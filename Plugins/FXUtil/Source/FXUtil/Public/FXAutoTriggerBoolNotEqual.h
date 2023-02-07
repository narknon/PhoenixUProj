#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolTwoScalarParams.h"
#include "FXAutoTriggerBoolNotEqual.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolNotEqual : public UFXAutoTriggerBoolTwoScalarParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UFXAutoTriggerBoolNotEqual();
};

