#include "DirectionalLightCascadedShadowMapsOverride.h"

FDirectionalLightCascadedShadowMapsOverride::FDirectionalLightCascadedShadowMapsOverride() {
    this->bOverride_DynamicShadowDistanceMovableLight = false;
    this->bOverride_DynamicShadowCascades = false;
    this->bOverride_CascadeDistributionExponent = false;
    this->bOverride_CascadeTransitionFraction = false;
    this->bOverride_ShadowDistanceFadeoutFraction = false;
    this->bOverride_FarShadowCascadeCount = false;
    this->bOverride_FarShadowDistance = false;
    this->bOverride_CachedDirectionalShadowDistance = false;
    this->bOverride_bUseCachedDirectionalShadowMaps = false;
    this->DynamicShadowDistanceMovableLight = 0.00f;
    this->DynamicShadowCascades = 0;
    this->CascadeDistributionExponent = 0.00f;
    this->CascadeTransitionFraction = 0.00f;
    this->ShadowDistanceFadeoutFraction = 0.00f;
    this->FarShadowCascadeCount = 0;
    this->FarShadowDistance = 0.00f;
    this->CachedDirectionalShadowDistance = 0.00f;
    this->bUseCachedDirectionalShadowMaps = false;
}

