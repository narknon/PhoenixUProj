#include "DecalPointLightInfo.h"

FDecalPointLightInfo::FDecalPointLightInfo() {
    this->IntensityUnits = ELightUnits::Unitless;
    this->Intensity = 0.00f;
    this->Temperature = 0.00f;
    this->AttenuationRadius = 0.00f;
    this->LightFalloffExponent = 0.00f;
    this->MinDistance = 0.00f;
    this->MaxDrawDistance = 0.00f;
    this->MaxDistanceFadeRange = 0.00f;
    this->bUseTemperature = false;
    this->bUseInverseSquaredFalloff = false;
    this->bVisible = false;
}

