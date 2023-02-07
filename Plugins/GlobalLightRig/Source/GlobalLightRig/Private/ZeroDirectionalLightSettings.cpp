#include "ZeroDirectionalLightSettings.h"

FZeroDirectionalLightSettings::FZeroDirectionalLightSettings() {
    this->Mode = EZeroDirectionalLightMode::AllowZeroIntensity;
    this->ClampToMinimum = 0.00f;
}

