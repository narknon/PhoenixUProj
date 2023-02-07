#include "GlobalLightingBlendableFull.h"

UGlobalLightingBlendableFull::UGlobalLightingBlendableFull() {
    this->DirectionalLightDirection = NULL;
    this->DirectionalLightParameters = NULL;
    this->SecondaryDirectionalLightDirection = NULL;
    this->SecondaryDirectionalLightParameters = NULL;
    this->SkyLightParameters = NULL;
    this->SkyAtmosphereParameters = NULL;
    this->ExpHeightFogParameters = NULL;
    this->VolumetricCloudsParameters = NULL;
    this->CloudsPresetParameters = NULL;
    this->CloudsWindParameters = NULL;
    this->ProbeLightingParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

