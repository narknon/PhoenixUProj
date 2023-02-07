#include "ExpHeightFogVolumetricLightingParametersOverride.h"

FExpHeightFogVolumetricLightingParametersOverride::FExpHeightFogVolumetricLightingParametersOverride() {
    this->bOverride_VolumetricLightingDirectionalLightScattering = false;
    this->bOverride_VolumetricLightingDirectionalLightDesaturation = false;
    this->bOverride_VolumetricLightingShadowsNearMinimum = false;
    this->bOverride_VolumetricLightingShadowsFarMinimum = false;
    this->bOverride_VolumetricLightingShadowsNearDistance = false;
    this->bOverride_VolumetricLightingShadowsFarDistance = false;
    this->bOverride_VolumetricLightingCloudShadowsNearMinimum = false;
    this->bOverride_VolumetricLightingCloudShadowsFarMinimum = false;
    this->bOverride_VolumetricLightingCloudShadowsNearDistance = false;
    this->bOverride_VolumetricLightingCloudShadowsFarDistance = false;
    this->bOverride_VolumetricLightingHistoryWeight = false;
    this->bOverride_VolumetricLightingHistoryWeightStableCell = false;
    this->bOverride_VolumetricLightingHistoryWeightMovingLight = false;
    this->VolumetricLightingDirectionalLightScattering = 0.00f;
    this->VolumetricLightingDirectionalLightDesaturation = 0.00f;
    this->VolumetricLightingShadowsNearMinimum = 0.00f;
    this->VolumetricLightingShadowsFarMinimum = 0.00f;
    this->VolumetricLightingShadowsNearDistance = 0.00f;
    this->VolumetricLightingShadowsFarDistance = 0.00f;
    this->VolumetricLightingCloudShadowsNearMinimum = 0.00f;
    this->VolumetricLightingCloudShadowsFarMinimum = 0.00f;
    this->VolumetricLightingCloudShadowsNearDistance = 0.00f;
    this->VolumetricLightingCloudShadowsFarDistance = 0.00f;
    this->VolumetricLightingHistoryWeight = 0.00f;
    this->VolumetricLightingHistoryWeightStableCell = 0.00f;
    this->VolumetricLightingHistoryWeightMovingLight = 0.00f;
}

