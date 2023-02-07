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

#include "AkSurfaceReflectorSetComponent.h"
#include "AkSpatialAudioVolume.h"
#include "AkAudioDevice.h"
#include "AkRoomComponent.h"
#include "AkReverbDescriptor.h"
#include "AkComponentHelpers.h"
#include "Components/BrushComponent.h"

#include "Model.h"
#include "EditorSupportDelegates.h"
#include "Engine/Polys.h"

#include "GameFramework/Volume.h"
#include "AkSettings.h"
#include "EngineUtils.h"
#include <AK/SpatialAudio/Common/AkSpatialAudio.h>

#if WITH_EDITOR
#include "CameraController.h"
#include "Editor.h"
#include "AkAudioStyle.h"
#include "EditorModeTools.h"
#include "EditorModeManager.h"
#include "EditorModes.h"
#include "Kismet/KismetMathLibrary.h"
#include "LevelEditorViewport.h"

#if UE_4_25_OR_LATER
#include "EditorGeometry.h"
#include "GeometryEdMode.h"
#else
#include "Editor/GeometryMode/Public/EditorGeometry.h"
#include "Editor/GeometryMode/Public/GeometryEdMode.h"
#endif

#endif

#include "UObject/Object.h"
#include "Engine/GameEngine.h"


#if WITH_EDITOR

struct FFacePlane
{
	FFacePlane(FVector InOrigin, FVector InUp, FVector InRight)
		: Origin(InOrigin)
		, Up(InUp)
		, Right(InRight)
	{}

	/* Transform a point in world space to coordinates on the plane. */
	FVector2D WorldToPlaneCoordinates(FVector WorldPoint) const
	{
		float X = FVector::DotProduct((WorldPoint - Origin), Right);
		float Y = FVector::DotProduct((WorldPoint - Origin), Up);
		return FVector2D(X, Y);
	}

	/* Transform an edge in world space to an edge defined by plane coordinates. */
	void WorldToPlaneEdge(FVector WorldStart, FVector WorldEnd, FVector2D& PlaneStart, FVector2D& PlaneEnd, float ExtendAmount = 0.0f) const
	{
		PlaneStart = WorldToPlaneCoordinates(WorldStart);
		PlaneEnd = WorldToPlaneCoordinates(WorldEnd);
		if (ExtendAmount > 0.0f)
		{
			PlaneStart += (PlaneStart - PlaneEnd).GetSafeNormal() * ExtendAmount;
			PlaneEnd += (PlaneEnd - PlaneStart).GetSafeNormal() * ExtendAmount;
		}
	}

	FVector Origin = FVector::ZeroVector;
	FVector Up = FVector::UpVector;
	FVector Right = FVector::RightVector;
};

namespace TextAlignmentHelpers
{
	/* Get the four edges of the text render component in world space. */
	TArray<FAkSurfaceEdgeInfo> GetTextEdges(const UTextRenderComponent& TextComp, const FVector& TextBottomLeft, const FFacePlane& FacePlane, const float scale)
	{
		TArray<FAkSurfaceEdgeInfo> Edges;
		FVector LocalTextSize = TextComp.GetTextLocalSize();
		const float TextSizeVer = LocalTextSize.Z * scale;
		const float TextSizeHor = LocalTextSize.Y * scale;
		const FVector BottomRight = TextBottomLeft + TextSizeHor * FacePlane.Right;
		const FVector TopLeft = TextBottomLeft + TextSizeVer * FacePlane.Up;
		const FVector TopRight = TopLeft + TextSizeHor * FacePlane.Right;
		Edges.Add(FAkSurfaceEdgeInfo(TextBottomLeft, BottomRight));
		Edges.Add(FAkSurfaceEdgeInfo(TopLeft, TopRight));
		Edges.Add(FAkSurfaceEdgeInfo(TextBottomLeft, TopLeft));
		Edges.Add(FAkSurfaceEdgeInfo(BottomRight, TopRight));
		return Edges;
	}

	FVector From2D(const FVector2D& Vec2D)
	{
		return FVector(Vec2D.X, Vec2D.Y, 0.0f);
	}

	/* Query where BrushEdge bisects TextEdge. BisectionRatio indicates the length ratio at which TextEdge is intersected by BrushEdge.
		This is used to determine the scaling factor for the text visualizers on each face. */
	void GetTextEdgeBisection(const FAkSurfaceEdgeInfo& TextEdge, const FAkSurfaceEdgeInfo& BrushEdge, const FFacePlane& Plane, float& BisectionRatio)
	{
		BisectionRatio = 0.0f;
		const float Tolerance = 0.1f;
		FVector2D TextEdgeStart2D, TextEdgeEnd2D, BrushEdgeStart2D, BrushEdgeEnd2D;
		Plane.WorldToPlaneEdge(TextEdge.V0(), TextEdge.V1(), TextEdgeStart2D, TextEdgeEnd2D);
		Plane.WorldToPlaneEdge(BrushEdge.V0(), BrushEdge.V1(), BrushEdgeStart2D, BrushEdgeEnd2D, 2.0f);
		FVector Intersection = FVector::ZeroVector;
		// If TextEdge and BrushEdge are almost parallel, record no intersection.
		if (FMath::Abs((FVector2D::DotProduct((BrushEdgeEnd2D - BrushEdgeStart2D).GetSafeNormal(), (TextEdgeEnd2D - TextEdgeStart2D).GetSafeNormal()))) >= 0.95f)
			return;

		if (FMath::SegmentIntersection2D(From2D(TextEdgeStart2D), From2D(TextEdgeEnd2D), From2D(BrushEdgeStart2D), From2D(BrushEdgeEnd2D), Intersection))
		{
			// Ignore intersection with the first vertex of TextEdge
			if (Intersection.Equals(From2D(TextEdgeStart2D), Tolerance))
				return;

			BisectionRatio = (Intersection - From2D(TextEdgeStart2D)).Size() / (TextEdgeEnd2D - TextEdgeStart2D).Size();
		}
	}

	/* Use Tangent and Normal to determine the up vector. Uses the viewport client orientation to align up with camera. */
	FVector DetermineUpVector(const FVector& Tangent, FVector& Normal, const FVector& CamToCentre)
	{
		if (GCurrentLevelEditingViewportClient != nullptr)
		{
			if (FVector::DotProduct(CamToCentre, Normal) < 0.0f)
			{
				Normal *= -1.0f;
			}
		}

		FVector Up = -FVector::CrossProduct(Tangent, Normal);
		Up.Normalize();

		if (GCurrentLevelEditingViewportClient != nullptr)
		{
			FVector CamUp = UKismetMathLibrary::GetUpVector(GCurrentLevelEditingViewportClient->GetViewRotation());
			if (FVector::DotProduct(Up, CamUp) < 0.0f)
			{
				Up *= -1.0f;
			}
		}

		return Up;
	}

	/* Set the text alignment for TextComp according to where the AlginmentEdge is in relation to the MidPoint. */
	void SetTextAlignment(UTextRenderComponent* TextComp, const FAkSurfaceEdgeInfo& AlignmentEdge, const FVector& MidPoint)
	{
		TextComp->SetHorizontalAlignment(EHTA_Left);
		TextComp->SetVerticalAlignment(EVRTA_TextBottom);
		const FVector& AnchorVertex = AlignmentEdge.V0();
		// 'Probe' slightly up and right of the AnchorVertex to determine how the text should be aligned vertically and horizontally.
		FVector TextWorldUp = TextComp->GetUpVector();
		FVector Probe = AnchorVertex + TextWorldUp;
		if ((MidPoint - Probe).Size() > (MidPoint - AnchorVertex).Size())
			TextComp->SetVerticalAlignment(EVRTA_TextTop);
		// Since the normal faces out of the face, we actually probe to the "left" of the anchor point (hence the subtract instead of add).
		Probe = AnchorVertex - TextComp->GetRightVector();
		if ((Probe - AlignmentEdge.V1()).Size() > (AnchorVertex - AlignmentEdge.V1()).Size())
			TextComp->SetHorizontalAlignment(EHTA_Right);
	}

	float GetDistanceScaling(UTextRenderComponent* TextComp)
	{
		float DistanceScaling = 1.0f;
		if (GCurrentLevelEditingViewportClient != nullptr)
		{
			DistanceScaling = (GCurrentLevelEditingViewportClient->GetViewLocation() - TextComp->GetComponentLocation()).Size();
		}
		if (DistanceScaling > 1.0f)
		{
			// empirically derived through experimentation
			DistanceScaling = DistanceScaling / 800.0f;
		}
		return DistanceScaling;
	}
}

#endif

UAkSurfaceReflectorSetComponent::UAkSurfaceReflectorSetComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	// Property initialization
	bWantsOnUpdateTransform = true;

	bEnableSurfaceReflectors = 1;

	bEnableDiffraction = 1;

	bEnableDiffractionOnBoundaryEdges = 0;
	
#if WITH_EDITOR
	PropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(this, &UAkSurfaceReflectorSetComponent::OnPropertyChanged);
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;
	WasSelected = false;
#endif
}

void UAkSurfaceReflectorSetComponent::BeginDestroy()
{
	Super::BeginDestroy();
#if WITH_EDITOR
	FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(PropertyChangedHandle);
#endif
}

void UAkSurfaceReflectorSetComponent::OnRegister()
{
	Super::OnRegister();
	InitializeParentBrush();
	SendSurfaceReflectorSet();
}

void UAkSurfaceReflectorSetComponent::InitializeParentBrush(bool fromTick /* = false */)
{
	AVolume* Parent = Cast<AVolume>(GetOwner());
	if (Parent)
	{
		ParentBrush = Parent->Brush;
#if WITH_EDITOR
		// For runtime viewports, delay the UpdatePolys call until post-registration in tick.
		// When editing geometry in the editor, the brush vertex data can sometimes be out of date at this point, causing the 
		// EdgeMap to be incorrect, which results in the visualizer drawing incorrect edges.
		SchedulePolysUpdate();
#endif
	}
	else
	{
		bEnableSurfaceReflectors = false;
		ParentBrush = nullptr;
		if (!fromTick)
		{
			FString actorString = FString("NONE");
			FString actorClass = FString("NONE");
			if (GetOwner() != nullptr)
			{
				actorString = GetOwner()->GetName();
				UClass* ownerClass = GetOwner()->GetClass();
				if (ownerClass != nullptr)
					actorClass = ownerClass->GetName();
			}
			UE_LOG(LogAkAudio, Error, TEXT("UAkSurfaceReflectorSetComponent::InitializeParentBrush : Error. Actor %s, of type %s, has an AkSurfaceReflectorSetComponent attached (%s)."), *actorString, *actorClass, *UObject::GetName());
			UE_LOG(LogAkAudio, Error, TEXT("UAkSurfaceReflectorSetComponent requires to be attached to an actor inheriting from AVolume."));
		}
	}
}

void UAkSurfaceReflectorSetComponent::OnUnregister()
{
#if WITH_EDITOR
	if (!HasAnyFlags(RF_Transient))
	{
		DestroyTextVisualizers();
	}
#endif
	RemoveSurfaceReflectorSet();
	Super::OnUnregister();
}

#if WITH_EDITOR

TSet<int> UAkSurfaceReflectorSetComponent::GetSelectedFaceIndices() const
{
	TSet<int> selectedFaceIndices;

	// Determine if we are in geometry edit mode.
	if (GLevelEditorModeTools().IsModeActive(FEditorModeID(TEXT("EM_Geometry"))))
	{
		// If we are in geometry mode, go through the list of geometry objects
		// and find our current brush and update its source data as it might have changed 
		// in RecomputePoly
		if (ABrush* ownerBrush = Cast<ABrush>(GetOwner()))
		{
			USceneComponent* parentComp = GetAttachParent();
			if (ParentBrush != nullptr)
			{
				FEdModeGeometry* GeomMode = (FEdModeGeometry*)GLevelEditorModeTools().GetActiveMode(FEditorModeID(TEXT("EM_Geometry")));
				FEdModeGeometry::TGeomObjectIterator GeomModeIt = GeomMode->GeomObjectItor();
				const float tolerance = 0.001f;
				const FTransform& attachTransform = parentComp->GetComponentTransform();
				for (; GeomModeIt; ++GeomModeIt)
				{
					FGeomObjectPtr Object = *GeomModeIt;
					if (Object->GetActualBrush() == ownerBrush)
					{
						// selectedGeometry is a list of selected geometry elements. They can be vertices, edges, or polys
						TArray<FGeomBase*> selectedGeometry = Object->SelectionOrder;
						for (FGeomBase* selection : selectedGeometry)
						{
							if (!selection->IsVertex())
							{
								// There is no way to distinguish an edge from a poly, and we are unable to downcast.
								// Check the normal and mid point against the normal and mid point of each face in our model.
								// If we find the corresponding face, add its index to the selectedFaceIndices list.
								for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num() && NodeIdx < AcousticPolys.Num(); ++NodeIdx)
								{
									FVector localPolyMidPoint = attachTransform.InverseTransformPosition(AcousticPolys[NodeIdx].MidPoint);
									if (FMath::IsNearlyEqual((selection->GetNormal() - FPlane(ParentBrush->Nodes[NodeIdx].Plane)).Size(), 0.0f, tolerance)
										&& FMath::IsNearlyEqual((selection->GetMid() - localPolyMidPoint).Size(), 0.0f, tolerance))
									{
										selectedFaceIndices.Add(NodeIdx);
										break;
									}
								}
							}
						}
						break;
					}
				}
			}
		}
	}

	return selectedFaceIndices;
}

void UAkSurfaceReflectorSetComponent::CacheAcousticProperties()
{
	ensure(PreviousPolys.Num() == AcousticPolys.Num());
	for (int FaceIndex = 0; FaceIndex < PreviousPolys.Num(); ++FaceIndex)
	{
		PreviousPolys[FaceIndex].Texture = AcousticPolys[FaceIndex].Texture;
		PreviousPolys[FaceIndex].Occlusion = AcousticPolys[FaceIndex].Occlusion;
		PreviousPolys[FaceIndex].EnableSurface = AcousticPolys[FaceIndex].EnableSurface;
	}
}

void UAkSurfaceReflectorSetComponent::CacheLocalSpaceSurfaceGeometry()
{
	PreviousPolys = AcousticPolys;
	USceneComponent* ParentComp = GetAttachParent();
	if (ParentComp == nullptr)
		return;
	const FTransform AttachTransformInverse = ParentComp->GetComponentTransform().Inverse();
	for (FAkSurfacePoly& Face : PreviousPolys)
	{
		Face.MidPoint = AttachTransformInverse.TransformPositionNoScale(Face.MidPoint);
		Face.Normal = AttachTransformInverse.TransformVectorNoScale(Face.Normal);
		Face.Normal.Normalize();
		for (FAkSurfaceEdgeVerts& EdgeVerts : Face.Edges)
		{
			EdgeVerts.TransformEdge(AttachTransformInverse);
		}
	}
}

void UAkSurfaceReflectorSetComponent::SkipNextTexturesUpdate()
{
	if (GetWorld() && GetWorld()->ShouldTick())
	{
		bSkipTexturesUpdate = true;
	}
}

bool UAkSurfaceReflectorSetComponent::TexturesDiffer() const
{
	if (AcousticPolys.Num() == 0)
		return false;

	UAkAcousticTexture* texture = AcousticPolys[0].Texture;
	for (const FAkSurfacePoly Poly : AcousticPolys)
	{
		if (Poly.Texture != texture)
			return true;
	}
	
	return false;
}

void UAkSurfaceReflectorSetComponent::OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent)
{
	bool changeAffectsThis = false;
	if (AActor* actor = Cast<AActor>(ObjectBeingModified))
	{
		if (actor == GetOwner())
		{
			changeAffectsThis = true;
		}
	}
	if (USceneComponent* component = Cast<USceneComponent>(ObjectBeingModified))
	{
		if (component->GetOwner() == GetOwner())
		{
			changeAffectsThis = true;
		}
	}
	if (changeAffectsThis)
	{
		// The start of a UI interaction will trigger a EPropertyChangeType::Interactive.
		// This will be followed by a EPropertyChangeType::ValueSet at the end of the interaction.
		if (PropertyChangedEvent.ChangeType == EPropertyChangeType::Interactive)
		{
			UserInteractionInProgress = true;
		}
		if (UserInteractionInProgress && PropertyChangedEvent.ChangeType == EPropertyChangeType::ValueSet)
		{
			UserInteractionInProgress = false;
		}
	}
}

void UAkSurfaceReflectorSetComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	InitializeParentBrush();
		
	if (ParentBrush != nullptr)
	{
		UpdatePolys();
	}

	if (AssociatedRoom && !Cast<UAkRoomComponent>(AssociatedRoom->GetComponentByClass(UAkRoomComponent::StaticClass())))
	{
		UE_LOG(LogAkAudio, Warning, TEXT("%s: The Surface Reflector Set's Associated Room is not of type UAkRoomComponent."), *GetOwner()->GetName());
	}

	const FName MemberPropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkSurfaceReflectorSetComponent, AcousticPolys))
	{
		RegisterAllTextureParamCallbacks();
		RecalculateHFDamping();
	}
}

void UAkSurfaceReflectorSetComponent::PostEditUndo()
{
	OnRefreshDetails.ExecuteIfBound(); 
	Super::PostEditUndo();
	// After the undo operation has finished, re-populate the PreviousPolys array to the current state.
	CacheLocalSpaceSurfaceGeometry();
}

void UAkSurfaceReflectorSetComponent::PreEditUndo()
{
	// Empty the previous polys such that any surface properties are correctly reverted.
	PreviousPolys.Empty();
	Super::PreEditUndo();
}

FText UAkSurfaceReflectorSetComponent::GetPolyText(int32 PolyIdx) const
{
	if (PolyIdx >= AcousticPolys.Num())
		return FText();

	return AcousticPolys[PolyIdx].GetPolyText(bEnableSurfaceReflectors);
}

void UAkSurfaceReflectorSetComponent::UpdateText(bool Visible)
{
	bool bReallyVisible = GetWorld() && GetWorld()->WorldType == EWorldType::Editor && Visible;
	if (GetOwner() != nullptr)
	{
		const AAkSpatialAudioVolume* SpatialAudioVolume = Cast<const AAkSpatialAudioVolume>(GetOwner());
		if (SpatialAudioVolume != nullptr && SpatialAudioVolume->FitToGeometry)
			bReallyVisible &= (!SpatialAudioVolume->IsDragging || SpatialAudioVolume->FitFailed);
	}
	for (int32 i = 0; i < TextVisualizers.Num(); i++)
	{
		if (TextVisualizers[i])
		{
			TextVisualizers[i]->SetText(GetPolyText(i));
			TextVisualizers[i]->SetVisibility(bReallyVisible);
		}
	}
	UpdateTextPositions();
}

void UAkSurfaceReflectorSetComponent::SurfacePropertiesChanged()
{
	CacheAcousticProperties();

	UpdateText(GetOwner() && GetOwner()->IsSelected());
	RegisterAllTextureParamCallbacks();
	RecalculateHFDamping();
}

void UAkSurfaceReflectorSetComponent::DestroyTextVisualizers()
{
	for (int32 i = 0; i < TextVisualizers.Num(); i++)
	{
		if(TextVisualizers[i])
			TextVisualizers[i]->DestroyComponent();
	}

	TextVisualizers.Empty();
}

void UAkSurfaceReflectorSetComponent::SchedulePolysUpdate()
{
	if (GetWorld()->ShouldTick())
	{
		PolysNeedUpdate = true;
	}
	else
	{
		if (ParentBrush && ParentBrush->Nodes.Num() != AcousticPolys.Num())
		{
			UpdatePolys();
		}
	}
}

void UAkSurfaceReflectorSetComponent::UpdatePolys(bool bPreserveTextures /*= false*/)
{
	if (!ParentBrush || HasAnyFlags(RF_Transient) || UserInteractionInProgress)
	{
		return;
	}

	int32 NumFaces = AcousticPolys.Num();
	int32 NumBrushFaces = ParentBrush->Nodes.Num();
	const bool shouldRefreshDetails = NumFaces != NumBrushFaces;
	if (NumBrushFaces > NumFaces)
	{
		AcousticPolys.AddDefaulted(NumBrushFaces - NumFaces);
	}
	else if(NumBrushFaces < NumFaces)
	{
		AcousticPolys.RemoveAt(NumBrushFaces, NumFaces - NumBrushFaces);
	}

	const auto WorldScale = GetOwner()->ActorToWorld().GetScale3D();

	for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num(); ++NodeIdx)
	{
		if (ParentBrush->Nodes[NodeIdx].NumVertices > 2)
		{
			TArray<FVector> ScaledVertices;

			const int32 VertStartIndex = ParentBrush->Nodes[NodeIdx].iVertPool;

			FVector CentroidPosition = FVector::ZeroVector;
			for (int32 VertIdx = 0; VertIdx < ParentBrush->Nodes[NodeIdx].NumVertices; ++VertIdx)
			{
				auto Vert = FVector(ParentBrush->Points[ParentBrush->Verts[VertStartIndex + VertIdx].pVertex]) * WorldScale;
				CentroidPosition += Vert;
				ScaledVertices.Emplace(Vert);
			}
			CentroidPosition /= (float)ParentBrush->Nodes[NodeIdx].NumVertices;
			double Area = 0.0f;
			for (int vIndex = 0; vIndex < ScaledVertices.Num() - 1; ++vIndex)
			{
				Area += FAkReverbDescriptor::TriangleArea(CentroidPosition, ScaledVertices[vIndex], ScaledVertices[vIndex + 1]);
			}
			Area += FAkReverbDescriptor::TriangleArea(CentroidPosition, ScaledVertices[ScaledVertices.Num() - 1], ScaledVertices[0]);
			AcousticPolys[NodeIdx].SetSurfaceArea(Area);
		}
	}

	// Always recreate all text visualizers as indexes may have changed.
	DestroyTextVisualizers();
	UMaterialInterface* mat = Cast<UMaterialInterface>(FAkAudioStyle::GetAkForegroundTextMaterial());

	for (int32 i = 0; i < AcousticPolys.Num(); i++)
	{
		FString VizName = GetOwner()->GetName() + GetName() + TEXT("TextViz ") + FString::FromInt(i);
		if (AcousticPolys[i].EnableSurface)
		{
			int32 idx = TextVisualizers.Add(NewObject<UTextRenderComponent>(GetOuter(), *VizName));
			if (TextVisualizers[idx])
			{
				if (mat != nullptr)
					TextVisualizers[idx]->SetTextMaterial(mat);
				TextVisualizers[idx]->RegisterComponentWithWorld(GetWorld());
				TextVisualizers[idx]->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
				TextVisualizers[idx]->bIsEditorOnly = true;
				TextVisualizers[idx]->bSelectable = false;
				TextVisualizers[idx]->bAlwaysRenderAsText = true;
				TextVisualizers[idx]->SetHorizontalAlignment(EHTA_Center);
				TextVisualizers[idx]->SetVerticalAlignment(EVRTA_TextCenter);
			}
		}
		else
		{
			TextVisualizers.Add(nullptr);
		}
	}

	UpdateEdgeMap(!bPreserveTextures);
	UpdateText(GetOwner() && GetOwner()->IsSelected());
	RegisterAllTextureParamCallbacks();
	RecalculateHFDamping();
	PolysNeedUpdate = false;
	if (shouldRefreshDetails)
		OnRefreshDetails.ExecuteIfBound();
}

FUnrealFloatVector GetModelCenter(const UModel& Model)
{
	FUnrealFloatVector Center = FUnrealFloatVector::ZeroVector;
	uint32 Count = 0;
	for (int32 NodeIndex = 0; NodeIndex < Model.Nodes.Num(); NodeIndex++)
	{
		const FBspNode& Node = Model.Nodes[NodeIndex];
		uint32 NumVerts = (Node.NodeFlags & PF_TwoSided) ? Node.NumVertices / 2 : Node.NumVertices;
		for (uint32 VertexIndex = 0; VertexIndex < NumVerts; VertexIndex++)
		{
			const FVert& Vert = Model.Verts[Node.iVertPool + VertexIndex];
			const auto& Position = Model.Points[Vert.pVertex];
			Center += Position;
			Count++;
		}
	}

	if (Count > 0)
	{
		Center /= Count;
	}

	return Center;
}

void UAkSurfaceReflectorSetComponent::SortFaceEdges(int FaceIndex)
{
	FAkSurfacePoly& Face = AcousticPolys[FaceIndex];

	if (Face.Edges.Num() < 2)
		return;

	for (int SortedPosition = 1; SortedPosition < Face.Edges.Num(); ++SortedPosition)
	{
		const FVector& PreviousV1 = Face.Edges[SortedPosition - 1].V1;
		for (int IndexToSwap = SortedPosition; IndexToSwap < Face.Edges.Num(); ++IndexToSwap)
		{
			const FVector& CurrentV0 = Face.Edges[IndexToSwap].V0;
			const FVector& CurrentV1 = Face.Edges[IndexToSwap].V1;
			if (PreviousV1.Equals(CurrentV0, AkSurfaceReflectorUtils::EQUALITY_THRESHOLD) 
				|| PreviousV1.Equals(CurrentV1, AkSurfaceReflectorUtils::EQUALITY_THRESHOLD))
			{
				Face.Edges.Swap(SortedPosition, IndexToSwap);
				if (PreviousV1.Equals(CurrentV1, AkSurfaceReflectorUtils::EQUALITY_THRESHOLD))
				{
					Face.Edges[SortedPosition].Invert();
				}
				break;
			}
		}
	}
}

void UAkSurfaceReflectorSetComponent::UpdateFaceNormals(int FaceIndex)
{
	FAkSurfacePoly& Face = AcousticPolys[FaceIndex];

	FVector E0 = Face.Edges[0].GetUnitVector();
	FVector E1 = Face.Edges[1].GetUnitVector();
	const float AlmostParallel = 0.99f;
	if (FVector::DotProduct(E0, E1) >= AlmostParallel)
		return;
	Face.Normal = FVector::CrossProduct(E0, E1);
	Face.Normal.Normalize();
	USceneComponent* ParentComp = GetAttachParent();
	if (ParentBrush != nullptr && ParentComp != nullptr)
	{
		const FTransform AttachTransform = ParentComp->GetComponentTransform();
		const FVector BrushCentre = AttachTransform.TransformPosition(FVector(GetModelCenter(*ParentBrush)));
		FVector VToCentre = BrushCentre - Face.Edges[0].V0;
		VToCentre.Normalize();
		if (FVector::DotProduct(VToCentre, Face.Normal) > 0.0f)
		{
			// normal is pointing in wrong direction. Flip the ends of each Edge.
			for (int EdgeIndex = 0; EdgeIndex < Face.Edges.Num(); ++EdgeIndex)
			{
				Face.Edges[EdgeIndex].Invert();
			}
			Face.Normal *= -1.0f;
			Face.Normal.Normalize();
		}
	}
}

void UAkSurfaceReflectorSetComponent::UpdateEdgeMap(bool bUpdateTextures)
{
	EdgeMap.Empty();
	const AAkSpatialAudioVolume* SpatialAudioVolume = Cast<const AAkSpatialAudioVolume>(GetOwner());
	USceneComponent* parentComp = GetAttachParent();
	if (ParentBrush != nullptr && SpatialAudioVolume != nullptr && parentComp != nullptr)
	{
		const FTransform AttachTransform = parentComp->GetComponentTransform();
		for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num() && NodeIdx < AcousticPolys.Num(); ++NodeIdx)
		{
			AcousticPolys[NodeIdx].ClearEdgeInfo();
			FVector PolyMidPoint(0, 0, 0);
			FVector PolyWorldSpaceNormal(0, 0, 0);
			FAkSurfaceEdgeInfo EdgeInfo;
			FUnrealFloatPlane& Plane = ParentBrush->Nodes[NodeIdx].Plane;
			EdgeInfo.Normal = FVector(Plane.X, Plane.Y, Plane.Z);
			EdgeInfo.IsEnabled = AcousticPolys[NodeIdx].EnableSurface;
			int32 VertStartIndex = ParentBrush->Nodes[NodeIdx].iVertPool;
			FVert BrushVert0 = ParentBrush->Verts[VertStartIndex];
			FVert BrushVert1 = ParentBrush->Verts[VertStartIndex + 1];

			// Add edges to map for edges visualization
			int32 NumVertices = ParentBrush->Nodes[NodeIdx].NumVertices;
			for (int32 Idx0 = NumVertices - 1, Idx1 = 0;
				Idx1 < NumVertices;
				Idx0 = Idx1, Idx1++)
			{
				BrushVert0 = ParentBrush->Verts[VertStartIndex + Idx0];
				BrushVert1 = ParentBrush->Verts[VertStartIndex + Idx1];

				PolyMidPoint += AttachTransform.TransformPosition(FVector(ParentBrush->Points[BrushVert1.pVertex]));

				EdgeInfo.SetV0(AttachTransform.TransformPosition(FVector(ParentBrush->Points[BrushVert0.pVertex])));
				EdgeInfo.SetV1(AttachTransform.TransformPosition(FVector(ParentBrush->Points[BrushVert1.pVertex])));

				int64 EdgeHash = EdgeInfo.GetHash();
				FAkSurfaceEdgeInfo* Found = EdgeMap.Find(EdgeHash);
				if (Found)
				{
					const float DP = FVector::DotProduct(Found->Normal, EdgeInfo.Normal);
					if (FMath::IsNearlyEqual(DP, 1.0f, 0.00001f))
						Found->IsFlat = true;
					else
						Found->IsBoundary = !(Found->IsEnabled && EdgeInfo.IsEnabled);
					
					AcousticPolys[NodeIdx].Edges.Add(EdgeInfo.EdgeVerts);
					Found->IsEnabled |= EdgeInfo.IsEnabled;
				}
				else
				{
					EdgeMap.Add(EdgeHash, EdgeInfo);
					AcousticPolys[NodeIdx].Edges.Add(EdgeInfo.EdgeVerts);
				}
			}
			PolyMidPoint /= (float)ParentBrush->Nodes[NodeIdx].NumVertices;
			AcousticPolys[NodeIdx].MidPoint = PolyMidPoint;
			SortFaceEdges(NodeIdx);
			// Non-uniform scaling of dimensions will skew the normals stored in the brush, so we need to recaluclate them here
			// taking scaling into account.
			UpdateFaceNormals(NodeIdx);
		}
		if (bUpdateTextures)
			EdgeMapChanged(AttachTransform);
	}
	CacheLocalSpaceSurfaceGeometry();
}

void UAkSurfaceReflectorSetComponent::EdgeMapChanged(const FTransform& AttachTransform)
{
	if (PreviousPolys.Num() <= 0)
		return;
	for (int FaceIndex = 0; FaceIndex < AcousticPolys.Num(); ++FaceIndex)
	{
		FAkSurfacePoly& Face = AcousticPolys[FaceIndex];
		Face.Texture = nullptr;
		Face.Occlusion = 0.0f;
		Face.EnableSurface = true;
		FVector ComponentNormal = AttachTransform.Inverse().TransformVectorNoScale(Face.Normal);
		ComponentNormal.Normalize();
		const float Thresh = AkSurfaceReflectorUtils::EQUALITY_THRESHOLD;
		for (int OtherFaceIndex = 0; OtherFaceIndex < PreviousPolys.Num(); ++OtherFaceIndex)
		{
			FAkSurfacePoly& PreviousFace = PreviousPolys[OtherFaceIndex];
			if (!ComponentNormal.Equals(PreviousFace.Normal, Thresh))
				continue;
			int NumSharedEdges = 0;
			int EdgeIndex = 0;
			while (NumSharedEdges < 2 && EdgeIndex < Face.Edges.Num())
			{
				FAkSurfaceEdgeVerts Edge = Face.Edges[EdgeIndex].GetTransformedEdge(AttachTransform.Inverse());
				for (int OtherEdgeIndex = 0; OtherEdgeIndex < PreviousFace.Edges.Num(); ++OtherEdgeIndex)
				{
					const FAkSurfaceEdgeVerts& PreviousEdge = PreviousFace.Edges[OtherEdgeIndex];
					const float EdgeDP = FVector::DotProduct(Edge.GetUnitVector(), PreviousEdge.GetUnitVector());
					if (FMath::IsNearlyEqual(EdgeDP, 1.0f, Thresh) && (FAkSurfaceEdgeVerts::EdgesShareVertex(Edge, PreviousEdge)))
					{
						++NumSharedEdges;
						break;
					}
				}
				++EdgeIndex;
			}
			if (NumSharedEdges >= 2)
			{
				Face.Texture = PreviousFace.Texture;
				Face.Occlusion = PreviousFace.Occlusion;
				Face.EnableSurface = PreviousFace.EnableSurface;
				break;
			}
		}
	}	
}

int UAkSurfaceReflectorSetComponent::ChooseAlignmentEdge(int FaceIndex) const
{
	int EdgeChoice = 0;
	if (GCurrentLevelEditingViewportClient != nullptr
		&& ParentBrush != nullptr
		&& FaceIndex < TextVisualizers.Num()
		&& FaceIndex < ParentBrush->Nodes.Num()
		&& FaceIndex < AcousticPolys.Num())
	{
		FVector CamUp = UKismetMathLibrary::GetUpVector(GCurrentLevelEditingViewportClient->GetViewRotation());
		UTextRenderComponent* TextComp = TextVisualizers[FaceIndex];
		FVector Normal = AcousticPolys[FaceIndex].Normal;
		Normal.Normalize();
		const FAkSurfacePoly& Face = AcousticPolys[FaceIndex];
		FVector AlignmentV0 = FVector::ZeroVector;
		FVector AlignmentV1 = FVector::ZeroVector;
		for (int EdgeIndex = 0; EdgeIndex < Face.Edges.Num(); ++EdgeIndex)
		{
			AlignmentV0 = Face.Edges[EdgeIndex].V0;
			AlignmentV1 = Face.Edges[EdgeIndex].V1;
			FVector Tangent = AlignmentV1 - AlignmentV0;
			Tangent.Normalize();
			FVector Up = -FVector::CrossProduct(Tangent, Normal);
			Up.Normalize();
			float DP = FMath::Abs(FVector::DotProduct(CamUp, Up));
			const float DPDiffThresh = 0.1f;
			if (DP > AcousticPolys[FaceIndex].OptimalEdgeDP && FMath::Abs(DP - AcousticPolys[FaceIndex].OptimalEdgeDP) > DPDiffThresh)
			{
				AcousticPolys[FaceIndex].OptimalEdgeDP = DP;
				EdgeChoice = EdgeIndex;
			}
		}
	}
	return EdgeChoice;
}

FVector UAkSurfaceReflectorSetComponent::GetTextAnchorPosition(int FaceIndex, const FAkSurfaceEdgeInfo& AlignmentEdge, int AlignmentEdgeIndex) const
{
	UTextRenderComponent* TextComp = TextVisualizers[FaceIndex];
	TextComp->SetWorldLocation(AlignmentEdge.V0());
	const FAkSurfacePoly& Face = AcousticPolys[FaceIndex];
	// Find the edge that connectes to the first vertex of the AlignmentEdge
	int ConnectedEdgeIndex = (AlignmentEdgeIndex - 1) < 0 ? Face.Edges.Num() - 1 : AlignmentEdgeIndex - 1;
	const FAkSurfaceEdgeVerts* ConnectedEdge = &Face.Edges[ConnectedEdgeIndex];
	if (!ConnectedEdge->V1.Equals(AlignmentEdge.V0(), AkSurfaceReflectorUtils::EQUALITY_THRESHOLD))
	{
		ConnectedEdgeIndex = (AlignmentEdgeIndex + 1) % Face.Edges.Num();
		ConnectedEdge = &Face.Edges[ConnectedEdgeIndex];
		if (!ConnectedEdge->V1.Equals(AlignmentEdge.V0(), AkSurfaceReflectorUtils::EQUALITY_THRESHOLD))
			return AlignmentEdge.V0();
	}
	const FVector NormedConnectedEdge = -ConnectedEdge->GetUnitVector();
	const FVector AlignmentEdgeUnitV = (AlignmentEdge.V1() - AlignmentEdge.V0()).GetSafeNormal();
	const float AlignmentCornerDP = FVector::DotProduct(NormedConnectedEdge, AlignmentEdgeUnitV);
	FVector Shift(0.0f);
	if (AlignmentCornerDP > 0.0f)
	{
		float ProjCornerV = FMath::Abs(FVector::DotProduct(NormedConnectedEdge, AlignmentEdgeUnitV));
		float MaxWidth = (AlignmentEdge.V1() - AlignmentEdge.V0()).Size() / 2.0f;
		Shift = ProjCornerV * MaxWidth * AlignmentEdgeUnitV;
	}
	return AlignmentEdge.V0() + Shift;
}

void UAkSurfaceReflectorSetComponent::SetTextScale(int FaceIndex, int AlignmentEdgeIndex, const FVector& TextAnchorPosition, const FFacePlane& FacePlane) const
{
	UTextRenderComponent* TextComp = TextVisualizers[FaceIndex];
	const FVector WorldTextSize = TextComp->GetTextWorldSize();
	float Scale = TextAlignmentHelpers::GetDistanceScaling(TextComp);
	bool IntersectionFound = true;
	const FAkSurfacePoly& Face = AcousticPolys[FaceIndex];
	// Look for intersections between the edges of the text visualizer and the edges of the face.
	// Scale down by the smallest amount until no more intersections are found.
	while (IntersectionFound)
	{
		TArray<FAkSurfaceEdgeInfo> TextEdges = TextAlignmentHelpers::GetTextEdges(*TextComp, TextAnchorPosition, FacePlane, Scale);
		float ScaleDown = 0.0f;
		float BisectionRatio;
		for (const FAkSurfaceEdgeInfo& TextEdge : TextEdges)
		{
			for (int EdgeIndex = 0; EdgeIndex < Face.Edges.Num(); ++EdgeIndex)
			{
				if (EdgeIndex != AlignmentEdgeIndex)
				{
					FVector BrushEdgeV0 = Face.Edges[EdgeIndex].V0;
					FVector BrushEdgeV1 = Face.Edges[EdgeIndex].V1;

					FAkSurfaceEdgeInfo brushEdge(BrushEdgeV0, BrushEdgeV1);
					FVector intersection = FVector::ZeroVector;

					TextAlignmentHelpers::GetTextEdgeBisection(TextEdge, brushEdge, FacePlane, BisectionRatio);
					if (BisectionRatio > ScaleDown && BisectionRatio < 1.0f)
						ScaleDown = BisectionRatio;
				}
			}
		}
		if (ScaleDown > 0.0f)
			Scale *= ScaleDown;
		else
			IntersectionFound = false;
	}
	TextComp->SetWorldScale3D(FVector(FMath::Max(1.0f, Scale)));
}

void UAkSurfaceReflectorSetComponent::AlignTextWithEdge(int FaceIndex) const
{
	if (GCurrentLevelEditingViewportClient != nullptr
		&& ParentBrush != nullptr
		&& FaceIndex < TextVisualizers.Num()
		&& FaceIndex < ParentBrush->Nodes.Num()
		&& FaceIndex < AcousticPolys.Num())
	{
		int EdgeIndex = ChooseAlignmentEdge(FaceIndex);
		UTextRenderComponent* TextComp = TextVisualizers[FaceIndex];
		const FAkSurfacePoly& Face = AcousticPolys[FaceIndex];
		FVector AlignmentV0 = Face.Edges[EdgeIndex].V0;
		FVector AlignmentV1 = Face.Edges[EdgeIndex].V1;
		if (TextComp != nullptr)
		{
			FVector Normal = Face.Normal;
			FVector Edge = AlignmentV1 - AlignmentV0;
			FVector Tangent = Edge;
			Normal.Normalize();
			Tangent.Normalize();
			FVector CamToCentre = GCurrentLevelEditingViewportClient->GetViewLocation() - AlignmentV0 + Edge * 0.5f;
			FVector Up = TextAlignmentHelpers::DetermineUpVector(Tangent, Normal, CamToCentre);
			TextComp->SetWorldRotation(UKismetMathLibrary::MakeRotFromXZ(Normal, Up));
			FVector MidPoint = Face.MidPoint;
			TextAlignmentHelpers::SetTextAlignment(TextComp, FAkSurfaceEdgeInfo(AlignmentV0, AlignmentV1), MidPoint);
			FVector TextAnchorPosition = GetTextAnchorPosition(FaceIndex, FAkSurfaceEdgeInfo(AlignmentV0, AlignmentV1), EdgeIndex);
			TextComp->SetWorldLocation(TextAnchorPosition);
			FFacePlane FacePlane(AlignmentV0, TextComp->VerticalAlignment == EVRTA_TextBottom ? Up : -Up, Edge.GetSafeNormal());
			SetTextScale(FaceIndex, EdgeIndex, TextAnchorPosition, FacePlane);
		}
	}
}

void UAkSurfaceReflectorSetComponent::UpdateTextPositions() const
{
	const AAkSpatialAudioVolume* SpatialAudioVolume = Cast<const AAkSpatialAudioVolume>(GetOwner());
	if (ParentBrush != nullptr && SpatialAudioVolume != nullptr)
	{
		// For each text visualizer, find an appropriate edge on the face and align that visualizer with the edge.
		for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num() && NodeIdx < TextVisualizers.Num(); ++NodeIdx)
		{
			UTextRenderComponent* TextComp = TextVisualizers[NodeIdx];
			if (TextComp != nullptr)
			{
				AlignTextWithEdge(NodeIdx);
			}
		}
	}
}

void UAkSurfaceReflectorSetComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!ParentBrush)
	{
		InitializeParentBrush(true);
	}

	const bool bNumBrushNodesChanged = (ParentBrush && ParentBrush->Nodes.Num() != AcousticPolys.Num());
	if (PolysNeedUpdate || bNumBrushNodesChanged)
	{
		const bool bPreserveTextures = bSkipTexturesUpdate && !bNumBrushNodesChanged;
		UpdatePolys(bPreserveTextures);
		bSkipTexturesUpdate = false;
	}

	if (GetOwner()->IsSelected() && !WasSelected)
	{
		WasSelected = true;
		UpdateText(true);
	}

	if (!GetOwner()->IsSelected() && WasSelected)
	{
		WasSelected = false;
		UpdateText(false);
	}
}
#endif // WITH_EDITOR

bool UAkSurfaceReflectorSetComponent::MoveComponentImpl(
	const FVector& Delta,
	const FQuat& NewRotation,
	bool bSweep,
	FHitResult* Hit,
	EMoveComponentFlags MoveFlags,
	ETeleportType Teleport)
{
	if (USceneComponent* Parent = GetAttachParent())
		if (AkComponentHelpers::DoesMovementRecenterChild(this, Parent, Delta))
			Super::MoveComponentImpl(Delta, NewRotation, bSweep, Hit, MoveFlags, Teleport);

	return false;
}

void UAkSurfaceReflectorSetComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	UpdateSurfaceReflectorSet();
#if WITH_EDITOR
	UpdateEdgeMap(false);
	UpdateText(GetOwner() && GetOwner()->IsSelected());
#endif
}

void UAkSurfaceReflectorSetComponent::GetTexturesAndSurfaceAreas(TArray<FAkAcousticTextureParams>& textures, TArray<float>& surfaceAreas) const
{
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (AcousticPolys.Num() > 0)
		{
			for (const FAkSurfacePoly& Poly : AcousticPolys)
			{
				if (Poly.Texture)
				{
					surfaceAreas.Add(Poly.GetSurfaceArea() / AkComponentHelpers::UnrealUnitsPerSquaredMeter(this));
					const FAkAcousticTextureParams* params = AkSettings->GetTextureParams(Poly.Texture->ShortID);
					if (params != nullptr)
					{
						textures.Add(*params);
					}
					else
					{
						textures.Add(FAkAcousticTextureParams());
					}
				}
			}
		}
	}
}

bool UAkSurfaceReflectorSetComponent::ShouldSendGeometry() const
{
	if (GetAttachParent() == nullptr || ParentBrush == nullptr)
		return false;
	UAkRoomComponent* siblingRoom = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*GetAttachParent());
	if (!bEnableSurfaceReflectors && !(siblingRoom && siblingRoom->bEnable))
		return false;

	return UAkAcousticTextureSetComponent::ShouldSendGeometry();
}

void UAkSurfaceReflectorSetComponent::SendSurfaceReflectorSet() 
{
	if (GetWorld() && GetWorld()->bIsTearingDown)
		return;

	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();

	if (AkAudioDevice && ShouldSendGeometry())
	{
		TArray<AkVertex> VertsToSend;
		TArray<AkAcousticSurface> SurfacesToSend;
		TArray<AkTriangle> TrianglesToSend;
		TArray<AK::SpatialAudio::String> triangleNames;
		FString ParentName = GetOwner()->GetName();
		// Some clarifications: 
		// - All of the brush's vertices are held in the UModel->Verts array (elements of type FVert)
		// - FVert contains pVertex, which points to the UModel->Points array (actual coords of the point in actor space)
		// - Polygons are represented by the UModel->Nodes array (elements of type FBspNode).
		// - FBspNode contains iVertPool, which represents the index in the UModel->Verts at which the node's verts start
		// - FBspNode contains NumVertices, the number of vertices that compose this node.
		//
		// For more insight on how all of these tie together, look at UModel::BuildVertexBuffers().

		// A mapping from the unreal vertex index to the wwise vertex index.
		TArray<int32> UnrealToWwiseIndex;
		UnrealToWwiseIndex.Init(-1, ParentBrush->Points.Num());

		// A function to add unique vertices to the VertsToSend array.
		// UnrealToWwiseIndex keeps track of added vertices to avoid duplicates.
		// This function ensures that we only include vertices that are actually referenced by triangles.
		auto AddVertex = [&UnrealToWwiseIndex,&VertsToSend,this](int32 UnrealIdx)
		{
			int32 wwiseIdx = UnrealToWwiseIndex[UnrealIdx];
			if (wwiseIdx == -1)
			{
				wwiseIdx = VertsToSend.Num();
				UnrealToWwiseIndex[UnrealIdx] = wwiseIdx;

				const FVector& VertexInActorSpace = FVector(ParentBrush->Points[UnrealIdx]);
				FVector v = GetOwner()->ActorToWorld().TransformPosition(VertexInActorSpace);
				AkVertex akvtx;
				akvtx.X = v.X;
				akvtx.Y = v.Y;
				akvtx.Z = v.Z;
				VertsToSend.Add(akvtx);

			}
			check(wwiseIdx < (AkVertIdx)-1);
			return (AkVertIdx)wwiseIdx;
		};

		for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num(); ++NodeIdx)
		{
			if (AcousticPolys.Num() > NodeIdx)
			{
				FAkSurfacePoly AcosuticSurface = AcousticPolys[NodeIdx];
				if (ParentBrush->Nodes[NodeIdx].NumVertices > 2 && (AcosuticSurface.EnableSurface || !bEnableSurfaceReflectors))
				{
					AkAcousticSurface NewSurface;
					FString TriangleName;
					if (AcosuticSurface.Texture != nullptr)
					{
						TriangleName = ParentName + GetName() + FString(TEXT("_")) + AcosuticSurface.Texture->GetName() + FString::FromInt(NodeIdx);
					}
					else
					{
						TriangleName = ParentName + GetName() + FString(TEXT("_")) + FString::FromInt(NodeIdx);
					}

					NewSurface.textureID = AcosuticSurface.Texture != nullptr ? FAkAudioDevice::GetIDFromString(AcosuticSurface.Texture->GetName()) : 0;
					NewSurface.transmissionLoss = AcosuticSurface.Occlusion;
					int32 newIdx = triangleNames.Add(TCHAR_TO_ANSI(*TriangleName));
					triangleNames[newIdx].AllocCopy(); //the conversion macro TCHAR_TO_ANSI will reuse the same buffer, so we need a local copy.
					NewSurface.strName = triangleNames[newIdx].Get();
					SurfacesToSend.Add(NewSurface);

					//

					int32 VertStartIndex = ParentBrush->Nodes[NodeIdx].iVertPool;

					const FVert* Vert0 = &ParentBrush->Verts[VertStartIndex + 0];
					const FVert* Vert1 = &ParentBrush->Verts[VertStartIndex + 1];

					for (int32 VertexIdx = 2; VertexIdx < ParentBrush->Nodes[NodeIdx].NumVertices; ++VertexIdx)
					{
						const FVert* Vert2 = &ParentBrush->Verts[VertStartIndex + VertexIdx];

						AkTriangle NewTriangle;
						NewTriangle.point0 = AddVertex(Vert0->pVertex);
						NewTriangle.point1 = AddVertex(Vert1->pVertex);
						NewTriangle.point2 = AddVertex(Vert2->pVertex);
						NewTriangle.surface = (AkSurfIdx)(SurfacesToSend.Num()-1);
						TrianglesToSend.Add(NewTriangle);

						Vert1 = Vert2;
					}
				}
			}
		}

		if (TrianglesToSend.Num() > 0 && VertsToSend.Num() > 0)
		{
			AkGeometryParams params;
			params.NumSurfaces = SurfacesToSend.Num();
			params.NumTriangles = TrianglesToSend.Num();
			params.NumVertices = VertsToSend.Num();
			params.Surfaces = SurfacesToSend.GetData();
			params.Triangles = TrianglesToSend.GetData();
			params.Vertices = VertsToSend.GetData();
			params.EnableDiffraction = bEnableDiffraction;
			params.EnableDiffractionOnBoundaryEdges = bEnableDiffractionOnBoundaryEdges;
			params.EnableTriangles = bEnableSurfaceReflectors;

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

void UAkSurfaceReflectorSetComponent::RemoveSurfaceReflectorSet()
{
	RemoveGeometryFromWwise();
}

void UAkSurfaceReflectorSetComponent::UpdateSurfaceReflectorSet()
{
	SendSurfaceReflectorSet();
	if (ReverbDescriptor != nullptr)
	{
		DampingEstimationNeedsUpdate = true;
	}
}

#if WITH_EDITOR
void UAkSurfaceReflectorSetComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	Super::HandleObjectsReplaced(ReplacementMap);
	if (ReplacementMap.Contains(ParentBrush))
	{
		InitializeParentBrush();
		SendSurfaceReflectorSet();
	}
}

bool UAkSurfaceReflectorSetComponent::ContainsTexture(const FGuid& textureID)
{
	for (const FAkSurfacePoly& Poly : AcousticPolys)
		if (Poly.Texture != nullptr && Poly.Texture->ID == textureID)
			return true;
	return false;
}

void UAkSurfaceReflectorSetComponent::RegisterAllTextureParamCallbacks()
{
	for (const FAkSurfacePoly& Poly : AcousticPolys)
		if (Poly.Texture != nullptr && TextureDelegateHandles.Find(Poly.Texture->ID) == nullptr)
			RegisterTextureParamChangeCallback(Poly.Texture->ID);
}

TWeakObjectPtr<UPhysicalMaterial> AssignPolygonTexturesFromSamples(const TArray<FVector>& Vertices, const TArray<FVector>& Points, const TArray<FVector>& Normals, const TArray< TWeakObjectPtr<UPhysicalMaterial> >& Materials, int Num)
{
	const float kNormalAgreement = 0.866f; // ~30 degrees

	TMap<TWeakObjectPtr<UPhysicalMaterial>, int> Votes;

	const FVector* Vert0 = &Vertices[0];
	const FVector* Vert1 = &Vertices[1];

	for (int32 VertexIdx = 2; VertexIdx < Vertices.Num(); ++VertexIdx)
	{
		const FVector* Vert2 = &Vertices[VertexIdx];

		FVector e0 = *Vert1 - *Vert0;
		FVector e1 = *Vert2 - *Vert0;

		float d00 = FVector::DotProduct(e0, e0);
		float d01 = FVector::DotProduct(e0, e1);
		float d10 = FVector::DotProduct(e1, e0);
		float d11 = FVector::DotProduct(e1, e1);
		float denom = d00 * d11 - d01 * d01;

		// n defined such that the normal faces inwards.
		FVector n = FVector::CrossProduct(e1, e0);
		n.Normalize();

		for (int i = 0; i < Num; ++i)
		{
			const FVector& pt = Points[i];
			const FVector& norm = Normals[i];

			// We want some amount of agreement between the hit normal and the triangle normal.
			if (FVector::DotProduct(n, norm) < kNormalAgreement)
				continue;

			// Init tally to 0 if the normal points the right way.
			int Tally = 0;

			//project point on to triangle.
			float proj = FVector::DotProduct(n, pt - *Vert0);

			FVector pt_proj = pt - proj * n;
			FVector vToPt = pt_proj - *Vert0;

			float d20 = FVector::DotProduct(vToPt, e0);
			float d21 = FVector::DotProduct(vToPt, e1);

			// convert to barycentric coords to see if the point projects into the triangle.
			float u = (d00 * d21 - d01 * d20) / denom;
			if (u > 0.f && u < 1.f)
			{
				float v = (d11 * d20 - d01 * d21) / denom;
				if (v > 0.f && v < 1.f)
				{
					if (u + v < 1.f)
					{
						// Assign another point to the surface if the point projects into the triangle
						Tally++;
					}
				}
			}

			int* Count = Votes.Find(Materials[i]);
			if (Count == nullptr)
			{
				Count = &Votes.Add(Materials[i]);
				*Count = 0;
			}

			if (Count != nullptr)
			{
				*Count += Tally;
			}
		}

		Vert1 = Vert2;
	}

	// Tally the votes
	if (Votes.Num() > 0)
	{
		auto MaxVotes = *Votes.begin();
		auto it = Votes.begin();
		++it;

		while (it != Votes.end())
		{
			if (it->Value > MaxVotes.Value)
				MaxVotes = *it;

			++it;
		}

		// Return the material with the max number of points.
		return MaxVotes.Key;
	}

	return nullptr;
}

void UAkSurfaceReflectorSetComponent::AssignAcousticTexturesFromSamples(const TArray<FVector>& Points, const TArray<FVector>& Normals, const TArray< TWeakObjectPtr<class UPhysicalMaterial> >& Materials, int Num)
{
	check(Points.Num() == Materials.Num());

	FTransform ToWorld = GetOwner()->ActorToWorld();

	for (int32 NodeIdx = 0; NodeIdx < ParentBrush->Nodes.Num(); ++NodeIdx)
	{
		AcousticPolys[NodeIdx].EnableSurface = false;

		if (ParentBrush->Nodes[NodeIdx].NumVertices > 2)
		{
			TArray<FVector> WorldVertices;

			int32 VertStartIndex = ParentBrush->Nodes[NodeIdx].iVertPool;

			for (int32 VertIdx = 0; VertIdx < ParentBrush->Nodes[NodeIdx].NumVertices; ++VertIdx)
			{
				WorldVertices.Emplace(ToWorld.TransformPosition(FVector(ParentBrush->Points[ParentBrush->Verts[VertStartIndex + VertIdx].pVertex])));
			}

			TWeakObjectPtr<UPhysicalMaterial> Material = AssignPolygonTexturesFromSamples(WorldVertices, Points, Normals, Materials, Num);

			if (Material.IsValid())
			{
				GetDefault<UAkSettings>()->GetAssociatedAcousticTexture(Material.Get(), AcousticPolys[NodeIdx].Texture);
				GetDefault<UAkSettings>()->GetAssociatedOcclusionValue(Material.Get(), AcousticPolys[NodeIdx].Occlusion);
				AcousticPolys[NodeIdx].EnableSurface = true;
			}
		}
		if (AcousticPolys[NodeIdx].Texture != nullptr)
			RegisterTextureParamChangeCallback(AcousticPolys[NodeIdx].Texture->ID);
	}

	OnRefreshDetails.ExecuteIfBound();
	// Update text visualizers.
	SkipNextTexturesUpdate();
	SchedulePolysUpdate();
}

#endif
