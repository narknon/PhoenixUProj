#include "RenderSettingsPPExposureAdvanced.h"

FRenderSettingsPPExposureAdvanced::FRenderSettingsPPExposureAdvanced() {
    this->bOverride_AutoExposureLowPercent = false;
    this->bOverride_AutoExposureHighPercent = false;
    this->bOverride_HistogramLogMin = false;
    this->bOverride_HistogramLogMax = false;
    this->bOverride_AutoExposureMeterMask = false;
    this->AutoExposureLowPercent = 0.00f;
    this->AutoExposureHighPercent = 0.00f;
    this->HistogramLogMin = 0.00f;
    this->HistogramLogMax = 0.00f;
    this->AutoExposureMeterMask = NULL;
}

