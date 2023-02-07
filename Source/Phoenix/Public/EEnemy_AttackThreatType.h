#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackThreatType : uint8 {
    None,
    Melee,
    Munition,
    Weapon,
    Ranged,
    Buf,
    Spawn,
    Custom,
    Ballistic,
    RunTo,
    EEnemy_MAX UMETA(Hidden),
};

