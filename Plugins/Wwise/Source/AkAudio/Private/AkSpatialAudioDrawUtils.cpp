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
	AkSpatialAudioDrawUtils.cpp:
=============================================================================*/
#include "AkSpatialAudioDrawUtils.h"

#if WITH_EDITOR

#include "AkAcousticPortal.h"
#include "AkSpatialAudioVolume.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "Classes/EditorStyleSettings.h"

AkDrawBounds::AkDrawBounds(const FTransform& T, const FVector& Extent) : Transform(T), BoxExtent(Extent) {}

FVector AkDrawBounds::FRU() { return Transform.TransformPosition(BoxExtent); }
FVector AkDrawBounds::BLD() { return Transform.TransformPosition(-BoxExtent); }
FVector AkDrawBounds::FLD() { return Transform.TransformPosition(FVector(BoxExtent.X, -BoxExtent.Y, -BoxExtent.Z)); }
FVector AkDrawBounds::BRU() { return Transform.TransformPosition(FVector(-BoxExtent.X, BoxExtent.Y, BoxExtent.Z)); }
FVector AkDrawBounds::FLU() { return Transform.TransformPosition(FVector(BoxExtent.X, -BoxExtent.Y, BoxExtent.Z)); }
FVector AkDrawBounds::BLU() { return Transform.TransformPosition(FVector(-BoxExtent.X, -BoxExtent.Y, BoxExtent.Z)); }
FVector AkDrawBounds::FRD() { return Transform.TransformPosition(FVector(BoxExtent.X, BoxExtent.Y, -BoxExtent.Z)); }
FVector AkDrawBounds::BRD() { return Transform.TransformPosition(FVector(-BoxExtent.X, BoxExtent.Y, -BoxExtent.Z)); }
FVector AkDrawBounds::RU() { return Transform.TransformPosition(FVector(0.0f, BoxExtent.Y, BoxExtent.Z)); }
FVector AkDrawBounds::LU() { return Transform.TransformPosition(FVector(0.0f, -BoxExtent.Y, BoxExtent.Z)); }
FVector AkDrawBounds::RD() { return Transform.TransformPosition(FVector(0.0f, BoxExtent.Y, -BoxExtent.Z)); }
FVector AkDrawBounds::LD() { return Transform.TransformPosition(FVector(0.0f, -BoxExtent.Y, -BoxExtent.Z)); }

namespace AkSpatialAudioColors
{	
	float kAlphaValue = 0.35f;
	float kDraggingAlphaValue = 0.05f;

	void GetPortalColors(const UAkPortalComponent* Portal, FLinearColor& FrontColor, FLinearColor& BackColor)
	{
		FLinearColor ConnectedColor = GetDefault<UEditorStyleSettings>()->SelectionColor;
		FrontColor = ConnectedColor;
		BackColor = ConnectedColor;
		if (!Portal->PortalPlacementValid())
		{
			FLinearColor ErrorColor = FLinearColor::Red;
			FrontColor = ErrorColor;
			BackColor = ErrorColor;
		}
		else if (Portal->GetFrontRoomComponent() == nullptr)
		{
			FLinearColor DisconnectedColor = FLinearColor::Gray;
			FrontColor = DisconnectedColor;
		}
		else if (Portal->GetBackRoomComponent() == nullptr)
		{
			FLinearColor DisconnectedColor = FLinearColor::Gray;
			BackColor = DisconnectedColor;
		}
		FrontColor.A = kAlphaValue;
		BackColor.A = kAlphaValue;
	}

	FLinearColor GetPortalOutlineColor(const UAkPortalComponent* Portal)
	{
		FLinearColor OutlineColor = GetDefault<UEditorStyleSettings>()->SelectionColor;
		if (false == Portal->PortalPlacementValid())
		{
			OutlineColor = FLinearColor::Red;
			OutlineColor.A = 0.85f;
		}
		return OutlineColor;
	}
	
	FLinearColor GetRoomColor()
	{
		return GetDefault<UEditorStyleSettings>()->SelectionColor;
	}
	
	FLinearColor GetRadialEmitterOutlineColor()
	{
		return GetDefault<UEditorStyleSettings>()->SelectionColor;
	}

	FLinearColor GetRadialEmitterColor()
	{
		return GetRadialEmitterOutlineColor();
	}

	float GetRadialEmitterInnerOpacity() { return kAlphaValue; }

	float GetRadialEmitterOuterOpacity() { return kAlphaValue * 0.15f; }

	FLinearColor GetSurfaceReflectorColor(const UAkSurfaceReflectorSetComponent* SurfaceReflectorSet, int NodeIdx, bool IsDragging)
	{
		const FLinearColor DefaultColor(FColor(0x4280AF));

		FLinearColor Color = FLinearColor::Gray;

		FAkSurfacePoly AcousticProperties = SurfaceReflectorSet->AcousticPolys[NodeIdx];
		if (AcousticProperties.EnableSurface)
		{
			Color = DefaultColor;

			if (AcousticProperties.Texture != nullptr)
			{
				Color = AcousticProperties.Texture->EditColor;
			}
		}

		Color.A = IsDragging ? kDraggingAlphaValue : kAlphaValue;

		return Color;
	}

	FLinearColor GetSpatialAudioVolumeOutlineColor()
	{
		return GetDefault<UEditorStyleSettings>()->SelectionColor;
	}

	FLinearColor GetBadFitSpatialAudioVolumeOutlineColor()
	{
		return FLinearColor::Red;
	}

	FLinearColor GetDiffractionEdgeColor()
	{
		return FLinearColor(FColor(0x09558F));
	}

	FLinearColor GetBoundaryDiffractionEdgeColor()
	{
		return FLinearColor(FColor(0x480D97));
	}
}

#endif // WITH_EDITOR
