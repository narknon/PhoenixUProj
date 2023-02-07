#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumeFinalInterpolant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeFinalInterpolant();
};

