#include "ExpHeightFogVolumetricLightingParameters.h"

FExpHeightFogVolumetricLightingParameters::FExpHeightFogVolumetricLightingParameters() {
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

