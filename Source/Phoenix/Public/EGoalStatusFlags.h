#pragma once
#include "CoreMinimal.h"
#include "EGoalStatusFlags.generated.h"

UENUM(BlueprintType)
namespace EGoalStatusFlags {
    enum Type {
        STATUS_FLAG_NONE,
        STATUS_FLAG_INTRANSIT,
        STATUS_FLAG_STATION_REQUIRED,
        STATUS_FLAG_INTERRUPTED = 0x4,
        STATUS_FLAG_COMPLETE = 0x8,
        STATUS_FLAG_DYNAMIC_IN_PROGRESS = 0x10,
        STATUS_FLAG_FAST_TRAVEL = 0x20,
        STATUS_FLAG_ENTER_COMPLETE_CALLBACK = 0x40,
        STATUS_FLAG_EXIT_COMPLETE_CALLBACK = 0x80,
        STATUS_FLAG_MAX UMETA(Hidden),
    };
}

