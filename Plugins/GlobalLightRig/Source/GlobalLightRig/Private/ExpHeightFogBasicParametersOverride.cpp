#include "ExpHeightFogBasicParametersOverride.h"

FExpHeightFogBasicParametersOverride::FExpHeightFogBasicParametersOverride() {
    this->bOverride_ZOffset = false;
    this->bOverride_FogDensity = false;
    this->bOverride_FogHeightFalloff = false;
    this->bOverride_FogInscatteringColor = false;
    this->bOverride_FogMaxOpacity = false;
    this->bOverride_StartDistance = false;
    this->bOverride_FogCutoffDistance = false;
    this->bOverride_FogInscatteringIntensity = false;
    this->bOverride_FogInscatteringSaturation = false;
    this->bOverride_DistantFogCloudShadowsMinimum = false;
    this->bOverride_FogInscatteringColorDirLightLuminanceModulate = false;
    this->ZOffset = 0.00f;
    this->FogDensity = 0.00f;
    this->FogHeightFalloff = 0.00f;
    this->FogInscatteringIntensity = 0.00f;
    this->FogInscatteringSaturation = 0.00f;
    this->FogInscatteringColorDirLightLuminanceModulate = 0.00f;
    this->FogMaxOpacity = 0.00f;
    this->StartDistance = 0.00f;
    this->FogCutoffDistance = 0.00f;
    this->DistantFogCloudShadowsMinimum = 0.00f;
}

