#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumeLevelNameInterpolantBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeLevelNameInterpolantBase : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeLevelNameInterpolantBase();
};

