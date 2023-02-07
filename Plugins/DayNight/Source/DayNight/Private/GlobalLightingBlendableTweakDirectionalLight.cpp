#include "GlobalLightingBlendableTweakDirectionalLight.h"

UGlobalLightingBlendableTweakDirectionalLight::UGlobalLightingBlendableTweakDirectionalLight() {
    this->Mode = EDayNightTweakDirectionalLightMode::SunOnly;
    this->TweakAltitude = 0.00f;
    this->TweakAzimuth = 0.00f;
}

