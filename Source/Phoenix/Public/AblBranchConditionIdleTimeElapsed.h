#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionIdleTimeElapsed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionIdleTimeElapsed : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeElapsed;
    
public:
    UAblBranchConditionIdleTimeElapsed();
};

