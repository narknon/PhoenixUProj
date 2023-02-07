#pragma once
#include "CoreMinimal.h"
#include "EDoorCurveAdjustment.generated.h"

UENUM(BlueprintType)
enum class EDoorCurveAdjustment : uint8 {
    NoAdjustment,
    Invert,
    Reverse,
};

