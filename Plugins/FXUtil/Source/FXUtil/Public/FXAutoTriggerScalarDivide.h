#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarTwoParams.h"
#include "FXAutoTriggerScalarDivide.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarDivide : public UFXAutoTriggerScalarTwoParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DivideByZero;
    
    UFXAutoTriggerScalarDivide();
};

