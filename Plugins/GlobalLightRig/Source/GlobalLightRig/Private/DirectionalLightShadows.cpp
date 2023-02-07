#include "DirectionalLightShadows.h"

FDirectionalLightShadows::FDirectionalLightShadows() {
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

