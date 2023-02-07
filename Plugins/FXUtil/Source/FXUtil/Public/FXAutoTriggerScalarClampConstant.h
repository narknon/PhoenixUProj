#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarSingleParam.h"
#include "FXAutoTriggerScalarClampConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarClampConstant : public UFXAutoTriggerScalarSingleParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Minimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Maximum;
    
    UFXAutoTriggerScalarClampConstant();
};

