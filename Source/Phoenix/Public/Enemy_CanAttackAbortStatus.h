#pragma once
#include "CoreMinimal.h"
#include "Enemy_CanAttackAbortStatus.generated.h"

UENUM(BlueprintType)
enum class Enemy_CanAttackAbortStatus : uint8 {
    NullAttackData,
    AttackEventAlreadyStarted,
    AttackEventReset,
    VerifyAttack,
    CorridorCheck,
    VerifyAttackTicket,
    LimitAttackOnTargetLocked,
    Enemy_MAX UMETA(Hidden),
};

