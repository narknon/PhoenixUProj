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
	AkDrawPortalComponent.cpp:
=============================================================================*/
#include "AkDrawPortalComponent.h"

#if WITH_EDITOR
#include "DynamicMeshBuilder.h"
#include "AkRoomComponent.h"
#include "AkSpatialAudioDrawUtils.h"
#include "AkSettings.h"
#endif // WITH_EDITOR

UDrawPortalComponent::UDrawPortalComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

#if WITH_EDITOR
const UAkPortalComponent* UDrawPortalComponent::GetPortalParent() const
{
	return Cast<UAkPortalComponent>(GetAttachParent());
}

void UDrawPortalComponent::DrawPortalOutline(const FSceneView* View, FPrimitiveDrawInterface* PDI, FMeshElementCollector& Collector, int32 ViewIndex) const
{
	const UAkPortalComponent* PortalComponent = GetPortalParent();
	if (IsValid(PortalComponent) && IsValid(PortalComponent->GetPrimitiveParent()))
	{
		const UPrimitiveComponent* PrimitiveParent = Cast<UPrimitiveComponent>(PortalComponent->GetPrimitiveParent());
		if (PrimitiveParent == nullptr)
			return;
		// Calculate the unscaled, unrotated box extent of the primitive parent component, at origin.
		FVector BoxExtent = PrimitiveParent->CalcBounds(FTransform()).BoxExtent;
		FLinearColor FrontDrawColor;
		FLinearColor BackDrawColor;
		AkSpatialAudioColors::GetPortalColors(PortalComponent, FrontDrawColor, BackDrawColor);
		FLinearColor OutlineColor = AkSpatialAudioColors::GetPortalOutlineColor(PortalComponent);

		float Thickness = AkDrawConstants::PortalOutlineThickness;
		FTransform T = PrimitiveParent->GetComponentTransform();
		AkDrawBounds DrawBounds(T, BoxExtent);

		/** Draw outline of 'front' (positive X) on portal */
		PDI->DrawLine(DrawBounds.RU(), DrawBounds.FRU(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FRU(), DrawBounds.FRD(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FRD(), DrawBounds.RD(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.LU(), DrawBounds.FLU(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FLU(), DrawBounds.FLD(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FLD(), DrawBounds.LD(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FRU(), DrawBounds.FLU(), FrontDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.FRD(), DrawBounds.FLD(), FrontDrawColor, SDPG_Foreground, Thickness);
		/** Draw outline of 'back' (negative X) on portal */
		PDI->DrawLine(DrawBounds.RU(), DrawBounds.BRU(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BRU(), DrawBounds.BRD(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BRD(), DrawBounds.RD(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.LU(), DrawBounds.BLU(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BLU(), DrawBounds.BLD(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BLD(), DrawBounds.LD(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BLU(), DrawBounds.BRU(), BackDrawColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.BLD(), DrawBounds.BRD(), BackDrawColor, SDPG_Foreground, Thickness);
		/** Draw outline around centre of portal (YZ plane) */
		PDI->DrawLine(DrawBounds.LU(), DrawBounds.LD(), OutlineColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.LD(), DrawBounds.RD(), OutlineColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.RD(), DrawBounds.RU(), OutlineColor, SDPG_Foreground, Thickness);
		PDI->DrawLine(DrawBounds.RU(), DrawBounds.LU(), OutlineColor, SDPG_Foreground, Thickness);

		UWorld* world = GetWorld();
		if (world != nullptr)
		{
			EWorldType::Type worldType = world->WorldType;
			if (!(worldType == EWorldType::Game || worldType == EWorldType::PIE) && PortalComponent->InitialState == AkAcousticPortalState::Closed ||
				(worldType == EWorldType::Game || worldType == EWorldType::PIE) && PortalComponent->GetCurrentState() == AkAcousticPortalState::Closed)
			{
				PDI->DrawLine(DrawBounds.FRU(), DrawBounds.BRD(), FrontDrawColor, SDPG_Foreground, Thickness);
				PDI->DrawLine(DrawBounds.FLD(), DrawBounds.BLU(), BackDrawColor, SDPG_Foreground, Thickness);
			}
		}

		Thickness = AkDrawConstants::PortalRoomConnectionThickness;

		FVector FrontPoint = FVector(BoxExtent.X, 0.0f, 0.0f);
		FVector BackPoint = FVector(-BoxExtent.X, 0.0f, 0.0f);
		if (PortalComponent->GetFrontRoomComponent() != nullptr && PortalComponent->GetFrontRoomComponent()->GetPrimitiveParent() != nullptr)
		{
			FVector From = PrimitiveParent->GetComponentTransform().TransformPosition(FrontPoint);
			FVector To = PortalComponent->GetFrontRoomComponent()->GetPrimitiveParent()->GetComponentTransform().TransformPosition(FVector(0.0f, 0.0f, 0.0f));
			PDI->DrawLine(From, To, OutlineColor, SDPG_Foreground, Thickness);
		}
		if (PortalComponent->GetBackRoomComponent() != nullptr && PortalComponent->GetBackRoomComponent()->GetPrimitiveParent() != nullptr)
		{
			FVector From = PrimitiveParent->GetComponentTransform().TransformPosition(BackPoint);
			FVector To = PortalComponent->GetBackRoomComponent()->GetPrimitiveParent()->GetComponentTransform().TransformPosition(FVector(0.0f, 0.0f, 0.0f));
			PDI->DrawLine(From, To, OutlineColor, SDPG_Foreground, Thickness);
		}
	}
}

/** Represents a portal to the scene manager. 
	Based on FDrawFrustumSceneProxy (in DrawFrustrumComponent.cpp)
*/
class FDrawPortalSceneProxy final : public FPrimitiveSceneProxy
{
public:
	/** Based on FDrawFrustumSceneProxy implementation */
	SIZE_T GetTypeHash() const override
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}

	/**
	* Initialization constructor.
	* @param	InComponent - game component to draw in the scene
	*/
	FDrawPortalSceneProxy(const UDrawPortalComponent* InComponent)
		: FPrimitiveSceneProxy(InComponent)
		, PortalDrawer(InComponent)
	{}

	// FPrimitiveSceneProxy interface.

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
	{
		if (GetDefault<UAkSettings>()->VisualizeRoomsAndPortals)
		{
			if (PortalDrawer != nullptr)
			{
				for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
				{
					if (VisibilityMap & (1 << ViewIndex))
					{
						FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);
						const FSceneView* View = Views[ViewIndex];
						PortalDrawer->DrawPortalOutline(View, PDI, Collector, ViewIndex);
					}
				}
			}
		}
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance Result;
		Result.bDrawRelevance = IsShown(View);
		Result.bDynamicRelevance = true;
		Result.bStaticRelevance = true;
		Result.bEditorNoDepthTestPrimitiveRelevance = true;
		return Result;
	}

	/** Based on FDrawFrustumSceneProxy implementation */
	virtual uint32 GetMemoryFootprint(void) const override { return(sizeof(*this) + GetAllocatedSize()); }
	uint32 GetAllocatedSize(void) const { return(FPrimitiveSceneProxy::GetAllocatedSize()); }

private:
	const UDrawPortalComponent* PortalDrawer;
};


FPrimitiveSceneProxy* UDrawPortalComponent::CreateSceneProxy()
{
	return new FDrawPortalSceneProxy(this);
}

FBoxSphereBounds UDrawPortalComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	return FBoxSphereBounds(LocalToWorld.TransformPosition(FVector::ZeroVector), FVector(AkDrawConstants::CullDepth), AkDrawConstants::CullDepth);
}

#endif // WITH_EDITOR