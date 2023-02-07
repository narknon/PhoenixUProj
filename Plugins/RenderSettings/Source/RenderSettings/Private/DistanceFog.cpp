#include "DistanceFog.h"

FDistanceFog::FDistanceFog() {
    this->bOverride_FogColor = false;
    this->bOverride_StartDistance = false;
    this->bOverride_FullDistance = false;
    this->bOverride_CutoffDistance = false;
    this->bOverride_Thickness = false;
    this->bOverride_MaxFogOpacityPercent = false;
    this->bOverride_BlendSceneColorPercent = false;
    this->bOverride_SkyBlendPercent = false;
    this->bOverride_SkyDesaturation = false;
    this->bOverride_SkyIntensityBoost = false;
    this->bOverride_SkySamplingHorizonAngle = false;
    this->bOverride_SkySamplingUseCameraZ = false;
    this->bOverride_FastAtmosphereHorizonBump = false;
    this->bOverride_FogPPMaterial = false;
    this->bOverride_ExtraA = false;
    this->bOverride_ExtraB = false;
    this->bOverride_ExtraC = false;
    this->bOverride_ExtraD = false;
    this->bOverride_FogGradientHorizonOffset = false;
    this->bFogColorGradient = false;
    this->OnOff = 0.00f;
    this->FogGradientHorizonOffset = 0.00f;
    this->MaxFogOpacityPercent = 0.00f;
    this->StartDistance = 0.00f;
    this->FullDistance = 0.00f;
    this->CutoffDistance = 0.00f;
    this->Thickness = 0.00f;
    this->BlendSceneColorPercent = 0.00f;
    this->SkyBlendPercent = 0.00f;
    this->SkyDesaturation = 0.00f;
    this->SkyIntensityBoost = 0.00f;
    this->SkySamplingHorizonAngle = 0.00f;
    this->SkySamplingUseCameraZ = 0.00f;
    this->FastAtmosphereHorizonBump = 0.00f;
    this->FogPPMaterial = NULL;
}

