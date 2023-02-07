#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackScoreTypeLevel.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackScoreTypeLevel : uint8 {
    Unset,
    VeryLow,
    Low,
    Medium,
    High,
    VeryHigh,
    EEnemy_MAX UMETA(Hidden),
};

