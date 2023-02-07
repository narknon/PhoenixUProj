#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionWaterDepth.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionWaterDepth : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GreaterThanWaterDepth;
    
public:
    UAblBranchConditionWaterDepth();
};

