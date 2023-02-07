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
	AkSpatialAudioDrawUtils.h:
=============================================================================*/
#pragma once

#if WITH_EDITOR

#include "CoreMinimal.h"
#include "AkAudioDevice.h"

namespace AkDrawConstants
{
	const float CullDepth = 100.0f;
	const float PortalOutlineThickness = 5.0f;
	const float PortalRoomConnectionThickness = 1.0f;
	const float RoomIconThickness = 2.0f;
	const float RoomIconRadius = 10.0f;
	const int	RoomIconSides = 16;
	const float RoomAxisLength = 30.0f;
	const float RoomAxisThickness = 1.0f;
	const float RoomOutlineThickness = 1.0f; // Slightly thicker lines for spatial audio volumes when surface reflectors are disabled, since they are less visible.
	const float SpatialAudioVolumeOutlineThickness = 0.2f; // Shows the outline of disabled surfaces and non-diffraction edges.
	const float RadialEmitterThickness = 2.0f;
	const float DiffractionEdgeThickness = 2.5f;
}

/** A utility struct to transfom the points on a local axis-aligned bounding box to world space using the given transform.
	Used for drawing rotated bounding boxes around portals.
*/
struct AKAUDIO_API AkDrawBounds
{
	AkDrawBounds(const FTransform& T, const FVector& Extent);

private:
	const FTransform& Transform;
	const FVector& BoxExtent;

public:
	/** FrontRightUp */		FVector FRU();
	/** BackLeftDown */		FVector BLD();
	/** FrontLeftDown */	FVector FLD();
	/** BackRightUp */		FVector BRU();
	/** FrontLeftDown */	FVector FLU();
	/** BackLeftUp */		FVector BLU();
	/** FrontRightDown */	FVector FRD();
	/** BackRightDown */	FVector BRD();
	/** RightUp */			FVector RU();
	/** LeftUp */			FVector LU();
	/** RightDown */		FVector RD();
	/** LeftDown */			FVector LD();
};

class UAkPortalComponent;
class UAkSurfaceReflectorSetComponent;
namespace AkSpatialAudioColors
{
	AKAUDIO_API void GetPortalColors(const UAkPortalComponent* Portal, FLinearColor& FrontColor, FLinearColor& BackColor);
	AKAUDIO_API FLinearColor GetPortalOutlineColor(const UAkPortalComponent* Portal);
	AKAUDIO_API FLinearColor GetRoomColor();
	AKAUDIO_API FLinearColor GetRadialEmitterOutlineColor();
	AKAUDIO_API FLinearColor GetRadialEmitterColor();
	AKAUDIO_API float GetRadialEmitterOuterOpacity();
	AKAUDIO_API float GetRadialEmitterInnerOpacity();
	AKAUDIO_API FLinearColor GetSurfaceReflectorColor(const UAkSurfaceReflectorSetComponent* SurfaceReflectorSet, int NodeIdx, bool IsDragging);
	AKAUDIO_API FLinearColor GetSpatialAudioVolumeOutlineColor();
	AKAUDIO_API FLinearColor GetBadFitSpatialAudioVolumeOutlineColor();
	AKAUDIO_API FLinearColor GetDiffractionEdgeColor();
	AKAUDIO_API FLinearColor GetBoundaryDiffractionEdgeColor();
}

#endif // WITH_EDITOR
