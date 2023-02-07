#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDynamicTagInterpolant.h"
#include "LerpVolumeNameTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeNameTagInterpolant : public ULerpVolumeDynamicTagInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeNameTagInterpolant();
};

