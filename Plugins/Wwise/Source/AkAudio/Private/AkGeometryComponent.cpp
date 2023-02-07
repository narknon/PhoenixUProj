/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "AkGeometryComponent.h"
#include "AkAudioDevice.h"
#include "AkComponentHelpers.h"
#include "AkReverbDescriptor.h"
#include "AkAcousticTexture.h"
#include "AkRoomComponent.h"
#include "AkSettings.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Polys.h"
#include "Engine/StaticMesh.h"

#if PHYSICS_INTERFACE_PHYSX
#include "PhysXPublic.h"
#endif

#if WITH_CHAOS
#include "Chaos/Convex.h"
#include "Chaos/Particles.h"
#include "Chaos/Plane.h"
#include "Chaos/AABB.h"
#include "Chaos/CollisionConvexMesh.h"
#include "ChaosLog.h"
#endif

#include <AK/SpatialAudio/Common/AkSpatialAudio.h>

#if WITH_EDITOR
#include "Editor.h"
#endif

#include "UObject/Object.h"
#include "Engine/GameEngine.h"
#include "PhysicsEngine/BodySetup.h"

static const float kVertexNear = 0.0001;

UAkGeometryComponent::UAkGeometryComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	MeshType = AkMeshType::StaticMesh;
	LOD = 0;
	CollisionMeshSurfaceOverride.AcousticTexture = nullptr;
	CollisionMeshSurfaceOverride.bEnableOcclusionOverride = false;
	CollisionMeshSurfaceOverride.OcclusionValue = 1.f;
	WeldingThreshold = 0.001;

	bWasAddedByRoom = 0;
	bEnableDiffraction = 1;
	bEnableDiffractionOnBoundaryEdges = 0;
#if WITH_EDITOR
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;
#endif
}

void UAkGeometryComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	RemoveGeometry();
	StaticMeshSurfaceOverride.Empty();
#if WITH_EDITOR
	check(!OnMeshMaterialChangedHandle.IsValid());
#endif
}

void UAkGeometryComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	UpdateGeometry();
	if (ReverbDescriptor != nullptr)
	{
		DampingEstimationNeedsUpdate = true;
	}
}

bool UAkGeometryComponent::MoveComponentImpl(
	const FVector & Delta,
	const FQuat & NewRotation,
	bool bSweep,
	FHitResult * Hit,
	EMoveComponentFlags MoveFlags,
	ETeleportType Teleport)
{
	if (AkComponentHelpers::DoesMovementRecenterChild(this, Parent, Delta))
		Super::MoveComponentImpl(Delta, NewRotation, bSweep, Hit, MoveFlags, Teleport);

	return false;
}

void UAkGeometryComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!IsBeingDestroyed())
	{
#if WITH_EDITOR
		if (AkComponentHelpers::ShouldDeferBeginPlay(this))
			bRequiresDeferredBeginPlay = true;
		else
			BeginPlayInternal();
#else
		BeginPlayInternal();
#endif
	}
}

void UAkGeometryComponent::BeginPlayInternal()
{

	if (Parent == nullptr)
		InitializeParent();

	if (GeometryData.Vertices.Num() == 0)
		ConvertMesh();

	for (int PosIndex = 0; PosIndex < GeometryData.Surfaces.Num(); ++PosIndex)
	{
		// set geometry surface names and update textures
		GeometryData.Surfaces[PosIndex].Name = GetOwner()->GetName() + GetName() + FString::FromInt(PosIndex);

		UPhysicalMaterial* physMat = GeometryData.ToOverrideAcousticTexture[PosIndex];
		if (physMat)
		{
			UAkAcousticTexture* acousticTexture = nullptr;
			if (GetDefault<UAkSettings>()->GetAssociatedAcousticTexture(physMat, acousticTexture))
			{
				if (acousticTexture)
					GeometryData.Surfaces[PosIndex].Texture = FAkAudioDevice::GetIDFromString(acousticTexture->GetName());
			}
		}

		physMat = GeometryData.ToOverrideOcclusion[PosIndex];
		if (physMat)
		{
			float occlusionValue = 1.f;
			if (GetDefault<UAkSettings>()->GetAssociatedOcclusionValue(physMat, occlusionValue))
			{
				GeometryData.Surfaces[PosIndex].Occlusion = occlusionValue;
			}
		}
	}

	UpdateGeometry();
	RecalculateHFDamping();
}

void UAkGeometryComponent::OnRegister()
{
	Super::OnRegister();
	SetRelativeTransform(FTransform::Identity);
	InitializeParent();
#if WITH_EDITOR
	OnMeshMaterialChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddLambda([this](UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
		{
			if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UMeshComponent, OverrideMaterials) &&
				Parent != nullptr &&
				Parent == Object &&
				MeshType == AkMeshType::StaticMesh
				)
			{
				UpdateStaticMeshOverride();
			}
		});
	if (Parent != nullptr)
	{
		if (MeshType == AkMeshType::StaticMesh)
		{
			UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
			if (MeshParent != nullptr)
				CalculateSurfaceArea(MeshParent);
		}
		RecalculateHFDamping();
	}
#endif
}

void UAkGeometryComponent::OnUnregister()
{
#if WITH_EDITOR
	FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(OnMeshMaterialChangedHandle);
	OnMeshMaterialChangedHandle.Reset();
#endif
	Parent = nullptr;

	Super::OnUnregister();
}

void UAkGeometryComponent::InitializeParent()
{
	USceneComponent* SceneParent = GetAttachParent();
	if (SceneParent != nullptr)
	{
		Parent = Cast<UPrimitiveComponent>(SceneParent);
		if (!Parent)
		{
			FString actorString = FString("NONE");
			if (GetOwner() != nullptr)
				actorString = GetOwner()->GetName();
			FString parentName = SceneParent->GetName();
			FString parentClass = SceneParent->GetClass()->GetName();
			UE_LOG(LogAkAudio, Error,
				TEXT("On actor %s, there is a UAkGeometryComponent (%s) attached to parent of type %s (%s).")
				, *actorString, *GetName(), *parentClass, *parentName);
			if (MeshType == AkMeshType::StaticMesh)
			{
				UE_LOG(LogAkAudio, Error, TEXT("When MeshType is set to Static Mesh, UAkGeometryComponent requires to be nested under a component inheriting from UStaticMeshComponent."));
			}
			else
			{
				UE_LOG(LogAkAudio, Error, TEXT("When MeshType is set to Simple Collision, UAkGeometryComponent requires to be nested under a component inheriting from UPrimitiveComponent."));
			}
			return;
		}
		if (MeshType == AkMeshType::StaticMesh)
		{
			UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(SceneParent);
			if (MeshParent != nullptr)
			{
				bool fillMaterialKeys = true;
#if WITH_EDITOR
				// Fill the materials in the StaticMeshSurfaceOverride map only when there is no ongoing transaction (e.g. a user changing a property in the details panel).
				if (GetOwner() != nullptr && GetOwner()->CurrentTransactionAnnotation != nullptr)
				{
					fillMaterialKeys = false;
				}
#endif
				if (fillMaterialKeys)
				{
					UpdateMeshAndArchetype(MeshParent);
				}
			}
			else
			{
				FString actorString = FString("NONE");
				if (GetOwner() != nullptr)
					actorString = GetOwner()->GetName();
				FString parentName = SceneParent->GetName();
				FString parentClass = SceneParent->GetClass()->GetName();
				UE_LOG(LogAkAudio, Warning,
					TEXT("On actor %s, there is a UAkGeometryComponent (%s) attached to parent of type %s (%s).")
					, *actorString, *GetName(), *parentClass, *parentName);
				UE_LOG(LogAkAudio, Warning, TEXT("When MeshType is set to Static Mesh, UAkGeometryComponent requires to be nested under a component inheriting from UStaticMeshComponent. Reverting to Simple Collision."));
				MeshType = AkMeshType::CollisionMesh;

				// If we're in the Blueprint editor, update the Archetype object as well.
				UWorld* World = GetWorld();
				if (World != nullptr && World->WorldType == EWorldType::EditorPreview
					&& CreationMethod == EComponentCreationMethod::SimpleConstructionScript)
				{
					UAkGeometryComponent* Archetype = Cast<UAkGeometryComponent>(GetArchetype());
					if (Archetype != nullptr)
						Archetype->MeshType = AkMeshType::CollisionMesh;
				}
			}
		}
	}
}

void UAkGeometryComponent::CalculateSurfaceArea(UStaticMeshComponent* StaticMeshComponent)
{
	SurfaceAreas.Empty();

	UStaticMesh* mesh = StaticMeshComponent->GetStaticMesh();
#if UE_4_27_OR_LATER
	if (mesh == nullptr || !mesh->GetRenderData())
		return;
#else
	if (mesh == nullptr || !mesh->RenderData)
		return;
#endif

	const FStaticMeshLODResources& RenderMesh = mesh->GetLODForExport(LOD);
	FIndexArrayView RawIndices = RenderMesh.IndexBuffer.GetArrayView();

	if (RawIndices.Num() == 0)
		return;

	const int32 PolygonsCount = RenderMesh.Sections.Num();
	double SurfaceArea = 0.0;
	const auto WorldScale = StaticMeshComponent->GetOwner()->ActorToWorld().GetScale3D();
	for (int32 PolygonsIndex = 0; PolygonsIndex < PolygonsCount; ++PolygonsIndex)
	{
		const FStaticMeshSection& Polygons = RenderMesh.Sections[PolygonsIndex];

		const uint32 TriangleCount = Polygons.NumTriangles;
		for (uint32 TriangleIndex = 0; TriangleIndex < TriangleCount; ++TriangleIndex)
		{
			const uint32 RawVertIndex0 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 0)];
			const uint32 RawVertIndex1 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 1)];
			const uint32 RawVertIndex2 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 2)];

			// Scale to world space to ensure proper area
			auto ScaledP0 = WorldScale * FVector(RenderMesh.VertexBuffers.PositionVertexBuffer.VertexPosition(RawVertIndex0).GridSnap(WeldingThreshold));
			auto ScaledP1 = WorldScale * FVector(RenderMesh.VertexBuffers.PositionVertexBuffer.VertexPosition(RawVertIndex1).GridSnap(WeldingThreshold));
			auto ScaledP2 = WorldScale * FVector(RenderMesh.VertexBuffers.PositionVertexBuffer.VertexPosition(RawVertIndex2).GridSnap(WeldingThreshold));
			SurfaceArea += FAkReverbDescriptor::TriangleArea(ScaledP0, ScaledP1, ScaledP2);
		}
		SurfaceAreas.Add(PolygonsIndex, SurfaceArea);
	}
}

bool AddVertsForEdge(const FPositionVertexBuffer& Positions, TArray<int32>& UniqueVerts, int32 P0UnrealIdx, int32 P0UniqueIdx, int32 P1UnrealIdx, int32 P1UniqueIdx, TArray< TPair<int32, float> > & VertsOnEdge, float WeldingThreshold)
{
	auto p0 = Positions.VertexPosition(P0UnrealIdx).GridSnap(WeldingThreshold);
	auto p1 = Positions.VertexPosition(P1UnrealIdx).GridSnap(WeldingThreshold);

	FUnrealFloatVector Dir;
	float Length;
	(p1 - p0).ToDirectionAndLength(Dir, Length);

	if (Length <= FLT_MIN)
		return false;

	for (int32 i = 0; i < UniqueVerts.Num(); i++)
	{
		const int32 UnrealVertIdx = UniqueVerts[i];
		auto p = Positions.VertexPosition(UnrealVertIdx).GridSnap(WeldingThreshold);

		float Dot = FUnrealFloatVector::DotProduct(p - p0, Dir);
		const float RelLength = Dot / Length;
		if (RelLength > kVertexNear && RelLength < 1.f + kVertexNear)
		{
			FUnrealFloatVector PtOnLine = p0 + Dot * Dir;
			FUnrealFloatVector Diff = PtOnLine - p;
			const float RelDiff = Diff.GetAbsMax() / Length;
			if (RelDiff < kVertexNear)
			{
				VertsOnEdge.Emplace(i, Dot);
			}
		}
	}

	// VertsOnEdge should contain p1 but not p0
	check(VertsOnEdge.Num() > 0);

	VertsOnEdge.Sort([](const TPair<int32, float>& One, const TPair<int32, float>& Two)
	{
		return One.Value < Two.Value;
	});

	return true;
}

void DetermineVertsToWeld(TArray<int32>& VertRemap, TArray<int32>& UniqueVerts, const FStaticMeshLODResources& RenderMesh, float WeldingThreshold)
{
	const int32 VertexCount = RenderMesh.VertexBuffers.PositionVertexBuffer.GetNumVertices();

	// Maps unreal verts to reduced list of verts
	VertRemap.Empty(VertexCount);
	VertRemap.AddUninitialized(VertexCount);

	// List of Unreal Verts to keep
	UniqueVerts.Empty(VertexCount);

	// Combine matching verts using hashed search to maintain good performance
	TMap<FUnrealFloatVector, int32> HashedVerts;
	for (int32 a = 0; a < VertexCount; a++)
	{
		auto PositionA = RenderMesh.VertexBuffers.PositionVertexBuffer.VertexPosition(a).GridSnap(WeldingThreshold);
		const int32* FoundIndex = HashedVerts.Find(PositionA);
		if (!FoundIndex)
		{
			int32 NewIndex = UniqueVerts.Add(a);
			VertRemap[a] = NewIndex;
			HashedVerts.Add(PositionA, NewIndex);
		}
		else
		{
			VertRemap[a] = *FoundIndex;
		}
	}
}

void UAkGeometryComponent::ConvertMesh()
{
	if (!(Parent && Parent->IsValidLowLevel()))
		return;

	const UAkSettings* AkSettings = GetDefault<UAkSettings>();

	switch (MeshType)
	{
		case AkMeshType::StaticMesh:
		{
			UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
			if (MeshParent != nullptr)
				ConvertStaticMesh(MeshParent, AkSettings);
			break;
		}
		case AkMeshType::CollisionMesh:
		{
			ConvertCollisionMesh(Parent, AkSettings);
			break;
		}
	}
}

void UAkGeometryComponent::ConvertStaticMesh(UStaticMeshComponent* StaticMeshComponent, const UAkSettings* AkSettings)
{
	UStaticMesh* mesh = StaticMeshComponent->GetStaticMesh();
	if (!(mesh && mesh->IsValidLowLevel()))
		return;

	if (LOD > mesh->GetNumLODs() - 1)
		LOD = mesh->GetNumLODs() - 1;

#if UE_4_27_OR_LATER
	if (!mesh->GetRenderData())
		return;
#else
	if (!mesh->RenderData)
		return;
#endif

	const FStaticMeshLODResources& RenderMesh = mesh->GetLODForExport(LOD);
	FIndexArrayView RawIndices = RenderMesh.IndexBuffer.GetArrayView();

	if (RawIndices.Num() == 0)
		return;

	GeometryData.Clear();

	TArray<int32> VertRemap;
	TArray<int32> UniqueVerts;

	DetermineVertsToWeld(VertRemap, UniqueVerts, RenderMesh, WeldingThreshold);

	for (int PosIndex = 0; PosIndex < UniqueVerts.Num(); ++PosIndex)
	{
		const int32 UnrealPosIndex = UniqueVerts[PosIndex];
		auto VertexInActorSpace = RenderMesh.VertexBuffers.PositionVertexBuffer.VertexPosition(UnrealPosIndex);
		GeometryData.Vertices.Add(FVector(VertexInActorSpace));
	}

	UpdateMeshAndArchetype(StaticMeshComponent);
	CalculateSurfaceArea(StaticMeshComponent);

	const int32 PolygonsCount = RenderMesh.Sections.Num();
	for (int32 PolygonsIndex = 0; PolygonsIndex < PolygonsCount; ++PolygonsIndex)
	{
		const FStaticMeshSection& Polygons = RenderMesh.Sections[PolygonsIndex];

		FAkAcousticSurface Surface;
		UPhysicalMaterial* physMatTexture = nullptr;
		UPhysicalMaterial* physMatOcclusion = nullptr;
		FAkGeometrySurfaceOverride surfaceOverride;

		UMaterialInterface* Material = StaticMeshComponent->GetMaterial(Polygons.MaterialIndex);
		if (Material)
		{
			UPhysicalMaterial* physicalMaterial = Material->GetPhysicalMaterial();

			if (StaticMeshSurfaceOverride.Contains(Material))
				surfaceOverride = StaticMeshSurfaceOverride[Material];
			
			if (!surfaceOverride.AcousticTexture)
				physMatTexture = physicalMaterial;

			if (!surfaceOverride.bEnableOcclusionOverride)
				physMatOcclusion = physicalMaterial;
		}

		if (surfaceOverride.AcousticTexture)
			Surface.Texture = FAkAudioDevice::GetIDFromString(surfaceOverride.AcousticTexture->GetName());

		if (surfaceOverride.bEnableOcclusionOverride)
			Surface.Occlusion = surfaceOverride.OcclusionValue;

		GeometryData.Surfaces.Add(Surface);
		GeometryData.ToOverrideAcousticTexture.Add(physMatTexture);
		GeometryData.ToOverrideOcclusion.Add(physMatOcclusion);
		AkSurfIdx surfIdx = (AkSurfIdx)(GeometryData.Surfaces.Num() - 1);

		TArray< TPair<int32, float> > Edge0, Edge1, Edge2;
		const uint32 TriangleCount = Polygons.NumTriangles;
		for (uint32 TriangleIndex = 0; TriangleIndex < TriangleCount; ++TriangleIndex)
		{
			uint32 RawVertIndex0 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 0)];
			uint32 UniqueVertIndex0 = VertRemap[RawVertIndex0];

			uint32 RawVertIndex1 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 1)];
			uint32 UniqueVertIndex1 = VertRemap[RawVertIndex1];

			uint32 RawVertIndex2 = RawIndices[Polygons.FirstIndex + ((TriangleIndex * 3) + 2)];
			uint32 UniqueVertIndex2 = VertRemap[RawVertIndex2];

			Edge0.Empty(8);
			bool succeeded = AddVertsForEdge(RenderMesh.VertexBuffers.PositionVertexBuffer, UniqueVerts, RawVertIndex0, UniqueVertIndex0, RawVertIndex1, UniqueVertIndex1, Edge0, WeldingThreshold);
			if (!succeeded)
			{
				UE_LOG(LogAkAudio, Warning, TEXT("%s: UAkGeometryComponent::ConvertStaticMesh Vertex IDs %i and %i are too close resulting in a triangle with an area of 0. The triangle will be skipped."), *GetOwner()->GetName(), RawVertIndex0, RawVertIndex1);
				continue;
			}

			Edge1.Empty(8);
			succeeded = AddVertsForEdge(RenderMesh.VertexBuffers.PositionVertexBuffer, UniqueVerts, RawVertIndex1, UniqueVertIndex1, RawVertIndex2, UniqueVertIndex2, Edge1, WeldingThreshold);
			if (!succeeded)
			{
				UE_LOG(LogAkAudio, Warning, TEXT("%s: UAkGeometryComponent::ConvertStaticMesh Vertex IDs %i and %i are too close resulting in a triangle with an area of 0. The triangle will be skipped."), *GetOwner()->GetName(), RawVertIndex1, RawVertIndex2);
				continue;
			}

			Edge2.Empty(8);
			succeeded = AddVertsForEdge(RenderMesh.VertexBuffers.PositionVertexBuffer, UniqueVerts, RawVertIndex2, UniqueVertIndex2, RawVertIndex0, UniqueVertIndex0, Edge2, WeldingThreshold);
			if (!succeeded)
			{
				UE_LOG(LogAkAudio, Warning, TEXT("%s: UAkGeometryComponent::ConvertStaticMesh Vertex IDs %i and %i are too close resulting in a triangle with an area of 0. The triangle will be skipped."), *GetOwner()->GetName(), RawVertIndex2, RawVertIndex0);
				continue;
			}

			FAkTriangle triangle;
			triangle.Surface = surfIdx;

			bool bDone = false;
			do
			{
				int32 v0, v1, v2;

				if (Edge0.Num() > 1)
				{
					v1 = Edge0.Pop().Key;
					v0 = Edge0.Last().Key;
					v2 = Edge1[0].Key;
				}
				else if (Edge1.Num() > 1)
				{
					v1 = Edge1.Pop().Key;
					v0 = Edge1.Last().Key;
					v2 = Edge2[0].Key;
				}
				else if (Edge2.Num() > 1)
				{
					v1 = Edge2.Pop().Key;
					v0 = Edge2.Last().Key;
					v2 = Edge0[0].Key;
				}
				else
				{
					v0 = Edge0[0].Key;
					v1 = Edge1[0].Key;
					v2 = Edge2[0].Key;
					bDone = true;
				}

				triangle.Point0 = (AkVertIdx)v0;
				triangle.Point1 = (AkVertIdx)v1;
				triangle.Point2 = (AkVertIdx)v2;

				if (triangle.Point0 != triangle.Point1 &&
					triangle.Point1 != triangle.Point2 &&
					triangle.Point2 != triangle.Point0)
					GeometryData.Triangles.Add(triangle);
			} while (!bDone);

		}
		if (SurfaceAreas.Contains(PolygonsIndex))
			surfaceOverride.SetSurfaceArea(SurfaceAreas[PolygonsIndex]);
	}
}

struct VertexIndexByAngle
{
	AkVertIdx Index;
	float Angle;
}; 

#if PHYSICS_INTERFACE_PHYSX
void ConvertConvexMeshToGeometryData(AkSurfIdx surfIdx, UBodySetup* bodySetup, FAkGeometryData* GeometryData)
{
	int32 numComvexHulls = bodySetup->AggGeom.ConvexElems.Num();
	for (int32 i = 0; i < numComvexHulls; i++)
	{
		FKConvexElem& convexHull = bodySetup->AggGeom.ConvexElems[i];
		physx::PxConvexMesh* convexMesh = convexHull.GetConvexMesh();

		AkVertIdx initialVertIdx = GeometryData->Vertices.Num();
		if (convexMesh != nullptr)
		{
			const PxVec3* vertices = convexMesh->getVertices();

			uint32 numVerts = (uint32)convexMesh->getNbVertices();
			for (uint32 vertIdx = 0; vertIdx < numVerts; ++vertIdx)
			{
				FVector akvtx;
				akvtx.X = vertices[vertIdx].x;
				akvtx.Y = vertices[vertIdx].y;
				akvtx.Z = vertices[vertIdx].z;
				GeometryData->Vertices.Add(akvtx);
			}

			const physx::PxU8* indexBuf = convexMesh->getIndexBuffer();

			uint32 numPolys = (uint32)convexMesh->getNbPolygons();
			for (uint32 polyIdx = 0; polyIdx < numPolys; polyIdx++)
			{
				PxHullPolygon polyData;
				convexMesh->getPolygonData(polyIdx, polyData);

				// order the vertices of the polygon
				uint32 numVertsInPoly = (uint32)polyData.mNbVerts;
				uint32 vertIdxOffset = (uint32)polyData.mIndexBase;

				TArray<VertexIndexByAngle> orderedIndexes;
				// first element is first vertex index
				AkVertIdx firstVertIdx = (AkVertIdx)indexBuf[vertIdxOffset];
				orderedIndexes.Add(VertexIndexByAngle{ firstVertIdx, 0 });

				// get the center of the polygon
				FVector center(0, 0, 0);
				for (uint32 polyVertIdx = 0; polyVertIdx < numVertsInPoly; ++polyVertIdx)
				{
					auto vertIdx = indexBuf[vertIdxOffset + polyVertIdx];
					center.X += vertices[vertIdx].x;
					center.Y += vertices[vertIdx].y;
					center.Z += vertices[vertIdx].z;
				}
				center.X /= numVertsInPoly;
				center.Y /= numVertsInPoly;
				center.Z /= numVertsInPoly;

				// get the vector from center to the first vertex
				FVector v0;
				v0.X = vertices[firstVertIdx].x - center.X;
				v0.Y = vertices[firstVertIdx].y - center.Y;
				v0.Z = vertices[firstVertIdx].z - center.Z;
				v0.Normalize();

				// get the normal of the plane
				FVector n;
				n.X = polyData.mPlane[0];
				n.Y = polyData.mPlane[1];
				n.Z = polyData.mPlane[2];
				n.Normalize();

				// find the angles between v0 and the other vertices of the polygon
				for (uint32 polyVertIdx = 1; polyVertIdx < numVertsInPoly; polyVertIdx++)
				{
					// get the vector from center to the current vertex
					AkVertIdx vertIdx = (AkVertIdx)indexBuf[vertIdxOffset + polyVertIdx];
					FVector v1;
					v1.X = vertices[vertIdx].x - center.X;
					v1.Y = vertices[vertIdx].y - center.Y;
					v1.Z = vertices[vertIdx].z - center.Z;
					v1.Normalize();

					// get the angle between v0 and v1
					// to do so, we need the dot product and the determinant respectively proportional to cos and sin of the angle.
					// atan2(sin, cos) will give us the angle
					float dot = FVector::DotProduct(v0, v1);
					// the determinant of two 3D vectors in the same plane can be found with the dot product of the normal with the result of
					// a cross product between the vectors
					float det = FVector::DotProduct(n, FVector::CrossProduct(v0, v1));
					float angle = (float)atan2(det, dot);

					orderedIndexes.Add(VertexIndexByAngle{ vertIdx, angle });
				}

				orderedIndexes.Sort();

				// fan triangulation
				for (uint32 vertIdx = 1; vertIdx < numVertsInPoly - 1; ++vertIdx)
				{
					FAkTriangle tri;
					tri.Point0 = (AkVertIdx)orderedIndexes[0].Index + initialVertIdx;
					tri.Point1 = (AkVertIdx)orderedIndexes[vertIdx].Index + initialVertIdx;
					tri.Point2 = (AkVertIdx)orderedIndexes[vertIdx + 1].Index + initialVertIdx;
					tri.Surface = surfIdx;

					GeometryData->Triangles.Add(tri);
				}
			}
		}
		else
		{
			// bounding box
			GeometryData->AddBox(surfIdx,
				convexHull.ElemBox.GetCenter(),
				convexHull.ElemBox.GetExtent(),
				convexHull.GetTransform().Rotator());
		}
	}
}
#elif WITH_CHAOS
	void ConvertConvexMeshToGeometryData(AkSurfIdx surfIdx, UBodySetup* bodySetup, FAkGeometryData* GeometryData)
	{
		int32 numComvexHulls = bodySetup->AggGeom.ConvexElems.Num();
		for (int32 i = 0; i < numComvexHulls; i++)
		{
			FKConvexElem* convexHull = &bodySetup->AggGeom.ConvexElems[i];
			auto convexMesh = convexHull->GetChaosConvexMesh();

			AkVertIdx initialVertIdx = GeometryData->Vertices.Num();
			if (convexMesh.IsValid())
			{
				const auto& Vertices = convexMesh->GetVertices();

				TArray<TArray<int32>> FaceIndices;
				TArray<Chaos::TPlaneConcrete<Chaos::FRealSingle, 3>> Planes;
				TArray<Chaos::TVec3<Chaos::FRealSingle>> SurfaceVertices;
				Chaos::TAABB<Chaos::FRealSingle, 3> LocalBoundingBox;
				Chaos::FConvexBuilder::Build(Vertices, Planes, FaceIndices, SurfaceVertices, LocalBoundingBox);


				for (int32 vertexIdx = 0; vertexIdx < Vertices.Num(); ++vertexIdx)
				{
					FVector akvtx;
					akvtx.X = Vertices[vertexIdx].X;
					akvtx.Y = Vertices[vertexIdx].Y;
					akvtx.Z = Vertices[vertexIdx].Z;
					GeometryData->Vertices.Add(akvtx);
				}

				for (int32 faceIdx = 0; faceIdx < FaceIndices.Num(); faceIdx++)
				{
					auto face = FaceIndices[faceIdx];
					// order the vertices of the polygon
					uint32 numVertsInPoly = face.Num();

					TArray<VertexIndexByAngle> orderedIndexes;
					// first element is first vertex index
					AkVertIdx firstVertIdx = face[0];
					orderedIndexes.Add(VertexIndexByAngle{ firstVertIdx, 0 });

					// get the center of the polygon
					FVector center(0, 0, 0);
					for (uint32 polyVertIdx = 0; polyVertIdx < numVertsInPoly; ++polyVertIdx)
					{
						auto vertIdx = face[polyVertIdx];
						center.X = Vertices[vertIdx].X;
						center.Y = Vertices[vertIdx].Y;
						center.Z = Vertices[vertIdx].Z;
					}
					center.X /= numVertsInPoly;
					center.Y /= numVertsInPoly;
					center.Z /= numVertsInPoly;

					// get the vector from center to the first vertex
					FVector v0;
					v0.X = Vertices[firstVertIdx].X - center.X;
					v0.Y = Vertices[firstVertIdx].Y - center.Y;
					v0.Z = Vertices[firstVertIdx].Z - center.Z;
					v0.Normalize();

					// get the normal of the plane
					FVector n = FVector(Planes[faceIdx].Normal());
					n.Normalize();

					// find the angles between v0 and the other vertices of the polygon
					for (uint32 polyVertIdx = 1; polyVertIdx < numVertsInPoly; polyVertIdx++)
					{
						// get the vector from center to the current vertex
						AkVertIdx vertIdx = face[polyVertIdx];
						FVector v1;
						v1.X = Vertices[vertIdx].X - center.X;
						v1.Y = Vertices[vertIdx].Y - center.Y;
						v1.Z = Vertices[vertIdx].Z - center.Z;
						v1.Normalize();

						// get the angle between v0 and v1
						// to do so, we need the dot product and the determinant respectively proportional to cos and sin of the angle.
						// atan2(sin, cos) will give us the angle
						float dot = FVector::DotProduct(v0, v1);
						// the determinant of two 3D vectors in the same plane can be found with the dot product of the normal with the result of
						// a cross product between the vectors
						float det = FVector::DotProduct(n, FVector::CrossProduct(v0, v1));
						float angle = (float)atan2(det, dot);

						orderedIndexes.Add(VertexIndexByAngle{ vertIdx, angle });
					}

					orderedIndexes.Sort();

					// fan triangulation
					for (uint32 vertIdx = 1; vertIdx < numVertsInPoly - 1; ++vertIdx)
					{
						FAkTriangle tri;
						tri.Point0 = (AkVertIdx)orderedIndexes[0].Index + initialVertIdx;
						tri.Point1 = (AkVertIdx)orderedIndexes[vertIdx].Index + initialVertIdx;
						tri.Point2 = (AkVertIdx)orderedIndexes[vertIdx + 1].Index + initialVertIdx;
						tri.Surface = surfIdx;

						GeometryData->Triangles.Add(tri);
					}
				}
			}
			else
			{
				// bounding box
				GeometryData->AddBox(surfIdx,
					convexHull->ElemBox.GetCenter(),
					convexHull->ElemBox.GetExtent(),
					convexHull->GetTransform().Rotator());
			}
		}
	}
#else
#error "The Wwise Unreal integration is only compatible with PhysX or Chaos physics engines"
#endif

bool operator<(const VertexIndexByAngle& lhs, const VertexIndexByAngle& rhs)
{
	return lhs.Angle < rhs.Angle;
}

void UAkGeometryComponent::ConvertCollisionMesh(UPrimitiveComponent* PrimitiveComponent, const UAkSettings* AkSettings)
{
	UBodySetup* bodySetup = PrimitiveComponent->GetBodySetup();
	if (!(bodySetup && bodySetup->IsValidLowLevel()))
		return;

	GeometryData.Clear();

	FAkAcousticSurface Surface;
	UPhysicalMaterial* physicalMaterial = bodySetup->GetPhysMaterial();
	UPhysicalMaterial* physMatTexture = nullptr;
	UPhysicalMaterial* physMatOcclusion = nullptr;
	FAkGeometrySurfaceOverride surfaceOverride = CollisionMeshSurfaceOverride;

	if (surfaceOverride.AcousticTexture)
		Surface.Texture = FAkAudioDevice::GetIDFromString(surfaceOverride.AcousticTexture->GetName());
	else
		physMatTexture = physicalMaterial;

	if (surfaceOverride.bEnableOcclusionOverride)
		Surface.Occlusion = surfaceOverride.OcclusionValue;
	else
		physMatOcclusion = physicalMaterial;
	
	GeometryData.ToOverrideAcousticTexture.Add(physMatTexture);
	GeometryData.ToOverrideOcclusion.Add(physMatOcclusion);

	GeometryData.Surfaces.Add(Surface);
	
	AkSurfIdx surfIdx = (AkSurfIdx)(GeometryData.Surfaces.Num() - 1);

	int32 numBoxes = bodySetup->AggGeom.BoxElems.Num();
	for (int32 i = 0; i < numBoxes; i++)
	{
		FKBoxElem box = bodySetup->AggGeom.BoxElems[i];

		FVector extent;
		extent.X = box.X / 2;
		extent.Y = box.Y / 2;
		extent.Z = box.Z / 2;

		GeometryData.AddBox(surfIdx, box.Center, extent, box.Rotation);
	}

	const int sides = 16;

	int32 numSpheres = bodySetup->AggGeom.SphereElems.Num();
	for (int32 i = 0; i < numSpheres; i++)
	{
		FKSphereElem sphere = bodySetup->AggGeom.SphereElems[i];
		GeometryData.AddSphere(surfIdx, sphere.Center, sphere.Radius, sides, sides / 2);
	}

	int32 numCapsules = bodySetup->AggGeom.SphylElems.Num();
	for (int32 i = 0; i < numCapsules; i++)
	{
		FKSphylElem capsule = bodySetup->AggGeom.SphylElems[i];

		FVector X = capsule.GetTransform().GetUnitAxis(EAxis::X);
		FVector Y = capsule.GetTransform().GetUnitAxis(EAxis::Y);
		FVector Z = capsule.GetTransform().GetUnitAxis(EAxis::Z);

		GeometryData.AddCapsule(surfIdx, capsule.Center, X, Y, Z, capsule.Radius, capsule.Length / 2, sides / 2);
	}

	ConvertConvexMeshToGeometryData(surfIdx, bodySetup, &GeometryData);
}

void UAkGeometryComponent::SendGeometry()
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();

	if (AkAudioDevice && ShouldSendGeometry())
	{
		if (GeometryData.Triangles.Num() > 0 && GeometryData.Vertices.Num() > 0)
		{
			AkGeometryParams params;
			params.NumSurfaces = GeometryData.Surfaces.Num();
			params.NumTriangles = GeometryData.Triangles.Num();
			params.NumVertices = GeometryData.Vertices.Num();
			
			TUniquePtr<AkAcousticSurface[]> Surfaces; // temp surface buffer
			if (params.NumSurfaces) 
			{
				Surfaces = MakeUnique<AkAcousticSurface[]>(params.NumSurfaces);
				for (int i = 0; i < params.NumSurfaces; ++i)
				{
					Surfaces[i].transmissionLoss = GeometryData.Surfaces[i].Occlusion;
					Surfaces[i].strName = nullptr;
					if (!GeometryData.Surfaces[i].Name.IsEmpty())
					{
						Surfaces[i].strName = TCHAR_TO_ANSI(*GeometryData.Surfaces[i].Name);
					}
					Surfaces[i].textureID = GeometryData.Surfaces[i].Texture;
				}
			}
			params.Surfaces = Surfaces.Get();

			TUniquePtr<AkTriangle[]> Triangles = MakeUnique<AkTriangle[]>(params.NumTriangles);// temp triangle buffer
			for (int i = 0; i < params.NumTriangles; ++i)
			{
				Triangles[i].point0 = GeometryData.Triangles[i].Point0;
				Triangles[i].point1 = GeometryData.Triangles[i].Point1;
				Triangles[i].point2 = GeometryData.Triangles[i].Point2;
				Triangles[i].surface = GeometryData.Triangles[i].Surface;
			}
			params.Triangles = Triangles.Get();

			TUniquePtr<AkVertex[]> Vertices = MakeUnique<AkVertex[]>(params.NumVertices); // temp vertex buffer
			for (int i = 0; i < params.NumVertices; ++i)
			{
				Vertices[i].X = GeometryData.Vertices[i].X;
				Vertices[i].Y = GeometryData.Vertices[i].Y;
				Vertices[i].Z = GeometryData.Vertices[i].Z;
			}
			params.Vertices = Vertices.Get();
			
			params.EnableDiffraction = bEnableDiffraction;
			params.EnableDiffractionOnBoundaryEdges = bEnableDiffractionOnBoundaryEdges;
			params.EnableTriangles = !bWasAddedByRoom;

			if (AssociatedRoom)
			{
				UAkRoomComponent* room = Cast<UAkRoomComponent>(AssociatedRoom->GetComponentByClass(UAkRoomComponent::StaticClass()));

				if (room != nullptr)
					params.RoomID = room->GetRoomID();
			}

			SendGeometryToWwise(params);
		}
	}
}


void UAkGeometryComponent::RemoveGeometry()
{
	RemoveGeometryFromWwise();
}

void UAkGeometryComponent::UpdateGeometry()
{
	UpdateGeometryTransform();
	SendGeometry();
}

void UAkGeometryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	RemoveGeometry();
}

float UAkGeometryComponent::GetSurfaceAreaSquaredMeters(const int& surfaceIndex) const
{
	if (SurfaceAreas.Contains(surfaceIndex))
		return SurfaceAreas[surfaceIndex] / AkComponentHelpers::UnrealUnitsPerSquaredMeter(Parent);
	return 0.0f;
}

#if WITH_EDITOR
void UAkGeometryComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (AkComponentHelpers::IsGameWorldBlueprintComponent(this) || IsBeingDestroyed())
		return;
	if (AssociatedRoom && !Cast<UAkRoomComponent>(AssociatedRoom->GetComponentByClass(UAkRoomComponent::StaticClass())))
	{
		UE_LOG(LogAkAudio, Warning, TEXT("%s: The Surface Reflector Set's Associated Room is not of type UAkRoomComponent."), *GetOwner()->GetName());
	}

	const FName memberPropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;
	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, MeshType))
	{
		if (Parent != nullptr && MeshType == AkMeshType::StaticMesh)
		{
			UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
			if (MeshParent == nullptr)
			{
				FString actorString = FString("NONE");
				if (GetOwner() != nullptr)
					actorString = GetOwner()->GetName();
				FString parentName = Parent->GetName();
				FString parentClass = Parent->GetClass()->GetName();
				UE_LOG(LogAkAudio, Warning,
					TEXT("On actor %s, there is a UAkGeometryComponent (%s) attached to parent of type %s (%s).")
					, *actorString, *GetName(), *parentClass, *parentName);
				UE_LOG(LogAkAudio, Warning, TEXT("When MeshType is set to Static Mesh, UAkGeometryComponent requires to be nested under a component inheriting from UStaticMeshComponent. Reverting to Simple Collision."));
				MeshType = AkMeshType::CollisionMesh;
			}
			else
			{
				UpdateStaticMeshOverride();
			}
		}
		UnregisterTextureParamChangeCallbacks();
		RegisterAllTextureParamCallbacks();
	}
	else if ( (memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, StaticMeshSurfaceOverride) && MeshType == AkMeshType::StaticMesh)
		   || (memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, CollisionMeshSurfaceOverride) && MeshType == AkMeshType::CollisionMesh))
	{
		UnregisterTextureParamChangeCallbacks();
		RegisterAllTextureParamCallbacks();
		RecalculateHFDamping();
	}
	if (MeshType == AkMeshType::StaticMesh &&
		memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, WeldingThreshold) &&
		PropertyChangedEvent.ChangeType == EPropertyChangeType::ValueSet)
	{
		ConvertMesh();
		UpdateGeometry();
	}
	else if (memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, bEnableDiffraction) ||
			memberPropertyName == GET_MEMBER_NAME_CHECKED(UAkGeometryComponent, bEnableDiffractionOnBoundaryEdges))
	{
		UpdateGeometry();
	}
}

void UAkGeometryComponent::PostEditUndo()
{
	OnRefreshDetails.ExecuteIfBound();
	Super::PostEditUndo();
}

void UAkGeometryComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bRequiresDeferredBeginPlay)
	{
		BeginPlayInternal();
		bRequiresDeferredBeginPlay = false;
	}
	if (MeshType == AkMeshType::StaticMesh)
	{
		if (IsValid(Parent) && !Parent->IsBeingDestroyed())
		{
			UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
			if (MeshParent != nullptr && StaticMeshSurfaceOverride.Num() != MeshParent->GetNumMaterials())
				UpdateMeshAndArchetype(MeshParent);
		}
		if (bMeshMaterialChanged)
		{
			OnRefreshDetails.ExecuteIfBound();
			bMeshMaterialChanged = false;
		}
	}
}
#endif

void UAkGeometryComponent::UpdateStaticMeshOverride()
{
	UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
	if (MeshParent != nullptr)
	{
		UpdateMeshAndArchetype(MeshParent);	
	}
}

void UAkGeometryComponent::UpdateMeshAndArchetype(UStaticMeshComponent* StaticMeshComponent)
{
	_UpdateStaticMeshOverride(StaticMeshComponent);
	// If we're in the Blueprint editor, update the Archetype object as well.
	// (The archetype object is the object that's edited when properties are changed in the Blueprint editor details inspector.
	// This is a separate object from the objects shown in the Blueprint editor viewport.)
	UWorld* World = GetWorld();
	if (World != nullptr && World->WorldType == EWorldType::EditorPreview
		&& CreationMethod == EComponentCreationMethod::SimpleConstructionScript)
	{
		UAkGeometryComponent* Archetype = Cast<UAkGeometryComponent>(GetArchetype());
		if (Archetype != nullptr)
			Archetype->_UpdateStaticMeshOverride(StaticMeshComponent);
	}
}

void UAkGeometryComponent::_UpdateStaticMeshOverride(UStaticMeshComponent* StaticMeshComponent)
{
	auto ToRemove = StaticMeshSurfaceOverride;

	int numMaterials = StaticMeshComponent->GetNumMaterials();
	for (int i = 0; i < numMaterials; i++)
	{
		UMaterialInterface* material = StaticMeshComponent->GetMaterial(i);
		if (StaticMeshSurfaceOverride.Contains(material))
			ToRemove.Remove(material);
		else
		{
			FAkGeometrySurfaceOverride surfaceOverride;
			if (PreviousStaticMeshSurfaceOverride.Contains(material))
				surfaceOverride = PreviousStaticMeshSurfaceOverride[material];

			StaticMeshSurfaceOverride.Add(material, surfaceOverride);
		}
	}

#if WITH_EDITORONLY_DATA
	if (ToRemove.Num() > 0)
		bMeshMaterialChanged = true;
#endif
	for (auto& elemToRemove : ToRemove)
		StaticMeshSurfaceOverride.Remove(elemToRemove.Key);

	ToRemove.Empty();

	PreviousStaticMeshSurfaceOverride.Empty();
	PreviousStaticMeshSurfaceOverride = StaticMeshSurfaceOverride;
}

void UAkGeometryComponent::Serialize(FArchive& Ar)
{
#if WITH_EDITORONLY_DATA
	UWorld* World = GetWorld();
	if (Ar.IsSaving() && World != nullptr && !World->IsGameWorld())
		ConvertMesh();
#endif

	Super::Serialize(Ar);
}

void UAkGeometryComponent::GetTexturesAndSurfaceAreas(TArray<FAkAcousticTextureParams>& textures, TArray<float>& surfaceAreas)  const
{
	textures.Empty();
	surfaceAreas.Empty();
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (MeshType == AkMeshType::CollisionMesh)
		{
			if (CollisionMeshSurfaceOverride.AcousticTexture != nullptr)
			{
				const FAkAcousticTextureParams* params = AkSettings->GetTextureParams(CollisionMeshSurfaceOverride.AcousticTexture->ShortID);
				if (params != nullptr)
				{
					textures.Add(*params);
					surfaceAreas.Add(1.0f); // When there is only 1 acoustic texture, surface area magnitude is not important.
				}
			}
		}
		else
		{
			if (StaticMeshSurfaceOverride.Num() > 0)
			{
				int surfIdx = 0;
				float surfaceArea = 0.0f;
				for (auto it = StaticMeshSurfaceOverride.CreateConstIterator(); it; ++it)
				{
					surfaceArea = GetSurfaceAreaSquaredMeters(surfIdx);
					FAkGeometrySurfaceOverride surface = it.Value();
					surfaceAreas.Add(surfaceArea);
					if (surface.AcousticTexture != nullptr)
					{
						const FAkAcousticTextureParams* params = AkSettings->GetTextureParams(surface.AcousticTexture->ShortID);
						if (params != nullptr)
						{
							textures.Add(*params);
						}
					}
					else
					{
						textures.Add(FAkAcousticTextureParams());
					}
					++surfIdx;
				}
			}
		}
	}
}
void UAkGeometryComponent::UpdateGeometryTransform()
{
	FTransform ParentToWorld = FTransform::Identity;
	if (Parent != nullptr)
		ParentToWorld = Parent->GetComponentTransform();

	for (auto& vertex : GeometryData.Vertices)
	{
		vertex = ParentToWorld.TransformPosition(vertex);
	}
}


#if WITH_EDITOR
void UAkGeometryComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	Super::HandleObjectsReplaced(ReplacementMap);
	if (ReplacementMap.Contains(Parent))
	{
		InitializeParent();
		if (Parent != nullptr)
		{
			if (MeshType == AkMeshType::StaticMesh)
			{
				UStaticMeshComponent* MeshParent = Cast<UStaticMeshComponent>(Parent);
				if (MeshParent != nullptr)
					CalculateSurfaceArea(MeshParent);
			}
			RecalculateHFDamping();
		}
	}
}

bool UAkGeometryComponent::ContainsTexture(const FGuid& textureID)
{
	if (MeshType == AkMeshType::CollisionMesh)
	{
		if (CollisionMeshSurfaceOverride.AcousticTexture != nullptr)
			return CollisionMeshSurfaceOverride.AcousticTexture->ID == textureID;
	}
	else
	{
		for (auto it = StaticMeshSurfaceOverride.CreateIterator(); it; ++it)
		{
			if (it.Value().AcousticTexture != nullptr)
			{
				if (it.Value().AcousticTexture->ID == textureID)
					return true;
			}
		}
	}
	return false;
}

void UAkGeometryComponent::RegisterAllTextureParamCallbacks()
{
	if (MeshType == AkMeshType::CollisionMesh)
	{
		if (CollisionMeshSurfaceOverride.AcousticTexture != nullptr)
			RegisterTextureParamChangeCallback(CollisionMeshSurfaceOverride.AcousticTexture->ID);
	}
	else
	{
		for (auto it = StaticMeshSurfaceOverride.CreateIterator(); it; ++it)
		{
			if (it.Value().AcousticTexture != nullptr)
			{
				RegisterTextureParamChangeCallback(it.Value().AcousticTexture->ID);
			}
		}
	}
}
#endif
