#include "PostProcessExposureValues.h"

FPostProcessExposureValues::FPostProcessExposureValues() {
    this->AutoExposureMinBrightness = 0.00f;
    this->AutoExposureMaxBrightness = 0.00f;
    this->AutoExposureBiasBase = 0.00f;
    this->AutoExposureBiasVFX = 0.00f;
    this->AutoExposureBiasCurve = NULL;
    this->AutoExposureSpeedUp = 0.00f;
    this->AutoExposureSpeedDown = 0.00f;
    this->HistogramLogMin = 0.00f;
    this->HistogramLogMax = 0.00f;
    this->BloomIntensity = 0.00f;
    this->BloomThreshold = 0.00f;
    this->AutoExposureMeterMask = NULL;
}

