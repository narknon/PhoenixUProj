#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIState.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIState : uint8 {
    None,
    Wander,
    Attack,
    FollowPath,
    Stationary,
    Dead,
    Deprecated_Reacting,
    DEPRECATED_Scared,
    Flee,
    FollowPlayer,
    ScheduledEntity,
    Sidekick,
    OnFire,
    Resurrecting,
    FollowSpline,
    Investigate,
};

