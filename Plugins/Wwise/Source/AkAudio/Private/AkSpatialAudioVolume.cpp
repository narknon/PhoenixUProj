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


/*=============================================================================
	AkSpatialAudioVolume.cpp:
=============================================================================*/

#include "AkSpatialAudioVolume.h"
#include "AkSpatialAudioHelper.h"
#include "AkAudioDevice.h"
#include "AkLateReverbComponent.h"
#include "AkRoomComponent.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "Components/BrushComponent.h"
#include "Model.h"
#include "Engine/BrushBuilder.h"

#include "AkAcousticPortal.h"
#include "AkSettings.h"

// Geometric Tools
#if WITH_EDITOR
#include "AkAudioStyle.h"
#include <Mathematics/Math.h>
#include <Mathematics/UIntegerAP32.h>
#include <Mathematics/BSRational.h>
#include <Mathematics/MinimumVolumeBox3.h>
#endif

#include <algorithm>

static const float kScaleEpsilon = 0.001;
static const float kConvexHullEpsilon = 0.001;
static const FName NAME_SAV_Fit = TEXT("AkSpatialAudioVolumeRaycast");

#if WITH_EDITOR
bool IntersectPlanes(FVector n0, float d0, FVector n1, float d1, FVector n2, float d2, FVector &p)
{
	FVector u = FVector::CrossProduct(n1, n2);
	float denom = FVector::DotProduct(n0, u);
	if (std::abs(denom) < 0.1)
		return false; // Planes do not intersect in a point

	p = (d0*u + FVector::CrossProduct(n0, (d2 * n1) - (d1 * n2))) / denom;
	return true;
}

gte::Vector3< float > ToGTEVector(FVector& In)
{
	gte::Vector3< float > Out;
	Out[0] = In.X;
	Out[1] = In.Y;
	Out[2] = In.Z;
	return Out;
}

FVector ToFVector(gte::Vector3< float >& In)
{
	return FVector(In[0], In[1], In[2]);
}
#endif

/*------------------------------------------------------------------------------------
	AAkSpatialAudioVolume
------------------------------------------------------------------------------------*/

AAkSpatialAudioVolume::AAkSpatialAudioVolume(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	// Property initialization
	UBrushComponent* BrushComp = GetBrushComponent();
	if (BrushComp)
	{
		BrushComp->SetGenerateOverlapEvents(false);
		BrushComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		BrushComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
		BrushComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	}

	static const FName SurfReflSetName = TEXT("SurfaceReflector");
	SurfaceReflectorSet = ObjectInitializer.CreateDefaultSubobject<UAkSurfaceReflectorSetComponent>(this, SurfReflSetName);
	SurfaceReflectorSet->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	static const FName LateReverbame = TEXT("LateReverb");
	LateReverb = ObjectInitializer.CreateDefaultSubobject<UAkLateReverbComponent>(this, LateReverbame);
	LateReverb->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	static const FName RoomName = TEXT("Room");
	Room = ObjectInitializer.CreateDefaultSubobject<UAkRoomComponent>(this, RoomName);
	Room->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	bColored = true;
	BrushColor = FColor(109, 187, 255, 255);

#if WITH_EDITOR
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings)
	{
		CollisionChannel = AkSettings->DefaultFitToGeometryCollisionChannel;
	}
	else
	{
		CollisionChannel = ECollisionChannel::ECC_WorldStatic;
	}

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
#endif
}

#if WITH_EDITOR
void AAkSpatialAudioVolume::FitRaycast()
{
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(this);
	if (!World)
		return;

	TArray<FHitResult> hits;
	hits.Reserve(kNumRaycasts);

	const float kRayLength = 10000000.f;

	FCollisionQueryParams CollisionParams(NAME_SAV_Fit, true, this);
	CollisionParams.bReturnPhysicalMaterial = true;

	FVector RaycastOrigin = GetActorLocation();

	float Offset = 2.f / kNumRaycasts;
	float Increment = PI * (3.f - sqrtf(5.f));

	for (int i = 0; i < kNumRaycasts; ++i)
	{
		float y = ((i * Offset) - 1) + (Offset / 2);
		float r = sqrtf(1.f - powf(y, 2.f));

		float phi = ((i + 1) % kNumRaycasts) * Increment;

		float x = cosf(phi) * r;
		float z = sinf(phi) * r;

		FVector to = RaycastOrigin + FVector(x, y, z) * kRayLength;

		TArray< FHitResult > OutHits;
		OutHits.Empty();
		World->LineTraceMultiByObjectType(OutHits, RaycastOrigin, to, (int)CollisionChannel, CollisionParams);

		for (auto& res : OutHits)
		{
			AActor* HitActor = AkSpatialAudioHelper::GetActorFromHitResult(res);
			if (HitActor != nullptr)
			{
				UAkPortalComponent* PortalComponent = (UAkPortalComponent*)HitActor->FindComponentByClass(UAkPortalComponent::StaticClass());
				if (PortalComponent != nullptr)
				{
					// We hit a portal. The portals are a good reference point for the SAV, but we need to extend the ray to the center of the portal
					FVector PortalNorm = PortalComponent->GetComponentTransform().GetRotation().RotateVector(FVector(0.f, 1.f, 0.f));
					FVector PortalPos = PortalComponent->GetComponentLocation();
					float d = FVector::DotProduct(PortalPos, PortalNorm);
					FVector ab = to - res.ImpactPoint;
					float t = (d - FVector::DotProduct(PortalNorm, res.ImpactPoint)) / FVector::DotProduct(PortalNorm, ab);

					if (t >= 0.f && t < 1.0f)
					{
						FVector ImpactPointOnPoralPlane = res.ImpactPoint + t * ab;
						FHitResult ModifiedHitResult = res;
						ModifiedHitResult.ImpactPoint = ImpactPointOnPoralPlane;
						ModifiedHitResult.ImpactNormal = PortalNorm;
						if (FVector::DotProduct(PortalNorm, res.ImpactNormal) < 0.f)
							ModifiedHitResult.ImpactNormal = -PortalNorm;
						hits.Emplace(ModifiedHitResult);
						break;
					}
				}

				if (!res.bStartPenetrating &&
					HitActor->GetClass() == AAkSpatialAudioVolume::StaticClass())
				{
					hits.Emplace(res);
					break;
				}
			}

			if (res.IsValidBlockingHit() )
			{
				hits.Emplace(res);
				break;
			}
		}
	}

	auto SortPredicate = [](FHitResult& A, FHitResult& B){	return A.Distance < B.Distance; };

	Algo::Sort(hits, SortPredicate);

	FitPoints.Empty();
	FitPoints.Reserve(hits.Num());

	FitMaterials.Empty();
	FitMaterials.Reserve(hits.Num());

	FitNormals.Empty();
	FitNormals.Reserve(hits.Num());

	for (int i = 0; i < hits.Num(); ++i)
	{
		FitPoints.Emplace(hits[i].ImpactPoint);
		FitNormals.Emplace(hits[i].ImpactNormal);
		FitMaterials.Emplace(hits[i].PhysMaterial);
	}
}

void AAkSpatialAudioVolume::PostRebuildBrush()
{
	UnregisterAllComponents(true);
	RegisterAllComponents();

	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice != nullptr)
		AkAudioDevice->UpdateRoomsForPortals(GetWorld());

	if (SurfaceReflectorSet != nullptr)
	{
		SurfaceReflectorSet->UpdatePolys(true);
		SurfaceReflectorSet->UpdateSurfaceReflectorSet();
	}

	ClearTextComponents();
}

void AAkSpatialAudioVolume::ClearTextComponents()
{
	for (int i = 0; i < PreviewTextureNameComponents.Num(); ++i)
	{
		UTextRenderComponent* textComp = PreviewTextureNameComponents[i];
		if (textComp != nullptr)
		{
			textComp->DestroyComponent();
		}
	}
	PreviewTextureNameComponents.Empty();
}

void AAkSpatialAudioVolume::UpdatePreviewTextComponents(TArray<FVector> positions)
{
	ClearTextComponents();
	int index = 0;
	UMaterialInterface* mat = Cast<UMaterialInterface>(FAkAudioStyle::GetAkForegroundTextMaterial());
	ensure(positions.Num() == PreviewPolys.Num());
	for (FAkSurfacePoly& Poly : PreviewPolys)
	{
		FString VizName = GetName() + TEXT("PolyPreviewText ") + FString::FromInt(index);
		if (Poly.EnableSurface)
		{
			int32 idx = PreviewTextureNameComponents.Add(NewObject<UTextRenderComponent>(GetOuter(), *VizName));
			UTextRenderComponent* textComp = PreviewTextureNameComponents[idx];
			if (textComp != nullptr)
			{
				if (mat != nullptr)
					textComp->SetTextMaterial(mat);
				textComp->RegisterComponentWithWorld(GetWorld());
				textComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
				textComp->bIsEditorOnly = true;
				textComp->bSelectable = false;
				textComp->bAlwaysRenderAsText = true;
				textComp->SetHorizontalAlignment(EHTA_Center);
				textComp->SetVerticalAlignment(EVRTA_TextCenter);
				bool displayOcclusion = true;
				if (SurfaceReflectorSet != nullptr)
					displayOcclusion = SurfaceReflectorSet->bEnableSurfaceReflectors;
				textComp->SetText(Poly.GetPolyText(displayOcclusion));
				textComp->SetWorldLocation(positions[index]);
			}
		}
		else
		{
			PreviewTextureNameComponents.Add(nullptr);
		}
		++index;
	}
}

void AAkSpatialAudioVolume::UpdatePreviewPolys(TArray<TMap<TWeakObjectPtr<UPhysicalMaterial>, int>> materialVotes)
{
	PreviewPolys.Empty();
	PreviewPolys.AddDefaulted(materialVotes.Num());
	for (int i = 0; i < materialVotes.Num(); ++i)
	{
		PreviewPolys[i].EnableSurface = false;
		TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = materialVotes[i];
		// Tally the votes
		if (votes.Num() > 0)
		{
			auto MaxVotes = *votes.begin();
			auto it = votes.begin();
			++it;

			while (it != votes.end())
			{
				if (it->Value > MaxVotes.Value)
					MaxVotes = *it;

				++it;
			}
			// Use the material with the max number of points.
			if (MaxVotes.Key.IsValid())
			{
				GetDefault<UAkSettings>()->GetAssociatedAcousticTexture(MaxVotes.Key.Get(), PreviewPolys[i].Texture);
				GetDefault<UAkSettings>()->GetAssociatedOcclusionValue(MaxVotes.Key.Get(), PreviewPolys[i].Occlusion);
				PreviewPolys[i].EnableSurface = true;
			}
		}
	}
}

void AddOrIncrementMaterialVote(TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes, TWeakObjectPtr<UPhysicalMaterial>& material)
{
	int* Count = votes.Find(material);
	if (Count == nullptr)
	{
		Count = &votes.Add(material);
		*Count = 0;
	}
	if (Count != nullptr)
	{
		*Count += 1;
	};
}

void AAkSpatialAudioVolume::FitBox(bool bPreviewOnly)
{
	ClearTextComponents();
	LongestEdgeLength = 0.0f;

	if (FitPoints.Num() * FilterHitPoints == 0)
	{
		FitFailed = true;
		return;
	}

	static const float kExtent = 100.f;

	using MinimumVolumeBox3 = gte::MinimumVolumeBox3<float, ::gte::BSRational<::gte::UIntegerAP32>>;
	using OBB = gte::OrientedBox3 < float >;
	using Vector3 = gte::Vector3< float >;

	PreviewOutline.Empty();
	const float kNormalAgreement = 0.866f; // ~30 degrees
	if (Shape == EAkFitToGeometryMode::OrientedBox || 
		Shape == EAkFitToGeometryMode::AlignedBox )
	{
		FTransform XF = GetActorTransform();

		if (Shape == EAkFitToGeometryMode::OrientedBox) //allow rotation.
		{
			TArray<Vector3> Points;
			Points.Reserve(FitPoints.Num());

			for (int i = 0; i < FitPoints.Num() && i < FitPoints.Num()*FilterHitPoints; ++i)
			{
				Points.Emplace(ToGTEVector(FitPoints[i]));
			}

			MinimumVolumeBox3 mvb(std::min(8U, std::thread::hardware_concurrency()-1), true);
			OBB obb = mvb(Points.Num(), &Points[0], kConvexHullEpsilon);

			FVector Location(obb.center[0], obb.center[1], obb.center[2]);
			FVector Front(obb.axis[1][0], obb.axis[1][1], obb.axis[1][2]);
			FVector Top(obb.axis[2][0], obb.axis[2][1], obb.axis[2][2]);
			FQuat Rotation = FRotationMatrix::MakeFromYZ(Front, Top).ToQuat();
			FVector Scale(obb.extent[0], obb.extent[1], obb.extent[2]);

			if (Scale.X > ::kScaleEpsilon &&
				Scale.Y > ::kScaleEpsilon &&
				Scale.Z > ::kScaleEpsilon)
			{
				LongestEdgeLength = Scale.GetAbsMax();
				// Compensate for the standard AAkSpatialAudioVolume, based on a cube brush with verts at [+/-]100 X,Y,Z. 
				Scale /= kExtent;

				XF.SetLocation(Location);
				XF.SetRotation(Rotation);
				XF.SetScale3D(Scale);
			}

			TArray<FVector> textPositions = TArray<FVector>();
			textPositions.AddDefaulted(6); // Box face planes
			// The material votes for each plane.
			TArray<TMap<TWeakObjectPtr<UPhysicalMaterial>, int>> MaterialVotes;
			MaterialVotes.AddDefaulted(6);
			for (int boxAxis = 0; boxAxis < 3; ++boxAxis)
			{
				int faceIndex = boxAxis * 2;
				int oppositeFaceIndex = faceIndex + 1;
				FVector axis(obb.axis[boxAxis][0], obb.axis[boxAxis][1], obb.axis[boxAxis][2]);
				FVector faceCenter = Location + axis * obb.extent[boxAxis];
				FVector oppositeFaceCenter = Location - axis * obb.extent[boxAxis];
				textPositions[faceIndex] = faceCenter;
				textPositions[oppositeFaceIndex] = oppositeFaceCenter;
				for (int i = 0; i < FitPoints.Num() && i < FitPoints.Num() * FilterHitPoints; ++i)
				{
					// The sign on the axis is flipped in the comparisons because the normals face in towards the cuboid...
					if (FVector::DotProduct(FitNormals[i], -axis) >= kNormalAgreement && FMath::IsNearlyZero(FVector::DotProduct(FitPoints[i] - faceCenter, axis), 0.01f))
					{
						TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = MaterialVotes[faceIndex];
						AddOrIncrementMaterialVote(votes, FitMaterials[i]);
					}
					if (FVector::DotProduct(FitNormals[i], axis) >= kNormalAgreement && FMath::IsNearlyZero(FVector::DotProduct(FitPoints[i] - oppositeFaceCenter, -axis), 0.01f))
					{
						TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = MaterialVotes[oppositeFaceIndex];
						AddOrIncrementMaterialVote(votes, FitMaterials[i]);
					}
				}
			}
			if (bPreviewOnly)
			{
				UpdatePreviewPolys(MaterialVotes);
				UpdatePreviewTextComponents(textPositions);
			}
		}
		else if (Shape == EAkFitToGeometryMode::AlignedBox)
		{
			USceneComponent* RC = GetRootComponent();
			if (RC)
			{
				FRotator Rotation = RC->GetComponentRotation();
				FVector Min(FLT_MAX, FLT_MAX, FLT_MAX);
				FVector Max(-FLT_MAX, -FLT_MAX, -FLT_MAX);

				for (int i = 0; i < FitPoints.Num() && i < FitPoints.Num()*FilterHitPoints; ++i)
				{
					FVector PtWorld(FitPoints[i][0], FitPoints[i][1], FitPoints[i][2]);
					FVector PtLocal = Rotation.UnrotateVector(PtWorld);
					Min = Min.ComponentMin(PtLocal);
					Max = Max.ComponentMax(PtLocal);
				}

				FVector Scale = Max - Min;
				if (Scale.X > ::kScaleEpsilon &&
					Scale.Y > ::kScaleEpsilon &&
					Scale.Z > ::kScaleEpsilon)
				{
					LongestEdgeLength = Scale.GetAbsMax();
 					FVector Location = Rotation.RotateVector((Min + Max) / 2.f);
					XF.SetLocation(Location);
					XF.SetScale3D(Scale / (2.f*kExtent));
				}

				FVector centre(XF.GetLocation());
				FVector extent(Scale / 2.0f);
				TArray<FVector> textPositions = // Box face planes
				{
					centre + FVector(extent.X, 0.0f, 0.0f), centre - FVector(extent.X, 0.0f, 0.0f), 
					centre + FVector(0.0f, extent.Y, 0.0f), centre - FVector(0.0f, extent.Y, 0.0f),
					centre + FVector(0.0f, 0.0f, extent.Z), centre - FVector(0.0f, 0.0f, extent.Z)
				};
				TArray<FVector> faceNormals =
				{
					FVector(1, 0, 0), FVector(-1, 0, 0), FVector(0, 1, 0), FVector(0, -1, 0), FVector(0, 0, 1), FVector(0, 0, -1)
				};
				// The material votes for each plane.
				TArray<TMap<TWeakObjectPtr<UPhysicalMaterial>, int>> materialVotes;
				materialVotes.AddDefaulted(6);
				for (int axisIndex = 0; axisIndex < textPositions.Num(); ++axisIndex)
				{
					for (int i = 0; i < FitPoints.Num() && i < FitPoints.Num() * FilterHitPoints; ++i)
					{
						if (FVector::DotProduct(-FitNormals[i], faceNormals[axisIndex]) >= kNormalAgreement && FMath::IsNearlyZero(FVector::DotProduct(FitPoints[i] - textPositions[axisIndex], faceNormals[axisIndex]), 0.01f))
						{
							TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = materialVotes[axisIndex];
							AddOrIncrementMaterialVote(votes, FitMaterials[i]);
						}
					}
				}
				if (bPreviewOnly)
				{
					UpdatePreviewPolys(materialVotes);
					UpdatePreviewTextComponents(textPositions);
				}
			}
		}

		if (!bPreviewOnly && BrushBuilder)
		{
			BrushBuilder->BeginBrush(true, this->GetFName());

			const FTransform& ActorTransform = GetActorTransform();

			for (int32 i = -1; i < 2; i += 2)
				for (int32 j = -1; j < 2; j += 2)
					for (int32 k = -1; k < 2; k += 2)
						BrushBuilder->Vertexv(ActorTransform.InverseTransformPosition( XF.TransformPosition(FVector(i*kExtent, j*kExtent, k*kExtent)) ));

			BrushBuilder->Poly4i(+1, 0, 1, 3, 2);
			BrushBuilder->Poly4i(+1, 2, 3, 7, 6);
			BrushBuilder->Poly4i(+1, 6, 7, 5, 4);
			BrushBuilder->Poly4i(+1, 4, 5, 1, 0);
			BrushBuilder->Poly4i(+1, 3, 1, 5, 7);
			BrushBuilder->Poly4i(+1, 0, 2, 6, 4);

			BrushBuilder->EndBrush(GetWorld(), this);

			SetNeedRebuild(GetLevel());
			GEditor->RebuildAlteredBSP();
			
			PostRebuildBrush();
		}

		
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(+kExtent, +kExtent, -kExtent)), XF.TransformPosition(FVector(+kExtent, +kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(+kExtent, -kExtent, -kExtent)), XF.TransformPosition(FVector(+kExtent, -kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, +kExtent, -kExtent)), XF.TransformPosition(FVector(-kExtent, +kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, -kExtent, -kExtent)), XF.TransformPosition(FVector(-kExtent, -kExtent, +kExtent))));

		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, -kExtent, -kExtent)), XF.TransformPosition(FVector(-kExtent, +kExtent, -kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(+kExtent, -kExtent, -kExtent)), XF.TransformPosition(FVector(+kExtent, +kExtent, -kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, -kExtent, -kExtent)), XF.TransformPosition(FVector(+kExtent, -kExtent, -kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, +kExtent, -kExtent)), XF.TransformPosition(FVector(+kExtent, +kExtent, -kExtent))));

		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, -kExtent, +kExtent)), XF.TransformPosition(FVector(-kExtent, +kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(+kExtent, -kExtent, +kExtent)), XF.TransformPosition(FVector(+kExtent, +kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, -kExtent, +kExtent)), XF.TransformPosition(FVector(+kExtent, -kExtent, +kExtent))));
		PreviewOutline.Emplace(TPair<FVector, FVector>(XF.TransformPosition(FVector(-kExtent, +kExtent, +kExtent)), XF.TransformPosition(FVector(+kExtent, +kExtent, +kExtent))));

	}
	else if (Shape == EAkFitToGeometryMode::ConvexPolyhedron)
	{
		static const int kMaxAllowedPointsBehindPlane = 1; // Allows for some leniency - we cant expect geometry to be completely convex.
		static const float kDotEpsilon = 0.1f;	// To determine if points are infront/behind a given plane.
		static const float kDotThreshold = 0.866f; //~ 30 degrees, enough for a polygonal cross section with 12 sides. Used for comparing normals.

		using ConvexHull3 = ::gte::ConvexHull3<float, ::gte::BSRational<::gte::UIntegerAP32>>;
		using ETManifoldMesh = ::gte::ETManifoldMesh;

		FVector Origin = GetActorLocation();

		TArray<Vector3> Points;
		Points.Reserve(FitPoints.Num());

		TArray<FVector> Normals;
		// The material votes for each plane.
		TArray<TMap<TWeakObjectPtr<UPhysicalMaterial>, int>> MaterialVotes;
		TArray<float> Ds;

		for (int i = 0; i < FitPoints.Num()*FilterHitPoints; ++i)
		{
			// If the room is convex, every other point should be in front of the plane defined by the hit point and normal.
			int PointsBehindPlane = 0;
			for (int j = 0; j < FitPoints.Num()*FilterHitPoints; ++j)
			{
				if (i != j)
				{
					FVector ToPt = FitPoints[j] - FitPoints[i];
					ToPt.Normalize();
					float Proj = FVector::DotProduct(ToPt, FitNormals[i]);
					if (Proj < -kDotEpsilon)
						PointsBehindPlane++;
				}

			}

			// But in practice we will allow 1 point to be behind.
			if (PointsBehindPlane <= kMaxAllowedPointsBehindPlane)
			{
				// Calculate a representative plane for this point to be used in the convex hull algorithm.
				float d = FVector::DotProduct(Origin - FitPoints[i], FitNormals[i]);
				FVector HullPoint = Origin - FitNormals[i] * d;
				FVector& Normal = FitNormals[i];
				TWeakObjectPtr<UPhysicalMaterial>& Material = FitMaterials[i];
				bool Found = false;

				for (int n = 0; n < Normals.Num(); ++n)
				{
					// Check to see if a plane with the same normal has already been found. 
					if (FVector::DotProduct(Normals[n], Normal) > kDotThreshold)
					{
						// If so, take the one with the largest d value.
						Found = true;
						if (Ds[n] < d)
						{
							Normals[n] = Normal;
							Ds[n] = d;
							Points[n] = ToGTEVector(HullPoint);
						}
						TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = MaterialVotes[n];
						AddOrIncrementMaterialVote(votes, Material);
					}
				}

				if (!Found)
				{
					MaterialVotes.Add(TMap<TWeakObjectPtr<UPhysicalMaterial>, int>());
					TMap<TWeakObjectPtr<UPhysicalMaterial>, int>& votes = MaterialVotes.Last();
					AddOrIncrementMaterialVote(votes, Material);
					Normals.Add(Normal);
					Ds.Add(d);
					Points.Emplace(ToGTEVector(HullPoint));
				}
			}
		}

		if (Points.Num() < 4)
		{
			FitFailed = true;
			return;
		}

		// Build a convex hull with the planes found from the raycasts.
		ConvexHull3 ConvexHull;
		if (ConvexHull(Points.Num(), &Points[0], kConvexHullEpsilon))
		{
			ETManifoldMesh RoughMesh = ConvexHull.GetHullMesh();

			//At this point the polyhedron mesh is missing 'corners'. Iterate through the triangles, checking the normals of the vertices.
			TArray<Vector3> MeshPoints;
			MeshPoints.Reserve(FitPoints.Num());

			ETManifoldMesh::TMap RoughTriangles = RoughMesh.GetTriangles();
			for (auto& Triangle : RoughTriangles)
			{
				auto& Indexes = Triangle.second->V;

				FVector& n0 = Normals[Indexes[0]];
				FVector& n1 = Normals[Indexes[1]];
				FVector& n2 = Normals[Indexes[2]];

				FVector p0 = ToFVector(Points[Indexes[0]]);
				FVector p1 = ToFVector(Points[Indexes[1]]);
				FVector p2 = ToFVector(Points[Indexes[2]]);

				float d0 = FVector::DotProduct(p0, n0);
				float d1 = FVector::DotProduct(p1, n1);
				float d2 = FVector::DotProduct(p2, n2);

				FVector CornerPoint;
				if (IntersectPlanes(n0, d0, n1, d1, n2, d2, CornerPoint))
				{
					// Punch out the corner
					MeshPoints.Emplace(ToGTEVector(CornerPoint));
				}
				else
				{
					FitFailed = true;
					return;
				}
			}

			// Now generate a convex hull with the new corner points.
			ConvexHull3 ConvexPolyhedron;
			if (ConvexPolyhedron(MeshPoints.Num(), &MeshPoints[0], kConvexHullEpsilon))
			{
				ETManifoldMesh Mesh = ConvexPolyhedron.GetHullMesh();

				// Build a new brush with the polyhedron mesh.
				if (!bPreviewOnly &&
					BrushBuilder)
				{
					BrushBuilder->BeginBrush(true, this->GetFName());

					FVector Location = GetActorLocation();

					for (int p = 0; p < ConvexPolyhedron.GetNumPoints(); ++p)
					{
						const Vector3& Vert = ConvexPolyhedron.GetPoints()[p];
						BrushBuilder->Vertex3f(	Vert[0] - Location.X,
												Vert[1] - Location.Y,
												Vert[2] - Location.Z);
					}


					ETManifoldMesh::TMap Triangles = Mesh.GetTriangles();

					for (auto& Triangle : Triangles)
					{
						auto& Indexes = Triangle.second->V;
						BrushBuilder->Poly3i(+1, Indexes[0], Indexes[1], Indexes[2]);
					}

					BrushBuilder->EndBrush(GetWorld(), this);

					auto* RC = GetRootComponent();
					if (RC)
					{
						RC->SetWorldRotation(FQuat::Identity);
						RC->SetWorldScale3D(FVector::OneVector);
					}

					SetNeedRebuild(GetLevel());
					GEditor->RebuildAlteredBSP();
					
					PostRebuildBrush();
				}

				// Add the edges to the preview outline - skipping the edges that are 'flat'.
				ETManifoldMesh::EMap Edges = Mesh.GetEdges();
				for (auto& E : Edges)
				{
					auto& Edge = *E.second;
					auto T0 = Edge.T[0].lock();
					auto T1 = Edge.T[1].lock();
					if (T0 != nullptr && T1 != nullptr)
					{
						FVector N0 = FVector::CrossProduct(ToFVector(MeshPoints[T0->V[1]]) - ToFVector(MeshPoints[T0->V[0]]), ToFVector(MeshPoints[T0->V[2]]) - ToFVector(MeshPoints[T0->V[0]]));
						FVector N1 = FVector::CrossProduct(ToFVector(MeshPoints[T1->V[1]]) - ToFVector(MeshPoints[T1->V[0]]), ToFVector(MeshPoints[T1->V[2]]) - ToFVector(MeshPoints[T1->V[0]]));
						N0.Normalize();
						N1.Normalize();
						if (FVector::DotProduct(N0, N1) < kDotThreshold)
						{
							PreviewOutline.Add(TPair<FVector, FVector>(ToFVector(MeshPoints[Edge.V[0]]), ToFVector(MeshPoints[Edge.V[1]])));
							float edgeLength = (PreviewOutline.Last().Value - PreviewOutline.Last().Key).Size();
							if (edgeLength > LongestEdgeLength)
								LongestEdgeLength = edgeLength;
						}
					}
				}
			}
		}

		if (bPreviewOnly)
		{
			UpdatePreviewPolys(MaterialVotes);
			TArray<FVector> textPositions = TArray<FVector>();
			textPositions.AddDefaulted(Points.Num());
			for (int posIndex = 0; posIndex < Points.Num(); ++posIndex)
			{
				textPositions[posIndex] = ToFVector(Points[posIndex]);
			}
			UpdatePreviewTextComponents(textPositions);
		}
	}
	else
	{
		check(false);
	}

	// Map physics materials to surfaces.
	if ((!bPreviewOnly) && SurfaceReflectorSet)
	{
		SurfaceReflectorSet->AssignAcousticTexturesFromSamples(FitPoints, FitNormals, FitMaterials, std::min(FitPoints.Num(), (int32)(FitPoints.Num()*FilterHitPoints)));
	}

	FitFailed = false;
}

bool AAkSpatialAudioVolume::ShouldTickIfViewportsOnly() const
{
	return bBrushNeedsRebuild || ((GetBounds() != PreviousBounds) && PreviousBounds.SphereRadius != 0.0f);
}

void AAkSpatialAudioVolume::Tick(float DeltaSeconds)
{
	if (ShouldTickIfViewportsOnly())
	{
		SetNeedRebuild(GetLevel());
		GEditor->RebuildAlteredBSP();
		PostRebuildBrush();
		PreviousBounds = GetBounds();
		bBrushNeedsRebuild = false;
	}
}

void AAkSpatialAudioVolume::PostTransacted(const FTransactionObjectEvent& TransactionEvent)
{
	Super::PostTransacted(TransactionEvent);
	const TArray<FName>& ChangedProperties = TransactionEvent.GetChangedProperties();
	if (TransactionEvent.GetEventType() == ETransactionObjectEventType::UndoRedo && ChangedProperties.Contains(FName("FitToGeometry")))
	{
		bBrushNeedsRebuild = true;
	}
}

void AAkSpatialAudioVolume::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);

	IsDragging = !bFinished;

	if (FitToGeometry)
	{
		FitRaycast();

		if (bFinished && Shape == EAkFitToGeometryMode::AlignedBox)
		{
			USceneComponent* RC = GetRootComponent();
			if (RC)
				SavedRotation = RC->GetComponentRotation();
		}

		FitBox(!bFinished);
	}
}

void AAkSpatialAudioVolume::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	IsDragging = PropertyChangedEvent.ChangeType == EPropertyChangeType::Interactive;

	if (PropertyChangedEvent.Property)
	{
		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AAkSpatialAudioVolume, FitToGeometry))
		{
			if (FitToGeometry)
			{
				FitRaycast();
				FitBox();
			}
			else
			{
				FitPoints.Empty();
			}
		}
		
		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AAkSpatialAudioVolume, FilterHitPoints))
		{
			if (FitToGeometry) // only fit box continuously on value set for performance reasons.
			{
				FitBox(PropertyChangedEvent.ChangeType != EPropertyChangeType::ValueSet);
			}
		}

		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AAkSpatialAudioVolume, Shape))
		{
			USceneComponent* RC = GetRootComponent();
			if (RC)
			{
				if (Shape != EAkFitToGeometryMode::AlignedBox)
				{
					// We just disabled 'ConstrainRotation'. Save the old rotation.
					SavedRotation = RC->GetComponentRotation();
				}
				else
				{
					// We just enabled 'ConstrainRotation'. Restore the old rotation.
					RC->SetWorldRotation(SavedRotation);
				}
			}

			FitBox();
		}

		if (PropertyChangedEvent.MemberProperty->GetFName() == FName(FString("RelativeLocation"))
			|| PropertyChangedEvent.MemberProperty->GetFName() == FName(FString("RelativeRotation"))
			|| PropertyChangedEvent.MemberProperty->GetFName() == FName(FString("RelativeScale3D")))
		{
			if (SurfaceReflectorSet != nullptr)
				SurfaceReflectorSet->SkipNextTexturesUpdate();
		}
	}
}

#endif // WITH_EDITOR