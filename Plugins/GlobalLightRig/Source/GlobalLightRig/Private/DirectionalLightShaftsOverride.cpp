#include "DirectionalLightShaftsOverride.h"

FDirectionalLightShaftsOverride::FDirectionalLightShaftsOverride() {
    this->bOverride_EnableLightShaftOcclusion = false;
    this->bOverride_OcclusionMaskDarkness = false;
    this->bOverride_OcclusionDepthRange = false;
    this->bOverride_EnableLightShaftBloom = false;
    this->bOverride_BloomScale = false;
    this->bOverride_BloomThreshold = false;
    this->bOverride_BloomTint = false;
    this->bOverride_LightShaftOverrideDirection = false;
    this->bEnableLightShaftOcclusion = false;
    this->OcclusionMaskDarkness = 0.00f;
    this->OcclusionDepthRange = 0.00f;
    this->bEnableLightShaftBloom = false;
    this->BloomScale = 0.00f;
    this->BloomThreshold = 0.00f;
}

