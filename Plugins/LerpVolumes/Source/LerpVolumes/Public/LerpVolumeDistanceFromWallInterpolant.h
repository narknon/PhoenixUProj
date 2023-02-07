#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceMetersInterpolant.h"
#include "LerpVolumeDistanceFromWallInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceFromWallInterpolant : public ULerpVolumeDistanceMetersInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceFromWallInterpolant();
};

