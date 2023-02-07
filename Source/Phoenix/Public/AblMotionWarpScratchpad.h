#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblMotionWarpScratchpad.generated.h"

class UAblTaskConditionScratchpad;

UCLASS(Blueprintable, NonTransient)
class UAblMotionWarpScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskConditionScratchpad*> BranchConditionScratchpads;
    
    UAblMotionWarpScratchpad();
};

