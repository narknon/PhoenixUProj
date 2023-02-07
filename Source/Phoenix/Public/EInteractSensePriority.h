#pragma once
#include "CoreMinimal.h"
#include "EInteractSensePriority.generated.h"

UENUM(BlueprintType)
enum class EInteractSensePriority : uint8 {
    Lowest,
    NPC,
    Conversation,
    ActiveCinematic,
    PerformTask,
    HideTrigger,
    ScheduleTimeWindow,
    Highest,
};

