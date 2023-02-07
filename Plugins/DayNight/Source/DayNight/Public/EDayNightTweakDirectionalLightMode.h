#pragma once
#include "CoreMinimal.h"
#include "EDayNightTweakDirectionalLightMode.generated.h"

UENUM(BlueprintType)
enum class EDayNightTweakDirectionalLightMode : uint8 {
    SunAndMoon,
    SunOnly,
    MoonOnly,
};

