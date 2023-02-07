#pragma once
#include "CoreMinimal.h"
#include "ENPCSense_EnemyTargetEval.generated.h"

UENUM(BlueprintType)
enum class ENPCSense_EnemyTargetEval : uint8 {
    Aware,
    Attacking,
    Alert,
    ENPCSense_MAX UMETA(Hidden),
};

