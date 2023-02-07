#pragma once
#include "CoreMinimal.h"
#include "EEnemyAITargetPerceiveState.generated.h"

UENUM(BlueprintType)
enum class EEnemyAITargetPerceiveState : uint8 {
    None,
    Gather,
    Evaluate,
};

