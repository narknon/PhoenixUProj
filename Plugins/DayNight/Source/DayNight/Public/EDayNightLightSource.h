#pragma once
#include "CoreMinimal.h"
#include "EDayNightLightSource.generated.h"

UENUM(BlueprintType)
enum class EDayNightLightSource : uint8 {
    Sun,
    Moon,
    LerpingSun,
    LerpingMoon,
    Invalid,
};

