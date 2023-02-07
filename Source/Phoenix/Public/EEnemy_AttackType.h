#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackType : uint8 {
    None,
    Ranged,
    Melee,
    Buf,
    Spawn,
    Custom,
    Ballistic,
    RunTo,
    EEnemy_MAX UMETA(Hidden),
};

