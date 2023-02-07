#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceMetersInterpolant.h"
#include "LerpVolumeDistanceFromCenterInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceFromCenterInterpolant : public ULerpVolumeDistanceMetersInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceFromCenterInterpolant();
};

