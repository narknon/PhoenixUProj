#include "SkyLightShadowParametersOverride.h"

FSkyLightShadowParametersOverride::FSkyLightShadowParametersOverride() {
    this->bOverride_CastShadows = false;
    this->bOverride_CastVolumetricShadow = false;
    this->bOverride_CastStaticShadow = false;
    this->bOverride_CastDynamicShadow = false;
    this->bOverride_CastRaytracedShadow = false;
    this->bCastShadows = false;
    this->bCastStaticShadow = false;
    this->bCastDynamicShadow = false;
    this->bCastVolumetricShadow = false;
    this->bCastRaytracedShadow = false;
}

