#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterDriver.h"
#include "SkinFXParameterDriverEndEffect.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterDriverEndEffect : public USkinFXParameterDriver {
    GENERATED_BODY()
public:
    USkinFXParameterDriverEndEffect();
};

