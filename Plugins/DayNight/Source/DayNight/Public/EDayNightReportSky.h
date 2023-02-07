#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportSky.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportSky : uint8 {
    NightNegOneDayOne,
    NightDay,
    Night,
    Day,
    NightSkyStrength,
    SunAzi,
    SunAlt,
    SunDiskAzi,
    SunDiskAlt,
    SunLightAzi,
    SunLightAlt,
    SunVisibility,
    SunScale,
    MoonAzi,
    MoonAlt,
    MoonPhase,
    MoonSize,
    MoonVisibility,
    MoonScale,
    MoonSunAngle,
    PlanetVenus,
    PlanetMars,
    PlanetJupiter,
    PlanetSaturn,
};

