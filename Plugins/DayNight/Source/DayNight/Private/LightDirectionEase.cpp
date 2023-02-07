#include "LightDirectionEase.h"

ULightDirectionEase::ULightDirectionEase() {
    this->Easing = ELerpEasingType::EaseInOut;
    this->BlendExp = 2.00f;
}

