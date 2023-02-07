#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDynamicTagInterpolant.h"
#include "LerpVolumeMapLocationTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULerpVolumeMapLocationTagInterpolant : public ULerpVolumeDynamicTagInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeMapLocationTagInterpolant();
};

