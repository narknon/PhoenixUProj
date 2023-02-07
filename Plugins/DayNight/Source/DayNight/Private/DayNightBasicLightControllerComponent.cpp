#include "DayNightBasicLightControllerComponent.h"

UDayNightBasicLightControllerComponent::UDayNightBasicLightControllerComponent() {
    this->Night0Day1ColorMod = NULL;
    this->SunLightDesaturation = 0.80f;
    this->DayIntensityMod = 1.00f;
    this->NightIntensityMod = 0.01f;
    this->StartNightSunAngle = 0.00f;
    this->FullNightSunAngle = -2.00f;
    this->bModulateColor = true;
    this->bModulateIntensity = true;
    this->bUseSunDirectionalBoost = true;
    this->bUseSunLightColor = true;
    this->bAttenuateDayIntensityWithSunIntensity = true;
    this->bUseModColorCurve = false;
}

