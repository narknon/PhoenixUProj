#include "VolumetricCloudsGroundShadowParametersOverride.h"

FVolumetricCloudsGroundShadowParametersOverride::FVolumetricCloudsGroundShadowParametersOverride() {
    this->bOverride_ShadowStrength = false;
    this->bOverride_CutOutDistanceMeters = false;
    this->bOverride_CutOutFadeDistanceMeters = false;
    this->ShadowStrength = 0.00f;
    this->CutOutDistanceMeters = 0.00f;
    this->CutOutFadeDistanceMeters = 0.00f;
}

