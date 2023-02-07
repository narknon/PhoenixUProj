#include "GlobalLightingBlendableSecondaryLight.h"

UGlobalLightingBlendableSecondaryLight::UGlobalLightingBlendableSecondaryLight() {
    this->SecondaryDirectionalLightDirection = NULL;
    this->SecondaryDirectionalLightParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

