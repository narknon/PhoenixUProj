#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblRootMotionModifiersScratchpad.generated.h"

class UAblTaskConditionScratchpad;

UCLASS(Blueprintable, NonTransient)
class UAblRootMotionModifiersScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> TaskConditionScratchpads;
    
    UAblRootMotionModifiersScratchpad();
};

