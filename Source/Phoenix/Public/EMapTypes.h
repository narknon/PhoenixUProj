#pragma once
#include "CoreMinimal.h"
#include "EMapTypes.generated.h"

UENUM(BlueprintType)
namespace EMapTypes {
    enum Type {
        MAP_TYPE_NONE,
        MAP_TYPE_OVERLAND,
        MAP_TYPE_DUNGEON,
        MAP_TYPE_HOGWARTS,
        MAP_TYPE_HOGSMEADE,
        MAP_TYPE_SANCTUARY,
        MAP_TYPE_TENT,
        MAP_TYPE_TUTORIAL,
        MAP_TYPE_MAX UMETA(Hidden),
    };
}

