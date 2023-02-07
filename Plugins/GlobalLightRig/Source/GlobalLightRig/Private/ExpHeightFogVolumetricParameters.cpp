#include "ExpHeightFogVolumetricParameters.h"

FExpHeightFogVolumetricParameters::FExpHeightFogVolumetricParameters() {
    this->bVolumetricFog = false;
    this->VolumetricFogScatteringDistribution = 0.00f;
    this->VolumetricFogExtinctionScale = 0.00f;
    this->VolumetricFogDistance = 0.00f;
    this->OutsideVolumeSunMultiplier = 0.00f;
    this->VolumetricInscatteringContribution = 0.00f;
    this->VolumetricDirectionalInscatteringContribution = 0.00f;
    this->VolumetricFogHeightFogNearStartDistance = 0.00f;
    this->VolumetricFogHeightFogNearFullDistance = 0.00f;
    this->VolumetricFogHeightFogColorationBlendStartDistance = 0.00f;
    this->VolumetricFogHeightFogColorationBlendFullDistance = 0.00f;
    this->VolumetricFogHeightFogColorationBlendStrength = 0.00f;
    this->VolumetricFogDepthDistributionScale = 0.00f;
    this->VolumetricFogHistoryWeight = 0.00f;
    this->VolumetricFogHistoryWeightFarFog = 0.00f;
    this->bOverrideLightColorsWithFogInscatteringColors = false;
}

