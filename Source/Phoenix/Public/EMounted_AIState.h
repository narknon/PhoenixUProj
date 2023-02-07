#pragma once
#include "CoreMinimal.h"
#include "EMounted_AIState.generated.h"

UENUM(BlueprintType)
enum class EMounted_AIState : uint8 {
    Stationary,
    MovingToPathNode,
    WaitingAtPathNode,
    FinishWaitingAtPathNode,
    MovingToSpline,
    FollowingSpline,
    EMounted_MAX UMETA(Hidden),
};

