#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDynamicUnitDirectionInterpolant.h"
#include "LerpVolumeDiretionToWallInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDiretionToWallInterpolant : public ULerpVolumeDynamicUnitDirectionInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDiretionToWallInterpolant();
};

