#pragma once
#include "CoreMinimal.h"
#include "ESlaveToSplineUpdateMode.generated.h"

UENUM(BlueprintType)
enum class ESlaveToSplineUpdateMode : uint8 {
    Wrap,
    PingPong,
    Once,
    Manual,
};

