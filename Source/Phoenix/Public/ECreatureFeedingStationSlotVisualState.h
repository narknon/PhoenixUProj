#pragma once
#include "CoreMinimal.h"
#include "ECreatureFeedingStationSlotVisualState.generated.h"

UENUM(BlueprintType)
enum class ECreatureFeedingStationSlotVisualState : uint8 {
    Empty,
    Filling,
    Full,
    Emptying,
    Dispensing,
};

