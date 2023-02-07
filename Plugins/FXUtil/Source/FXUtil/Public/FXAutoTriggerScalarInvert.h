#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarSingleParam.h"
#include "FXAutoTriggerScalarInvert.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarInvert : public UFXAutoTriggerScalarSingleParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DivideByZero;
    
    UFXAutoTriggerScalarInvert();
};

