#include "RenderSettingsEmissiveAdaptation.h"

FRenderSettingsEmissiveAdaptation::FRenderSettingsEmissiveAdaptation() {
    this->bOverride_BloomTarget = false;
    this->bOverride_BloomBaseEV = false;
    this->bOverride_BloomIntensityCorrection = false;
    this->bOverride_BloomOutdoorsDaytimeBoostEV = false;
    this->bOverride_AutoExposureAdaptationBoostEV = false;
    this->bOverride_LuminanceAdaptationBoostEV = false;
    this->bOverride_LuminanceAdaptationMinEV = false;
    this->bOverride_LuminanceAdaptationMaxEV = false;
    this->BloomTargetExpression = NULL;
    this->BloomBaseExpression = NULL;
    this->BloomIntensityCorrection = 0.00f;
    this->BloomOutdoorsDaytimeBoostExpression = NULL;
    this->AutoExposureAdaptationBoostExpression = NULL;
    this->LuminanceAdaptationBoostExpression = NULL;
    this->LuminanceAdaptationMinExpression = NULL;
    this->LuminanceAdaptationMaxExpression = NULL;
}

