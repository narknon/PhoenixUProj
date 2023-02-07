#include "ExpHeightFogVolumetricAdvancedParameters.h"

FExpHeightFogVolumetricAdvancedParameters::FExpHeightFogVolumetricAdvancedParameters() {
    this->DensityTweakingLightingThreshold = 0.00f;
    this->DensityTweakingMinPercentage = 0.00f;
    this->AliasingReduction = 0.00f;
    this->VolumetricFogHighQualityDistance = 0.00f;
    this->EmptyCellSkyOcclusion = 0.00f;
    this->bEnableVariableScatteringDistribution = false;
    this->MinScatteringDistribution = 0.00f;
    this->MaxScatteringDistribution = 0.00f;
    this->ScatteringDistributionInterpStart = 0.00f;
    this->ScatteringDistributionInterpEnd = 0.00f;
    this->FullDensityDistance = 0.00f;
    this->MinDensityFactor = 0.00f;
}

