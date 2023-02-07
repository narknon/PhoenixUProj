#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblNpcStartReactionScratchpad.generated.h"

class UAblTaskConditionScratchpad;

UCLASS(Blueprintable, NonTransient)
class UAblNpcStartReactionScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> TaskConditionScratchpads;
    
    UAblNpcStartReactionScratchpad();
};

