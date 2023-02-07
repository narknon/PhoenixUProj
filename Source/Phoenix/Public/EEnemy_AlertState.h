#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AlertState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AlertState : uint8 {
    None,
    AlertStart,
    Face,
    Idle,
    Move,
    StoreWeapon,
    LoseTarget,
    EEnemy_MAX UMETA(Hidden),
};

