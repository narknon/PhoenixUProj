#include "EnvironmentalGlobals.h"

FEnvironmentalGlobals::FEnvironmentalGlobals() {
    this->DayNight = 0.00f;
    this->DayNightLerp = 0.00f;
    this->Day = 0.00f;
    this->Night = 0.00f;
    this->DirectionalLightMode = EEnvironmentalGlobalsDirectionalLightMode::Unknown;
    this->bDualDirectionalLightMode = false;
    this->CameraEyeIndoors = 0.00f;
    this->CameraEyeProbeIndoors = 0.00f;
    this->CameraEyeWeatherIndoors = 0.00f;
    this->CameraEyeAudioIndoors = 0.00f;
    this->CameraEyeStreamingIndoors = 0.00f;
    this->Overcast = 0.00f;
    this->LightsOnMask = 0;
}

