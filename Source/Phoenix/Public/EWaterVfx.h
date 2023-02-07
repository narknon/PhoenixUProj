#pragma once
#include "CoreMinimal.h"
#include "EWaterVfx.generated.h"

UENUM(BlueprintType)
enum class EWaterVfx : uint8 {
    EnterWater,
    Floating,
    ExitWater,
    Count,
};

