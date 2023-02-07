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

#include "AkSurfaceReflectorSetUtils.h"

#if WITH_EDITOR

FText FAkSurfacePoly::GetPolyText(bool includeOcclusion) const
{
	if (!EnableSurface)
		return FText();

	FString textureName = FString("None");

	if (Texture)
		textureName = Texture->GetName();

	if (!includeOcclusion)
		return FText::FromString(FString::Format(TEXT("{0}"), { textureName }));

	FNumberFormattingOptions NumberFormat;
	NumberFormat.MaximumFractionalDigits = 2;
	NumberFormat.MinimumFractionalDigits = 1;
	FString transmissionLossValueString = FText::AsNumber(Occlusion, &NumberFormat).ToString();
	return FText::FromString(FString::Format(TEXT("{0}{1}{2}"), { textureName, LINE_TERMINATOR, transmissionLossValueString }));
}

void FAkSurfacePoly::ClearEdgeInfo()
{
	Edges.Empty();
	OptimalEdgeDP = 0.0f;
}

#endif

bool FAkSurfaceEdgeVerts::EdgesShareVertex(const FAkSurfaceEdgeVerts& Edge1, const FAkSurfaceEdgeVerts& Edge2)
{
	return FMath::IsNearlyEqual(FVector::Dist(Edge1.V0, Edge2.V0), 0.0f, AkSurfaceReflectorUtils::EQUALITY_THRESHOLD)
		|| FMath::IsNearlyEqual(FVector::Dist(Edge1.V1, Edge2.V1), 0.0f, AkSurfaceReflectorUtils::EQUALITY_THRESHOLD);
}

FAkSurfaceEdgeVerts FAkSurfaceEdgeVerts::GetTransformedEdge(const FTransform& Transform) const
{
	return FAkSurfaceEdgeVerts(Transform.TransformPositionNoScale(V0), Transform.TransformPositionNoScale(V1));
}

void FAkSurfaceEdgeVerts::TransformEdge(const FTransform& Transform)
{
	V0 = Transform.TransformPositionNoScale(V0);
	V1 = Transform.TransformPositionNoScale(V1);
}

void FAkSurfaceEdgeVerts::Invert()
{
	FVector Temp = V0;
	V0 = V1;
	V1 = Temp;
}

FAkSurfaceEdgeInfo::FAkSurfaceEdgeInfo() {}
FAkSurfaceEdgeInfo::FAkSurfaceEdgeInfo(FVector InV0, FVector InV1) : EdgeVerts(InV0, InV1) {}