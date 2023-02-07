#include "BentDirectionalLightParams.h"

FBentDirectionalLightParams::FBentDirectionalLightParams() {
    this->BlendStartAngle = 0.00f;
    this->BlendEndAngle = 0.00f;
    this->SunIntensitFactorEnd = 0.00f;
    this->SkyLightIntensityFactorEnd = 0.00f;
    this->bBlendSunLight = false;
    this->bBlendSkyLight = false;
}

