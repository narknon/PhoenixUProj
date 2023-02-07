#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolScalarParam.h"
#include "FXAutoTriggerBoolLessThanZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolLessThanZero : public UFXAutoTriggerBoolScalarParam {
    GENERATED_BODY()
public:
    UFXAutoTriggerBoolLessThanZero();
};

