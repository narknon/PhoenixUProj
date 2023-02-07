#pragma once
#include "CoreMinimal.h"
#include "EMiniMapLevels.generated.h"

UENUM(BlueprintType)
namespace EMiniMapLevels {
    enum Type {
        MINI_MAP_LEVEL_OVERLAND,
        MINI_MAP_LEVEL_HOGWARTS,
        MINI_MAP_LEVEL_HOGSMEADE,
        MINI_MAP_LEVEL_DUNGEON,
        MINI_MAP_LEVEL_TUTORIAL,
        MINI_MAP_LEVEL_SANCTUARY,
        MINI_MAP_LEVEL_TENTS,
        MINI_MAP_LEVEL_NONE,
        MINI_MAP_LEVEL_MAX UMETA(Hidden),
    };
}

