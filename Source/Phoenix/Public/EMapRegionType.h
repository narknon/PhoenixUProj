#pragma once
#include "CoreMinimal.h"
#include "EMapRegionType.generated.h"

UENUM(BlueprintType)
enum EMapRegionType {
    MAP_REGION_TYPE_UNDEFINED,
    MAP_REGION_TYPE_ROOM,
    MAP_REGION_TYPE_FLOOR,
    MAP_REGION_TYPE_STAIRS,
    MAP_REGION_TYPE_TOWER,
    MAP_REGION_TYPE_COUNT,
    MAP_REGION_TYPE_MAX UMETA(Hidden),
};

