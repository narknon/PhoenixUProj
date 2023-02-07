#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportLightRig.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportLightRig : uint8 {
    LightRigSun,
    LightRigMoon,
    LightRigLight,
    CloudLighting,
    CloudSkylight,
    CloudShadows,
};

