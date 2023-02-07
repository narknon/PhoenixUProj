#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarSingleParam.h"
#include "FXAutoTriggerScalarMinConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarMinConstant : public UFXAutoTriggerScalarSingleParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Minimum;
    
    UFXAutoTriggerScalarMinConstant();
};

