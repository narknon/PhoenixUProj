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
	AkDrawRoomComponent.cpp:
=============================================================================*/
#include "AkDrawRoomComponent.h"

#if WITH_EDITOR
#include "DynamicMeshBuilder.h"
#include "AkRoomComponent.h"
#include "AkSpatialAudioDrawUtils.h"
#include "SceneManagement.h"
#include "AkSettings.h"
#endif // WITH_EDITOR

UDrawRoomComponent::UDrawRoomComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

#if WITH_EDITOR
const UAkRoomComponent* UDrawRoomComponent::GetRoomParent() const
{
	return Cast<UAkRoomComponent>(GetAttachParent());
}

void UDrawRoomComponent::DrawRoom(const FSceneView* View, FPrimitiveDrawInterface* PDI, FMeshElementCollector& Collector, int32 ViewIndex) const
{
	const UAkRoomComponent* RoomComponent = GetRoomParent();
	if (IsValid(RoomComponent) && IsValid(RoomComponent->GetPrimitiveParent()))
	{
		const UPrimitiveComponent* PrimitiveParent = Cast<UPrimitiveComponent>(RoomComponent->GetPrimitiveParent());
		if (PrimitiveParent == nullptr)
			return;
		// Calculate the unscaled, unrotated box extent of the primitive parent component, at origin.
		FVector BoxExtent = PrimitiveParent->CalcBounds(FTransform()).BoxExtent;
		FLinearColor RoomColor = AkSpatialAudioColors::GetRoomColor();

		FTransform T = PrimitiveParent->GetComponentTransform();
		AkDrawBounds DrawBounds(T, BoxExtent);

		// Calculate the local room axis vectors
		FVector RoomAxisForward = DrawBounds.FRU() - DrawBounds.BRU();
		RoomAxisForward.Normalize();
		FVector RoomAxisRight = DrawBounds.RU() - DrawBounds.LU();
		RoomAxisRight.Normalize();
		FVector RoomAxisUp = DrawBounds.RU() - DrawBounds.RD();
		RoomAxisUp.Normalize();

		// Draw an icon representing the room's orientation.
		float Radius = AkDrawConstants::RoomIconRadius;
		float IconThickness = AkDrawConstants::RoomIconThickness;
		int Sides = AkDrawConstants::RoomIconSides;

		FVector RoomCentre = T.TransformPosition(FVector::ZeroVector);
		DrawCircle(PDI, RoomCentre, RoomAxisForward, RoomAxisRight, RoomColor, Radius, Sides, SDPG_Foreground, IconThickness);
		DrawCircle(PDI, RoomCentre, RoomAxisForward, RoomAxisUp, RoomColor, Radius, Sides, SDPG_Foreground, IconThickness);

		float AxisLength = AkDrawConstants::RoomAxisLength;
		PDI->DrawLine(RoomCentre, RoomCentre + RoomAxisForward * AxisLength, RoomColor, SDPG_Foreground, AkDrawConstants::RoomAxisThickness);
		PDI->DrawLine(RoomCentre, RoomCentre + RoomAxisRight * AxisLength, RoomColor, SDPG_Foreground, AkDrawConstants::RoomAxisThickness);
		PDI->DrawLine(RoomCentre, RoomCentre + RoomAxisUp * AxisLength, RoomColor, SDPG_Foreground, AkDrawConstants::RoomAxisThickness);
	}
}

/** Represents a Room to the scene manager.
	Based on FDrawFrustumSceneProxy (in DrawFrustrumComponent.cpp)
*/
class FDrawRoomSceneProxy final : public FPrimitiveSceneProxy
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
	FDrawRoomSceneProxy(const UDrawRoomComponent* InComponent)
		: FPrimitiveSceneProxy(InComponent)
		, RoomDrawer(InComponent)
	{}

	// FPrimitiveSceneProxy interface.

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
	{
		if (GetDefault<UAkSettings>()->VisualizeRoomsAndPortals)
		{
			if (RoomDrawer != nullptr)
			{
				for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
				{
					if (VisibilityMap & (1 << ViewIndex))
					{
						FPrimitiveDrawInterface* PDI = Collector.GetPDI(ViewIndex);
						const FSceneView* View = Views[ViewIndex];
						RoomDrawer->DrawRoom(View, PDI, Collector, ViewIndex);
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
	const UDrawRoomComponent* RoomDrawer;
};


FPrimitiveSceneProxy* UDrawRoomComponent::CreateSceneProxy()
{
	return new FDrawRoomSceneProxy(this);
}

FBoxSphereBounds UDrawRoomComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	return FBoxSphereBounds(LocalToWorld.TransformPosition(FVector::ZeroVector), FVector(AkDrawConstants::CullDepth), AkDrawConstants::CullDepth);
}

#endif // WITH_EDITOR