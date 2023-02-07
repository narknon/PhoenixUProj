#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblLeavingNavMeshScratchpad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblLeavingNavMeshScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UAblLeavingNavMeshScratchpad();
};

