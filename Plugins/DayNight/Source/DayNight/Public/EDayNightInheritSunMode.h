#pragma once
#include "CoreMinimal.h"
#include "EDayNightInheritSunMode.generated.h"

UENUM(BlueprintType)
enum class EDayNightInheritSunMode : uint8 {
    SunDiskOnly,
    FullSunRecompute,
};

