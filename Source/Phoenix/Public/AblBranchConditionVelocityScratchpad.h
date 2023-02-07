#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionVelocityScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionVelocityScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UAblBranchConditionVelocityScratchpad();
};

