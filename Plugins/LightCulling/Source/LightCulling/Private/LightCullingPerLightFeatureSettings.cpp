#include "LightCullingPerLightFeatureSettings.h"

FLightCullingPerLightFeatureSettings::FLightCullingPerLightFeatureSettings() {
    this->bDisableShadowCulling = false;
    this->bDisableVolumetricScatterCulling = false;
    this->bDisableVolumetricShadowCulling = false;
    this->bDisableContactShadowsCulling = false;
    this->bDisableTranslucentLightingCulling = false;
    this->bDisableVolumetricLightingCulling = false;
}

