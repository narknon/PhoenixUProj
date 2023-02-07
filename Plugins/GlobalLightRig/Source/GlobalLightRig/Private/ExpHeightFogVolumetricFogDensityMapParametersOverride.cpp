#include "ExpHeightFogVolumetricFogDensityMapParametersOverride.h"

FExpHeightFogVolumetricFogDensityMapParametersOverride::FExpHeightFogVolumetricFogDensityMapParametersOverride() {
    this->bOverride_FalloffStartMap = false;
    this->bOverride_DensityMultiplierMap = false;
    this->bOverride_DensityMapOrigin = false;
    this->bOverride_DensityMapSize = false;
    this->bOverride_DensityMapFalloffLength = false;
    this->bOverride_DensityMapFalloffStartRange = false;
    this->bOverride_DensityMapDensityRange = false;
    this->FalloffStartMap = NULL;
    this->DensityMultiplierMap = NULL;
    this->DensityMapFalloffLength = 0.00f;
}

