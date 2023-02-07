#include "DayNightLocalLightControllerComponent.h"

UDayNightLocalLightControllerComponent::UDayNightLocalLightControllerComponent() {
    this->Night0Day1ColorMod = NULL;
    this->DayIntensityMod = 100.00f;
    this->NightIntensityMod = 1.00f;
    this->StartNightSunAngle = 0.00f;
    this->FullNightSunAngle = -2.00f;
    this->bModulateColor = true;
    this->bModulateIntensity = true;
    this->bUseModColorCurve = false;
}

