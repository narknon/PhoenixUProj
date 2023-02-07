#pragma once
#include "CoreMinimal.h"
#include "ENPC_MoveState.generated.h"

UENUM(BlueprintType)
enum class ENPC_MoveState : uint8 {
    Loop,
    Start,
    Stop,
    LoopTurn,
    FollowSpline,
    TurnInPlace,
    Pivot,
    Count,
    ENPC_MAX UMETA(Hidden),
};

