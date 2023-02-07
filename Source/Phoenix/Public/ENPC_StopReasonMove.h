#pragma once
#include "CoreMinimal.h"
#include "ENPC_StopReasonMove.generated.h"

UENUM(BlueprintType)
enum class ENPC_StopReasonMove : uint8 {
    MoveData_RequestStop,
    MoveData_ResetRequestStop,
    MoveData_PathFinished,
    UpdateInfo_MoveCorridor,
    UpdateInfo_MoveCollision,
    UpdateMove_AwayFromWaypoint,
    UpdateMove_NotProgressingWaypoint,
    UpdateMove_NotProgressingDestination,
    UpdateMove_UpdateBlocked,
    UpdateMove_WillEnterCorridor,
    SetMoveWaypoint_StartBlocked,
    SetMoveWaypoint_ConstrainLocFailed,
    SetMoveWaypoint_AbruptHeadingChange,
    SetMoveWaypoint_HeadingOffscreen,
    SetMoveWaypoint_NoGroundFound,
    MoveWaypointCheck_NotProgressingDestination,
    MoveWaypointCheck_NotProgressingWaypoint,
    MoveWaypointCheck_AwayFromWaypoint,
    MoveCheck_LOSNotClear,
    MoveCheck_WillEnterCorridor,
    MoveCheck_TooCloseToTarget,
    MoveCheck_TooCloseToTeammates,
    MoveCheck_TooFarHeadingDistance,
    MoveCheck_EnergyDrained,
    ENPC_MAX UMETA(Hidden),
};

