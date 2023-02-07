#pragma once
#include "CoreMinimal.h"
#include "Enemy_CanMoveStatus.generated.h"

UENUM(BlueprintType)
enum class Enemy_CanMoveStatus : uint8 {
    Stationary,
    NotValidTASForAttacking,
    NonInterruptible,
    WaitInNotInRange,
    CannotApproachNotInRangeOrWaiting,
    CannotApproach,
    InvalidSelectionRange,
    ImmediateOnlyNotInRange,
    ImmediateOnly,
    CannotAttackFromGoalLoc,
    ThresholdNotMet,
    RadiusNotMet,
    CannotMoveInRange,
    CannotRetreat,
    AttackCorridor,
    FailedDestination,
    ForceFace,
    MoveReqNotMet,
    AlreadyAtGoal,
    EnergyDrained,
    StayPut,
    NavMeshNotFound,
    NavPathFailed,
    Enemy_MAX UMETA(Hidden),
};

