#pragma once
#include "CoreMinimal.h"
#include "EEnemyTakeAKneeAction.generated.h"

UENUM(BlueprintType)
enum class EEnemyTakeAKneeAction : uint8 {
    None,
    Defeat,
    Advance,
    Num,
};

