#pragma once
#include "CoreMinimal.h"
#include "EEnemyMovementState.generated.h"

UENUM(BlueprintType)
enum class EEnemyMovementState : uint8 {
    Stop,
    Walk,
    Jog,
    Gallop,
    Num,
};

