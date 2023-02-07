#include "DirectionalLightShadowsOverride.h"

FDirectionalLightShadowsOverride::FDirectionalLightShadowsOverride() {
    this->bOverride_ShadowResolutionScale = false;
    this->bOverride_ShadowBias = false;
    this->bOverride_ShadowSlopeBias = false;
    this->bOverride_ShadowSharpen = false;
    this->bOverride_ContactShadowLength = false;
    this->bOverride_ContactShadowLengthWorldSpace = false;
    this->bOverride_ContactShadowLengthInWS = false;
    this->bOverride_CastVolumetricShadow = false;
    this->bOverride_CastTranslucentShadows = false;
    this->ShadowResolutionScale = 0.00f;
    this->ShadowBias = 0.00f;
    this->ShadowSlopeBias = 0.00f;
    this->ShadowSharpen = 0.00f;
    this->ContactShadowLength = 0.00f;
    this->ContactShadowLengthWorldSpace = 0.00f;
    this->bContactShadowLengthInWS = false;
    this->bCastVolumetricShadow = false;
    this->bCastTranslucentShadows = false;
}

