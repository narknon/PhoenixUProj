#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolTwoScalarParams.h"
#include "FXAutoTriggerBoolEqual.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolEqual : public UFXAutoTriggerBoolTwoScalarParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UFXAutoTriggerBoolEqual();
};

