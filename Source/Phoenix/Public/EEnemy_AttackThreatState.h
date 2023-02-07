#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackThreatState : uint8 {
    None,
    Inactive,
    Active_Blockable,
    Active_Unblockable,
    PreAttack,
    EEnemy_MAX UMETA(Hidden),
};

