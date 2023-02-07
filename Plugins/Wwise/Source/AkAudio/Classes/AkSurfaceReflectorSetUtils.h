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

#pragma once
#include "AkAcousticTexture.h"
#include "AkSurfaceReflectorSetUtils.generated.h"

namespace AkSurfaceReflectorUtils
{
	static float EQUALITY_THRESHOLD = 0.001f;
}

/** An edge between two vertices */
USTRUCT()
struct FAkSurfaceEdgeVerts
{
	GENERATED_BODY()
	static bool EdgesShareVertex(const FAkSurfaceEdgeVerts& Edge1, const FAkSurfaceEdgeVerts& Edge2);

	FAkSurfaceEdgeVerts() {}
	FAkSurfaceEdgeVerts(FVector InV0, FVector InV1) : V0(InV0), V1(InV1) {}
	FVector V0 = FVector::ZeroVector;
	FVector V1 = FVector::ZeroVector;

	FVector GetUnitVector() const { return (V1 - V0).GetSafeNormal(); }

	FAkSurfaceEdgeVerts GetTransformedEdge(const FTransform& Transform) const;
	void TransformEdge(const FTransform& Transform);
	void Invert();
};

/** Information about an edge */
USTRUCT()
struct FAkSurfaceEdgeInfo
{
	GENERATED_BODY()
	FAkSurfaceEdgeVerts EdgeVerts;
	FVector Normal;
	bool IsEnabled = true;
	bool IsBoundary = true;
	bool IsFlat = false;

	const FVector V0() const { return EdgeVerts.V0; }
	const FVector V1() const { return EdgeVerts.V1; }

	void SetV0(FVector V0) { EdgeVerts.V0 = V0; }
	void SetV1(FVector V1) { EdgeVerts.V1 = V1; }

	int64 GetHash()
	{
		int64 H0 = GetTypeHash(V0());
		int64 H1 = GetTypeHash(V1());
		if (H1 > H0)
		{
			int64 temp = H0;
			H0 = H1;
			H1 = temp;
		}
		return H1 << 32 | H0;
	}

	FAkSurfaceEdgeInfo();
	FAkSurfaceEdgeInfo(FVector InV0, FVector InV1);
};

/** Contains the properties of a face from the ParentBrush of a UAkSurfaceReflectorSetComponent. */
USTRUCT(BlueprintType)
struct FAkSurfacePoly
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkSurfaceReflectorSet")
	UAkAcousticTexture* Texture = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkSurfaceReflectorSet", DisplayName = "Transmission Loss", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Occlusion = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkSurfaceReflectorSet")
	bool EnableSurface = true;

	void SetSurfaceArea(float area) { SurfaceArea = area; }
	float GetSurfaceArea() const { return SurfaceArea; }

#if WITH_EDITOR
	FVector Normal;
	FVector MidPoint;
	/* The edges of the polygon */
	TArray<FAkSurfaceEdgeVerts> Edges;
	/* Keeps track of the optimal dot product between the chosen up vector and view camera up vector.
		This is used to minimize the flickering of text as it switches between edges each frame. */
	mutable float OptimalEdgeDP = 0.0f;

	void ClearEdgeInfo();

	FText GetPolyText(bool includeOcclusion) const;
#endif

private:
	UPROPERTY()
	float SurfaceArea = 0.0f;
};
