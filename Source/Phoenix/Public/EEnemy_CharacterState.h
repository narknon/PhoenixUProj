#pragma once
#include "CoreMinimal.h"
#include "EEnemy_CharacterState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_CharacterState : uint8 {
    Wander,
    Stationary,
    StationaryUntilAware,
    FollowPath,
    StationaryUntilReleased,
    FollowSpline,
    None,
    EEnemy_MAX UMETA(Hidden),
};

