#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblAddPassiveReactionScratchpad.generated.h"

class UAblTaskConditionScratchpad;

UCLASS(Blueprintable, NonTransient)
class UAblAddPassiveReactionScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> TaskConditionScratchpads;
    
    UAblAddPassiveReactionScratchpad();
};

