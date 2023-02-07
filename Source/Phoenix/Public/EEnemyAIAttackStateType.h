#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIAttackStateType.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIAttackStateType : uint8 {
    None,
    Attack_0,
    Pressure_0,
    Withdraw_0,
    Count,
};

