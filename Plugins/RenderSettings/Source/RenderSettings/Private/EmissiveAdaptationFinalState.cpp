#include "EmissiveAdaptationFinalState.h"

FEmissiveAdaptationFinalState::FEmissiveAdaptationFinalState() {
    this->MinExposureEV100 = 0.00f;
    this->MaxExposureEV100 = 0.00f;
    this->BiasPow2 = 0.00f;
    this->MinExposure = 0.00f;
    this->MaxExposure = 0.00f;
    this->Bias = 0.00f;
    this->InverseBias = 0.00f;
    this->LastFrameAverageLuminanceEV100 = 0.00f;
    this->LastFrameAutoExposureEV100 = 0.00f;
    this->LastFrameAverageLuminanceFilteredEV100 = 0.00f;
    this->LastFrameAutoExposureFilteredEV100 = 0.00f;
    this->LastFrameAverageLuminance = 0.00f;
    this->LastFrameAutoExposure = 0.00f;
    this->LastFrameAverageLuminanceFiltered = 0.00f;
    this->LastFrameAutoExposureFiltered = 0.00f;
    this->BloomTargetEV100 = 0.00f;
    this->BloomFinalMultiplier = 0.00f;
    this->BloomFinalMultiplierOutdoorsDaytime = 0.00f;
    this->BloomUncorrectedMultiplier = 0.00f;
    this->BloomMultiplierMin = 0.00f;
    this->BloomMultiplierMax = 0.00f;
    this->BloomCorrectionFactor = 0.00f;
    this->AutoFinalMultiplier = 0.00f;
    this->AutoFinalMultiplierOutdoorsDaytime = 0.00f;
    this->LuminanceFinalMultiplier = 0.00f;
    this->LuminanceFinalMultiplierFiltered = 0.00f;
    this->LuminanceMultiplierMin = 0.00f;
    this->LuminanceMultiplierMax = 0.00f;
    this->Indoors = 0.00f;
    this->FilteredIndoors = 0.00f;
    this->OutdoorsDayTime = 0.00f;
    this->OutdoorsDayTimeBoostEV = 0.00f;
    this->OutdoorsDayTimeBoostFactor = 0.00f;
    this->bEnabled = false;
}

