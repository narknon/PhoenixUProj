#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceMetersInterpolant.h"
#include "LerpVolumeDistanceToFloorInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceToFloorInterpolant : public ULerpVolumeDistanceMetersInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceToFloorInterpolant();
};

