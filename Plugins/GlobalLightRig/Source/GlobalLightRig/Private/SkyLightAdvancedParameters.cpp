#include "SkyLightAdvancedParameters.h"

FSkyLightAdvancedParameters::FSkyLightAdvancedParameters() {
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

