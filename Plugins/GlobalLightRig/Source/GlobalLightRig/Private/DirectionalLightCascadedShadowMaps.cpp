#include "DirectionalLightCascadedShadowMaps.h"

FDirectionalLightCascadedShadowMaps::FDirectionalLightCascadedShadowMaps() {
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

