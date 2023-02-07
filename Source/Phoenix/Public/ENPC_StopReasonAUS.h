#pragma once
#include "CoreMinimal.h"
#include "ENPC_StopReasonAUS.generated.h"

UENUM(BlueprintType)
enum class ENPC_StopReasonAUS : uint8 {
    AUSStartMove_PathFinished,
    AUSStartMove_MoveData_bStopMove,
    AUSStartMove_RequestTimeout,
    AUSUpdateMove_PathFinished,
    AUSUpdateMove_MoveData_bStopMove,
    AUSUpdateMove_RequestTimeout,
    AUSUpdateMove_CanMoveUpdateStopOrAttack,
    AUSMoving_SidekickUpdateStateUpdate,
    AUSMoving_PathFininshed,
    AUSMoving_bStopMove,
    AUSMoving_NotMoving,
    AUSMoving_AtPathDest,
    AUSMoving_AUSAbortPending,
    AUSMoving_MoveAbortPending,
    AUSMoving_AbruptDirectionChange,
    AUSMoving_AbortAttackDistance,
    AUSMoving_AtPendingDest,
    AUSMoving_CanMoveUpdateStopOrAttack,
    AUSMoving_CantAttackFromDest,
    AUSPaused,
    ENPC_MAX UMETA(Hidden),
};

