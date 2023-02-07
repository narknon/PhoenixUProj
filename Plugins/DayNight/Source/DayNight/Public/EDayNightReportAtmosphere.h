#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportAtmosphere.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportAtmosphere : uint8 {
    AtmosphereLightingAzi,
    AtmosphereLightingAlt,
    AtmosphereLightingIntensity,
    AtmosphereLightingColor,
    AtmosphereSunMultiplier,
    AtmosphereDesaturation,
    AtmosphereGroundOffset,
    AtmosphereDensityOffset,
    TwilightNightColorationU,
    TwilightNightColorationVBase,
    TwilightNightModColor,
    TwilightNightIntensity,
    TwilightNightDesaturation,
    TwilightNightFogIntensity,
    TwilightNightFogDesaturation,
    TwilightNightFogStart,
    TwilightNightFogEnd,
    TwilightNightFogPower,
    TwilightNightFogVNear,
    TwilightNightFogVFar,
};

