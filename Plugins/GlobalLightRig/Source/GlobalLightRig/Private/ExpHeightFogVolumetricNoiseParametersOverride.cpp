#include "ExpHeightFogVolumetricNoiseParametersOverride.h"

FExpHeightFogVolumetricNoiseParametersOverride::FExpHeightFogVolumetricNoiseParametersOverride() {
    this->bOverride_NoiseMinFactor = false;
    this->bOverride_NoiseMaxFactor = false;
    this->bOverride_NoiseTilingSize = false;
    this->bOverride_NoiseSmoothStepMin = false;
    this->bOverride_NoiseSmoothStepMax = false;
    this->bOverride_BlueNoiseTexture = false;
    this->bOverride_WindFactor = false;
    this->bOverride_AddWindVelocity = false;
    this->bOverride_DensityTweakingLightingThreshold = false;
    this->bOverride_DensityTweakingMinPercentage = false;
    this->bOverride_AliasingReduction = false;
    this->bOverride_FullDensityDistance = false;
    this->bOverride_MinDensityFactor = false;
    this->NoiseMinFactor = 0.00f;
    this->NoiseMaxFactor = 0.00f;
    this->NoiseTilingSize = 0.00f;
    this->NoiseSmoothStepMin = 0.00f;
    this->NoiseSmoothStepMax = 0.00f;
    this->WindFactor = 0.00f;
    this->BlueNoiseTexture = NULL;
    this->DensityTweakingLightingThreshold = 0.00f;
    this->DensityTweakingMinPercentage = 0.00f;
    this->AliasingReduction = 0.00f;
    this->FullDensityDistance = 0.00f;
    this->MinDensityFactor = 0.00f;
}

