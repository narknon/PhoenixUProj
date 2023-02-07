#include "BasicLightShadowDescription.h"

FBasicLightShadowDescription::FBasicLightShadowDescription() {
    this->bCastShadows = false;
    this->bCastStaticShadows = false;
    this->bCastDynamicShadows = false;
    this->bCastVolumetricShadow = false;
    this->bContactShadowLengthInWS = false;
    this->bCastTranslucentShadows = false;
    this->bCastShadowsFromCinematicObjectsOnly = false;
    this->ShadowResolutionScale = 0.00f;
    this->ShadowBias = 0.00f;
    this->ShadowSlopeBias = 0.00f;
    this->ShadowSharpen = 0.00f;
    this->ContactShadowLength = 0.00f;
    this->NearShadowClippingDistance = 0.00f;
}

