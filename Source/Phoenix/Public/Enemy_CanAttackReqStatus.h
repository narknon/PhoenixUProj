#pragma once
#include "CoreMinimal.h"
#include "Enemy_CanAttackReqStatus.generated.h"

UENUM(BlueprintType)
enum class Enemy_CanAttackReqStatus : uint8 {
    NoTarget,
    TargetReacting,
    BreakActive,
    InvalidAUSForTurnScore,
    InvalidTAS,
    InsideAttackCorridor,
    InAttackExecuteRetreatDist,
    InvalidAttackState,
    LOSPathToTargetNotClear,
    TeammateToTargetNotClear,
    TeammatePathToTargetNotClear,
    NotInterruptible,
    NotFacing,
    NoAttackData,
    TargetNotNavReachable,
    InAttackExecuteCooldown,
    InTicketCooldown,
    WaitingOnTicket,
    NotInRange,
    EnergyDrained,
    ProtegoStartWait,
    RetaliateActive,
    InWater,
    TargetInWater,
    HeightDifference,
    ParryTargetCurrentWindow,
    LimitAttackOnTarget,
    Suspended,
    ForceMove,
    AlreadyHoldsTicket,
    NoTicketAvailable,
    TargetHasParryWindowAlready,
    Enemy_MAX UMETA(Hidden),
};

