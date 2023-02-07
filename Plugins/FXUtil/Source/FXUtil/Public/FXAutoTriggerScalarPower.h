#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarSingleParam.h"
#include "FXAutoTriggerScalarPower.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarPower : public UFXAutoTriggerScalarSingleParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Power;
    
    UFXAutoTriggerScalarPower();
};

