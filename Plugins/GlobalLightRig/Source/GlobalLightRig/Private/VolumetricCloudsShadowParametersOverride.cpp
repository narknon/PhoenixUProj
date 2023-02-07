#include "VolumetricCloudsShadowParametersOverride.h"

FVolumetricCloudsShadowParametersOverride::FVolumetricCloudsShadowParametersOverride() {
    this->bOverride_ShadowScale = false;
    this->bOverride_ShadowMapCloudShadowDensity = false;
    this->bOverride_RayMarchCloudShadowScale = false;
    this->bOverride_RayMarchShadowDensity = false;
    this->bOverride_SkyLightShadowDensity = false;
    this->ShadowScale = 0.00f;
    this->ShadowMapCloudShadowDensity = 0.00f;
    this->RayMarchCloudShadowScale = 0.00f;
    this->RayMarchShadowDensity = 0.00f;
    this->SkyLightShadowDensity = 0.00f;
}

