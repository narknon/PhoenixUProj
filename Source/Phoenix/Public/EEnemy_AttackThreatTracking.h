#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatTracking.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackThreatTracking : uint8 {
    None,
    Windup,
    Fired,
    Parried,
    ParriedFired,
    EEnemy_MAX UMETA(Hidden),
};

