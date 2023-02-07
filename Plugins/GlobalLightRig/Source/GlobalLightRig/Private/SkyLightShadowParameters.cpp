#include "SkyLightShadowParameters.h"

FSkyLightShadowParameters::FSkyLightShadowParameters() {
    this->bCastShadows = false;
    this->bCastStaticShadow = false;
    this->bCastDynamicShadow = false;
    this->bCastVolumetricShadow = false;
    this->bCastRaytracedShadow = false;
}

