#include "DirectionalLightAdvancedParametersOverride.h"

FDirectionalLightAdvancedParametersOverride::FDirectionalLightAdvancedParametersOverride() {
    this->bOverride_LightSourceAngle = false;
    this->bOverride_LightSourceSoftAngle = false;
    this->bOverride_LightingChannels = false;
    this->bOverride_AffectDynamicIndirectLighting = false;
    this->bOverride_AffectTranslucentLighting = false;
    this->bOverride_Transmission = false;
    this->bOverride_UsedAsAtmosphereSunLight = false;
    this->bOverride_ProbeOnly = false;
    this->bOverride_ShadowCascadeBiasDistribution = false;
    this->bOverride_AtmosphereSunLightIndex = false;
    this->bOverride_CloudShadowStrength = false;
    this->bOverride_CloudShadowOnAtmosphereStrength = false;
    this->bOverride_CloudShadowOnSurfaceStrength = false;
    this->bOverride_CloudShadowMinMax = false;
    this->bOverride_AtmosphereSunDiskColorScale = false;
    this->bOverride_bPerPixelAtmosphereTransmittance = false;
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

