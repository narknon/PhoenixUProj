#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackTier.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackTier : uint8 {
    High,
    Med,
    Low,
    None,
    EEnemy_MAX UMETA(Hidden),
};

