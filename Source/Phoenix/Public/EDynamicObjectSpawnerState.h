#pragma once
#include "CoreMinimal.h"
#include "EDynamicObjectSpawnerState.generated.h"

UENUM(BlueprintType)
enum class EDynamicObjectSpawnerState : uint8 {
    Inactive,
    Active,
    Spawning,
    Dormant,
};

