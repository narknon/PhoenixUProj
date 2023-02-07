#pragma once
#include "CoreMinimal.h"
#include "EOdcSnapMode.generated.h"

UENUM(BlueprintType)
enum class EOdcSnapMode : uint8 {
    SNAP_CLOSEST,
    SNAP_VERTICAL,
    SNAP_MAX UMETA(Hidden),
};

