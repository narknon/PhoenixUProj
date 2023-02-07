#pragma once
#include "CoreMinimal.h"
#include "UStreamlineReflexMode.generated.h"

UENUM(BlueprintType)
enum class UStreamlineReflexMode : uint8 {
    Disabled,
    Enabled,
    EnabledPlusBoost = 0x3,
};

