#include "EmissiveAdaptationLerpSettings.h"

FEmissiveAdaptationLerpSettings::FEmissiveAdaptationLerpSettings() {
    this->BloomTargetEV = 0.00f;
    this->BloomBaseEV = 0.00f;
    this->BloomIntensityCorrection = 0.00f;
    this->BloomOutdoorsDaytimeBoostEV = 0.00f;
    this->AutoExposureAdaptationBoostEV = 0.00f;
    this->LuminanceAdaptationBoostEV = 0.00f;
    this->LuminanceAdaptationClampMinEV = 0.00f;
    this->LuminanceAdaptationClampMaxEV = 0.00f;
}

