#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceMetersInterpolant.h"
#include "LerpVolumeDistanceFromCenterXYInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceFromCenterXYInterpolant : public ULerpVolumeDistanceMetersInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceFromCenterXYInterpolant();
};

