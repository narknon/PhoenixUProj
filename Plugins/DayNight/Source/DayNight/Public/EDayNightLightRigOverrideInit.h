#pragma once
#include "CoreMinimal.h"
#include "EDayNightLightRigOverrideInit.generated.h"

UENUM(BlueprintType)
enum class EDayNightLightRigOverrideInit : uint8 {
    Defaults,
    NewMoon,
    FullMoon,
    ProbeNight,
};

