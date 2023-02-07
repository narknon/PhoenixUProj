#pragma once
#include "CoreMinimal.h"
#include "ENPC_GameState.generated.h"

UENUM(BlueprintType)
enum class ENPC_GameState : uint8 {
    None,
    Wander,
    Attack,
    FollowPath,
    Flee,
    ScheduledEntity,
    Alert,
    FollowPlayer,
    Close,
    RunTo,
    Retreat,
    RetreatSplit,
    FollowSpline,
    ENPC_MAX UMETA(Hidden),
};

