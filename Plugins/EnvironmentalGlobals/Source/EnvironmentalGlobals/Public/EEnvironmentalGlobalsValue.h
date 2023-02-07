#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsValue.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsValue : uint8 {
    DayNight,
    DayNightLerp,
    Day,
    Night,
    SunAltitudeDegrees,
    MoonAltitudeDegrees,
    LightAltitudeDegrees,
    SunUnitIntensity,
    MoonUnitIntensity,
    LightUnitIntensity,
    CameraEyeIndoors,
    CameraEyeProbeIndoors,
    CameraEyeWeatherIndoors,
    Overcast,
    NormalizedTime,
    AverageLuminanceEV100,
    AutoExposureEV100,
    BrightnessEV100,
    PlayerSpeed,
    CameraSpeed,
    CameraAngle,
    SeasonSmooth,
    SeasonLerp,
    Season,
};

