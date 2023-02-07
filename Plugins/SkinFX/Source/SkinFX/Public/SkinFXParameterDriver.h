#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SkinFXParameterDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SKINFX_API USkinFXParameterDriver : public UObject {
    GENERATED_BODY()
public:
    USkinFXParameterDriver();
};

