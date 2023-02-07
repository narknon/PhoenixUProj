#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceFromWallInterpolant.h"
#include "LerpVolumeDistanceFromOppositeWallInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceFromOppositeWallInterpolant : public ULerpVolumeDistanceFromWallInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceFromOppositeWallInterpolant();
};

