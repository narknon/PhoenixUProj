#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionUseStairs.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionUseStairs : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AllowableAngleRange;
    
public:
    UAblBranchConditionUseStairs();
};

