#pragma once
#include "CoreMinimal.h"
#include "ESpawnedStationTypes.generated.h"

UENUM(BlueprintType)
enum ESpawnedStationTypes {
    SPAWNED_STATION_TYPE_NONE,
    SPAWNED_STATION_TYPE_WALKBY,
    SPAWNED_STATION_TYPE_STOPCHAT,
    SPAWNED_STATION_TYPE_MOVING_R,
    SPAWNED_STATION_TYPE_MOVING_LR,
    SPAWNED_STATION_TYPE_COUNT,
    SPAWNED_STATION_TYPE_MAX UMETA(Hidden),
};

