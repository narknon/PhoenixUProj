#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Abort.generated.h"

UENUM(BlueprintType)
enum class EEnemy_Abort : uint8 {
    None,
    AUS,
    Move,
    Idle,
    MoveCollision,
    MoveCorridor,
    Count,
    EEnemy_MAX UMETA(Hidden),
};

