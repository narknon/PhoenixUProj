#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionObjectStateScratchpad.generated.h"

class UObjectStateInfo;

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionObjectStateScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* ObjectStateInfo;
    
    UAblBranchConditionObjectStateScratchpad();
};

