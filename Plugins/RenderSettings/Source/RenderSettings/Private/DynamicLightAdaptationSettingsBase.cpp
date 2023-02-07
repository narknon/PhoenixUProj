#include "DynamicLightAdaptationSettingsBase.h"

FDynamicLightAdaptationSettingsBase::FDynamicLightAdaptationSettingsBase() {
    this->BaseEV = 0.00f;
    this->OutdoorsDayTimeEVBoost = 0.00f;
    this->AdaptationStrengthPercent = 0.00f;
    this->MinMaxExposureTarget = 0.00f;
    this->MaxEV = 0.00f;
    this->MinEV = 0.00f;
    this->StartCutoffMaxEV = 0.00f;
    this->StartCutoffMinEV = 0.00f;
    this->AutoExposureUpdateTolerance = 0.00f;
    this->FreezeAdaptationAfterFrames = 0;
    this->Mode = ELightAdapatationMode::LastFrameAutoExposure;
    this->bUseExposureBias = false;
    this->bFiltered = false;
    this->ExposureCompensationCurve = NULL;
    this->bApplyCompensation = false;
}

