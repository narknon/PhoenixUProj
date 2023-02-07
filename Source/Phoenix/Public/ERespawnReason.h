#pragma once
#include "CoreMinimal.h"
#include "ERespawnReason.generated.h"

UENUM(BlueprintType)
enum class ERespawnReason : uint8 {
    None,
    RespawnedFromDeath,
    RespawnedFromFailure,
    TraveledToDungeon,
    TraveledFromDungeon,
    FastTraveled,
    StartedNewDay,
    JogIntoScene,
    WalkIntoScene,
    IntrusionCaught,
    DeathlyHallowsSpawn,
    FastTraveledViaMission,
};

