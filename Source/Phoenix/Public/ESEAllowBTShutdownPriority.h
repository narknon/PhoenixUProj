#pragma once
#include "CoreMinimal.h"
#include "ESEAllowBTShutdownPriority.generated.h"

UENUM(BlueprintType)
enum class ESEAllowBTShutdownPriority : uint8 {
    LowestPriority,
    SeatFillerPriority,
    HighestPriority,
};

