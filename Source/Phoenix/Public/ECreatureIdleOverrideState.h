#pragma once
#include "CoreMinimal.h"
#include "ECreatureIdleOverrideState.generated.h"

UENUM(BlueprintType)
enum class ECreatureIdleOverrideState : uint8 {
    None,
    Stationary,
    FollowPath,
    RelaxNearSpawnLocation,
    StationaryGrazing,
};

