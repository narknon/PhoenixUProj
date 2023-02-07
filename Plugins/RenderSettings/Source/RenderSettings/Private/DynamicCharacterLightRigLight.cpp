#include "DynamicCharacterLightRigLight.h"

FDynamicCharacterLightRigLight::FDynamicCharacterLightRigLight() {
    this->Light = NULL;
    this->DayIntensity = 0.00f;
    this->NightIntensity = 0.00f;
    this->bOffAtNight = false;
    this->bFillLight = false;
    this->bAzimuthFollow = false;
    this->bAltitudeFollow = false;
    this->bModulateWithTemperature = false;
    this->bDisableDirectionalLightBelowHorizon = false;
    this->bAllowAdaptation = false;
    this->bEnable = false;
}

