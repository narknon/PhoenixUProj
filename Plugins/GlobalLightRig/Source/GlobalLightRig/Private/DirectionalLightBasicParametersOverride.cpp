#include "DirectionalLightBasicParametersOverride.h"

FDirectionalLightBasicParametersOverride::FDirectionalLightBasicParametersOverride() {
    this->bOverride_Intensity = false;
    this->bOverride_LightColor = false;
    this->bOverride_Temperature = false;
    this->bOverride_UseTemperature = false;
    this->bOverride_SpecularScale = false;
    this->bOverride_IndirectLightingIntensity = false;
    this->bOverride_VolumetricScatteringIntensity = false;
    this->bOverride_AtmosphereSunLightPriority = false;
    this->bOverride_bPseudoLight = false;
    this->Intensity = 0.00f;
    this->Temperature = 0.00f;
    this->bUseTemperature = false;
    this->SpecularScale = 0.00f;
    this->IndirectLightingIntensity = 0.00f;
    this->VolumetricScatteringIntensity = 0.00f;
    this->AtmosphereSunLightPriority = 0.00f;
    this->bPseudoLight = false;
}

