#include "ExpHeightFogVolumetricNoiseParameters.h"

FExpHeightFogVolumetricNoiseParameters::FExpHeightFogVolumetricNoiseParameters() {
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

