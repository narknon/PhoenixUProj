#include "LastRenderedExposure.h"

FLastRenderedExposure::FLastRenderedExposure() {
    this->AutoExposureEV100 = 0.00f;
    this->AverageViewLuminanceEV100 = 0.00f;
    this->AverageLuminanceEV100 = 0.00f;
    this->FrameNumber = 0;
    this->bValid = false;
}

