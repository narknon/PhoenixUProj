#include "BasicLightDescription.h"

FBasicLightDescription::FBasicLightDescription() {
    this->IntensityUnits = ELightUnits::Unitless;
    this->Intensity = 0.00f;
    this->AttenuationRadius = 0.00f;
    this->Temperature = 0.00f;
    this->VolumetricScatteringIntensity = 0.00f;
    this->SpecularScale = 0.00f;
    this->bAffectTranslucentLighting = false;
    this->bTransmission = false;
    this->bAffectReflection = false;
    this->bUseTemperature = false;
    this->bEnableLightShaftBloom = false;
}

