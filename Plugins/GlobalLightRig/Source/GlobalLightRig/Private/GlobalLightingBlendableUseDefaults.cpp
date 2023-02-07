#include "GlobalLightingBlendableUseDefaults.h"

UGlobalLightingBlendableUseDefaults::UGlobalLightingBlendableUseDefaults() {
    this->Defaults = NULL;
    this->bDirectionalLightDirection = true;
    this->bDirectionalLightParameters = true;
    this->bSecondaryDirectionalLightDirection = true;
    this->bSecondaryDirectionalLightParameters = true;
    this->bSkyLightParameters = true;
    this->bSkyAtmosphereParameters = true;
    this->bExpHeightFogParameters = true;
    this->bVolumetricCloudsParameters = true;
    this->bCloudsPresetParameters = false;
    this->bCloudsWindParameters = false;
    this->bProbeLightingParameters = true;
    this->bCustomBlendables = true;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

