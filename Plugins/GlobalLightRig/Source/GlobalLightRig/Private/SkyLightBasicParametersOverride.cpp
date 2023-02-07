#include "SkyLightBasicParametersOverride.h"

FSkyLightBasicParametersOverride::FSkyLightBasicParametersOverride() {
    this->bOverride_Intensity = false;
    this->bOverride_LightColor = false;
    this->bOverride_IndirectLightingIntensity = false;
    this->bOverride_VolumetricScatteringIntensity = false;
    this->Intensity = 0.00f;
    this->IndirectLightingIntensity = 0.00f;
    this->VolumetricScatteringIntensity = 0.00f;
}

