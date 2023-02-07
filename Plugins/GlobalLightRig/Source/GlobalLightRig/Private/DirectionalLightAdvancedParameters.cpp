#include "DirectionalLightAdvancedParameters.h"

FDirectionalLightAdvancedParameters::FDirectionalLightAdvancedParameters() {
    this->ShadowCascadeBiasDistribution = 0.00f;
    this->LightSourceAngle = 0.00f;
    this->LightSourceSoftAngle = 0.00f;
    this->CloudShadowStrength = 0.00f;
    this->CloudShadowOnAtmosphereStrength = 0.00f;
    this->CloudShadowOnSurfaceStrength = 0.00f;
    this->AtmosphereSunLightIndex = 0;
    this->bPerPixelAtmosphereTransmittance = false;
    this->bAffectDynamicIndirectLighting = false;
    this->bAffectTranslucentLighting = false;
    this->bTransmission = false;
    this->bUsedAsAtmosphereSunLight = false;
    this->bProbeOnly = false;
}

