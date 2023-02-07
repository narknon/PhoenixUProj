#pragma once
#include "CoreMinimal.h"
#include "EEnemy_IdleType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_IdleType : uint8 {
    None,
    Taunt,
    Shuffle,
    IdleBreak,
    Idle,
    Count,
    EEnemy_MAX UMETA(Hidden),
};

