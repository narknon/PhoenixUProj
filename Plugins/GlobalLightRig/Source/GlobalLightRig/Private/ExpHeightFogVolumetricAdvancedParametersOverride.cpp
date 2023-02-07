#include "ExpHeightFogVolumetricAdvancedParametersOverride.h"

FExpHeightFogVolumetricAdvancedParametersOverride::FExpHeightFogVolumetricAdvancedParametersOverride() {
    this->bOverride_DensityTweakingLightingThreshold = false;
    this->bOverride_DensityTweakingMinPercentage = false;
    this->bOverride_AliasingReduction = false;
    this->bOverride_VolumetricFogHighQualityDistance = false;
    this->bOverride_EmptyCellSkyOcclusion = false;
    this->bOverride_bEnableVariableScatteringDistribution = false;
    this->bOverride_MinScatteringDistribution = false;
    this->bOverride_MaxScatteringDistribution = false;
    this->bOverride_ScatteringDistributionInterpStart = false;
    this->bOverride_ScatteringDistributionInterpEnd = false;
    this->bOverride_FullDensityDistance = false;
    this->bOverride_MinDensityFactor = false;
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

