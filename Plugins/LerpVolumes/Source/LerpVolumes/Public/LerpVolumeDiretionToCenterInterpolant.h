#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDynamicUnitDirectionInterpolant.h"
#include "LerpVolumeDiretionToCenterInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDiretionToCenterInterpolant : public ULerpVolumeDynamicUnitDirectionInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeDiretionToCenterInterpolant();
};

