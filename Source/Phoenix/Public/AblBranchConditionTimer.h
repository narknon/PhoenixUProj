#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionTimer.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionTimer : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CountdownTime;
    
public:
    UAblBranchConditionTimer();
};

