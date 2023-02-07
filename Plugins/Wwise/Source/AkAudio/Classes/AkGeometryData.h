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
	AkGeometryData.h:
=============================================================================*/
#pragma once
#include <AkInclude.h>

#include "AkAcousticTexture.h"

#include "AkGeometryData.generated.h"

USTRUCT()
struct FAkAcousticSurface
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint32 Texture = AK_INVALID_UNIQUE_ID;

	UPROPERTY(DisplayName = "Transmission Loss")
	float Occlusion;

	UPROPERTY()
	FString Name;
};

USTRUCT()
struct FAkTriangle
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint16 Point0;

	UPROPERTY()
	uint16 Point1;

	UPROPERTY()
	uint16 Point2;

	UPROPERTY()
	uint16 Surface;
};

USTRUCT()
struct FAkGeometryData
{
	GENERATED_USTRUCT_BODY()

	void Clear()
	{
		Vertices.Empty();
		Surfaces.Empty();
		Triangles.Empty();
		ToOverrideAcousticTexture.Empty();
		ToOverrideOcclusion.Empty();
	}

	UPROPERTY()
	TArray<FVector> Vertices;

	UPROPERTY()
	TArray<FAkAcousticSurface> Surfaces;

	UPROPERTY()
	TArray<FAkTriangle> Triangles;

	UPROPERTY()
	TArray<UPhysicalMaterial*> ToOverrideAcousticTexture;

	UPROPERTY(DisplayName = "To Override Transmission Loss")
	TArray<UPhysicalMaterial*> ToOverrideOcclusion;

	void AddBox(AkSurfIdx surfIdx, FVector center, FVector extent, FRotator rotation);
	void AddSphere(AkSurfIdx surfIdx, const FVector& Center, const float Radius, int32 NumSides, int32 NumRings);
	void AddCapsule(AkSurfIdx surfIdx, const FVector& Origin, const FVector& XAxis, const FVector& YAxis, const FVector& ZAxis, float Radius, float HalfHeight, int32 NumSides);
};