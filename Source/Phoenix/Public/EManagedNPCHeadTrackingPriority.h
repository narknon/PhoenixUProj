#pragma once
#include "CoreMinimal.h"
#include "EManagedNPCHeadTrackingPriority.generated.h"

UENUM(BlueprintType)
enum class EManagedNPCHeadTrackingPriority : uint8 {
    Lowest,
    PointOfInterest,
    PerformTask,
    AttackTarget,
    Highest,
    Forced,
};

