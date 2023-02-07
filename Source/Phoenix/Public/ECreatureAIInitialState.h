#pragma once
#include "CoreMinimal.h"
#include "ECreatureAIInitialState.generated.h"

UENUM(BlueprintType)
enum class ECreatureAIInitialState : uint8 {
    Auto,
    Idle,
    Stationary,
    FollowPath,
    RelaxNearSpawnLocation,
    SpawnOnDen,
    PostGrowUp,
    InCage,
    StationaryGrazing,
};

