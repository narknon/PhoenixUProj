#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerScalarConstantTrue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarConstantTrue : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UFXAutoTriggerScalarConstantTrue();
};

