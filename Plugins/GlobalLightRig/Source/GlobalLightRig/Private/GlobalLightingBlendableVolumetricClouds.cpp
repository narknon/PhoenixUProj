#include "GlobalLightingBlendableVolumetricClouds.h"

UGlobalLightingBlendableVolumetricClouds::UGlobalLightingBlendableVolumetricClouds() {
    this->VolumetricCloudsParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

