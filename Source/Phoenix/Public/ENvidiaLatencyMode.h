#pragma once
#include "CoreMinimal.h"
#include "ENvidiaLatencyMode.generated.h"

UENUM(BlueprintType)
enum class ENvidiaLatencyMode : uint8 {
    Off,
    LowLatency,
    LowLatencyWithBoost,
};

