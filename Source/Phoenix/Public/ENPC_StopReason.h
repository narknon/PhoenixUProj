#pragma once
#include "CoreMinimal.h"
#include "ENPC_StopReason.generated.h"

UENUM(BlueprintType)
enum class ENPC_StopReason : uint8 {
    None,
    StopMove,
    MovementStop,
    OnPathFinished,
    PathFollowingComp_OnPathFinished,
    MovementComponent_StopActiveMovement,
    CanAttackChoose_StopReqPriorToAttack,
    CanAttackRequest_StopReqPriorToAttack,
    ENPC_MAX UMETA(Hidden),
};

