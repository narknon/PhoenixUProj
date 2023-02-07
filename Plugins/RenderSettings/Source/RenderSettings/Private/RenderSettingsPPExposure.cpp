#include "RenderSettingsPPExposure.h"

FRenderSettingsPPExposure::FRenderSettingsPPExposure() {
    this->bOverride_AutoExposureMethod = false;
    this->bOverride_AutoExposureMinBrightness = false;
    this->bOverride_AutoExposureMaxBrightness = false;
    this->bOverride_AutoExposureSpeedUp = false;
    this->bOverride_AutoExposureSpeedDown = false;
    this->bOverride_AutoExposureBias = false;
    this->AutoExposureMethod = AEM_Histogram;
    this->AutoExposureMinBrightness = 0.00f;
    this->AutoExposureMaxBrightness = 0.00f;
    this->AutoExposureSpeedUp = 0.00f;
    this->AutoExposureSpeedDown = 0.00f;
    this->AutoExposureBias = 0.00f;
}

