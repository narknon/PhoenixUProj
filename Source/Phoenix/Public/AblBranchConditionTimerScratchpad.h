#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionTimerScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionTimerScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UAblBranchConditionTimerScratchpad();
};

