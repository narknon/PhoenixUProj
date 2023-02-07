#include "SkyLightAdvancedParametersOverride.h"

FSkyLightAdvancedParametersOverride::FSkyLightAdvancedParametersOverride() {
    this->bOverride_AffectTranslucentLighting = false;
    this->bOverride_Transmission = false;
    this->bOverride_ProbeOnly = false;
    this->bOverride_bAffectReflection = false;
    this->bOverride_Mobility = false;
    this->bOverride_SourceMode = false;
    this->bOverride_Cubemap = false;
    this->bOverride_SourceCubemapAngle = false;
    this->bOverride_CubemapResolution = false;
    this->bOverride_SkyDistanceThreshold = false;
    this->bOverride_bCaptureEmissiveOnly = false;
    this->bOverride_bLowerHemisphereIsBlack = false;
    this->bOverride_LowerHemisphereColor = false;
    this->Mobility = EComponentMobility::Static;
    this->SourceMode = ESkyLightSourceMode::CapturedScene;
    this->CubeMap = NULL;
    this->SourceCubemapAngle = 0.00f;
    this->CubemapResolution = 0;
    this->SkyDistanceThreshold = 0.00f;
    this->bCaptureEmissiveOnly = false;
    this->bLowerHemisphereIsBlack = false;
    this->bAffectTranslucentLighting = false;
    this->bTransmission = false;
    this->bAffectReflection = false;
    this->bProbeOnly = false;
}

