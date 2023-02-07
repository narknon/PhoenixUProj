#include "GlobalLightingBlendableDirectionalLight.h"

UGlobalLightingBlendableDirectionalLight::UGlobalLightingBlendableDirectionalLight() {
    this->DirectionalLightDirection = NULL;
    this->DirectionalLightParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

