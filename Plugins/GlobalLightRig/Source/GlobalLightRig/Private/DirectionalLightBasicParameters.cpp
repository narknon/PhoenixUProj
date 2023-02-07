#include "DirectionalLightBasicParameters.h"

FDirectionalLightBasicParameters::FDirectionalLightBasicParameters() {
    this->Intensity = 0.00f;
    this->Temperature = 0.00f;
    this->bUseTemperature = false;
    this->SpecularScale = 0.00f;
    this->IndirectLightingIntensity = 0.00f;
    this->VolumetricScatteringIntensity = 0.00f;
    this->AtmosphereSunLightPriority = 0.00f;
    this->bPseudoLight = false;
    this->bExponentialIntensityBlend = false;
}

