#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDistanceMetersInterpolant.h"
#include "LerpVolumeDistanceToCeilingInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDistanceToCeilingInterpolant : public ULerpVolumeDistanceMetersInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDistanceToCeilingInterpolant();
};

