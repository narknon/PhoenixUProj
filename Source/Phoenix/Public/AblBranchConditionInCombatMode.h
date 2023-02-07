#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionInCombatMode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionInCombatMode : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckDelayedState;
    
public:
    UAblBranchConditionInCombatMode();
};

