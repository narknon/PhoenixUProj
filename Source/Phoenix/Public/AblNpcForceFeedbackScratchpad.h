#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblNpcForceFeedbackScratchpad.generated.h"

class UAblTaskConditionScratchpad;

UCLASS(Blueprintable, NonTransient)
class UAblNpcForceFeedbackScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> ConditionScratchpads;
    
    UAblNpcForceFeedbackScratchpad();
};

