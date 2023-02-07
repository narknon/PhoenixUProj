#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingEventType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingEventType : uint8 {
    FirstTargetHit,
    TargetThresholdReached,
    TimedOutMissedThreshold,
    MarkForDeath,
};

