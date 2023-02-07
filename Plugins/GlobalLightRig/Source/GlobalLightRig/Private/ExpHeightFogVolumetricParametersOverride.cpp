#include "ExpHeightFogVolumetricParametersOverride.h"

FExpHeightFogVolumetricParametersOverride::FExpHeightFogVolumetricParametersOverride() {
    this->bOverride_bVolumetricFog = false;
    this->bOverride_VolumetricFogScatteringDistribution = false;
    this->bOverride_VolumetricFogAlbedo = false;
    this->bOverride_VolumetricFogEmissive = false;
    this->bOverride_VolumetricFogExtinctionScale = false;
    this->bOverride_VolumetricFogDistance = false;
    this->bOverride_bOverrideLightColorsWithFogInscatteringColors = false;
    this->bOverride_VolumetricFogStaticLightingScatteringIntensity = false;
    this->bOverride_VolumetricFogDepthDistributionScale = false;
    this->bOverride_VolumetricFogHistoryWeight = false;
    this->bOverride_VolumetricFogHistoryWeightFarFog = false;
    this->bOverride_OutsideVolumeSunMultiplier = false;
    this->bOverride_VolumetricInscatteringContribution = false;
    this->bOverride_VolumetricDirectionalInscatteringContribution = false;
    this->bOverride_VolumetricFogHeightFogNearStartDistance = false;
    this->bOverride_VolumetricFogHeightFogNearFullDistance = false;
    this->bOverride_VolumetricFogHeightFogColorationBlendStartDistance = false;
    this->bOverride_VolumetricFogHeightFogColorationBlendFullDistance = false;
    this->bOverride_VolumetricFogHeightFogColorationBlendStrength = false;
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

