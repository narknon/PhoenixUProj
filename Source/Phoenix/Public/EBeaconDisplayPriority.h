#pragma once
#include "CoreMinimal.h"
#include "EBeaconDisplayPriority.generated.h"

UENUM(BlueprintType)
enum class EBeaconDisplayPriority : uint8 {
    BEACON_DISPLAY_PRIORITY_LOW,
    BEACON_DISPLAY_PRIORITY_MEDIUM,
    BEACON_DISPLAY_PRIORITY_HIGH,
    BEACON_DISPLAY_PRIORITY_HIGHEST,
    BEACON_DISPLAY_PRIORITY_MAX UMETA(Hidden),
};

