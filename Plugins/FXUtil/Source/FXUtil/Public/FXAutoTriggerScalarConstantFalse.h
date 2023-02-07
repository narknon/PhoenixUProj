#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerScalarConstantFalse.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarConstantFalse : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UFXAutoTriggerScalarConstantFalse();
};

