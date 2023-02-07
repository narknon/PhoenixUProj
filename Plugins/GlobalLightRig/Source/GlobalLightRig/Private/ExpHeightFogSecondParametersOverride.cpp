#include "ExpHeightFogSecondParametersOverride.h"

FExpHeightFogSecondParametersOverride::FExpHeightFogSecondParametersOverride() {
    this->bOverride_FogDensity = false;
    this->bOverride_FogHeightFalloff = false;
    this->bOverride_FogHeightOffset = false;
    this->FogDensity = 0.00f;
    this->FogHeightFalloff = 0.00f;
    this->FogHeightOffset = 0.00f;
}

