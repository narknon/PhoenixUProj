#pragma once
#include "CoreMinimal.h"
#include "ESpawnAreaEnum.generated.h"

UENUM(BlueprintType)
enum class ESpawnAreaEnum : uint8 {
    SPAWN_RING,
    SPAWN_SPHERE,
    SPAWN_SPHERE_FALLOFF,
    SPAWN_MAX UMETA(Hidden),
};

