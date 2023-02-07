#pragma once
#include "CoreMinimal.h"
#include "EMapFilterTypes.generated.h"

UENUM(BlueprintType)
enum class EMapFilterTypes : uint8 {
    MAP_FILTER_TYPE_NONE,
    MAP_FILTER_TYPE_GENERAL,
    MAP_FILTER_TYPE_BEASTS,
    MAP_FILTER_TYPE_PLANTS,
    MAP_FILTER_TYPE_MAX UMETA(Hidden),
};

