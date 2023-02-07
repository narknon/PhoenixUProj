#pragma once
#include "CoreMinimal.h"
#include "EDynamicObjectVolumeSpawnerState.generated.h"

UENUM(BlueprintType)
enum class EDynamicObjectVolumeSpawnerState : uint8 {
    Inactive,
    GatheringData,
    Loading,
    Active,
    Spawning,
    Culling,
    Dormant,
};

