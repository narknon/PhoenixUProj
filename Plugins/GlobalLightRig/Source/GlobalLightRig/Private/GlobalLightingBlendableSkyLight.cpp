#include "GlobalLightingBlendableSkyLight.h"

UGlobalLightingBlendableSkyLight::UGlobalLightingBlendableSkyLight() {
    this->SkyLightParameters = NULL;
    this->OverrideSource = EGlobalLightingBlendableInputType::CombinedValues;
}

