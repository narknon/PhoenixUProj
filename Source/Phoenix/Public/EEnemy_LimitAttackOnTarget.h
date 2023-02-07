#pragma once
#include "CoreMinimal.h"
#include "EEnemy_LimitAttackOnTarget.generated.h"

UENUM(BlueprintType)
enum class EEnemy_LimitAttackOnTarget : uint8 {
    None,
    AttackStart,
    WindowStart,
    ReleaseStart,
    RunToStart,
    EEnemy_MAX UMETA(Hidden),
};

