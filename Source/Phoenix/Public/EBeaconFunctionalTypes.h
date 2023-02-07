#pragma once
#include "CoreMinimal.h"
#include "EBeaconFunctionalTypes.generated.h"

UENUM(BlueprintType)
enum class EBeaconFunctionalTypes : uint8 {
    BEACON_TYPE_STATIC,
    BEACON_TYPE_DYNAMIC,
    BEACON_TYPE_DISCOVERABLE,
    BEACON_TYPE_ROAMING,
    BEACON_TYPE_MAX UMETA(Hidden),
};

