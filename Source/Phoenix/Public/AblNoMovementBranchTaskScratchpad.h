#pragma once
#include "CoreMinimal.h"
#include "AblBranchTaskScratchPad.h"
#include "AblNoMovementBranchTaskScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblNoMovementBranchTaskScratchpad : public UAblBranchTaskScratchPad {
    GENERATED_BODY()
public:
    UAblNoMovementBranchTaskScratchpad();
};

