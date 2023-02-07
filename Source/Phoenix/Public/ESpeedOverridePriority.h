#pragma once
#include "CoreMinimal.h"
#include "ESpeedOverridePriority.generated.h"

UENUM(BlueprintType)
enum class ESpeedOverridePriority : uint8 {
    ScheduledEntityPriority,
    SplineWalkerPriority,
    PerformTaskPriority,
    PerformTaskForAIPriority,
    GhostStoryPriority,
    CrimeSystemPriority,
    ForcedNavigationPriority,
    WalkToStationPriority,
    ApparatePriority,
};

