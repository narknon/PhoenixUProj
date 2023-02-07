#include "CustomBlendableVDHW.h"

FCustomBlendableVDHW::FCustomBlendableVDHW() {
    this->bOverride_bMovingCameraSupport = false;
    this->bOverride_MovingCameraStartSpeed = false;
    this->bOverride_MovingCameraEndSpeed = false;
    this->bOverride_MovingCameraStartRotation = false;
    this->bOverride_MovingCameraEndRotation = false;
    this->bOverride_bExposureShiftSupport = false;
    this->bOverride_ExposureShiftStart = false;
    this->bOverride_ExposureShiftEnd = false;
    this->bMovingCameraSupport = false;
    this->MovingCameraStartSpeed = 0.00f;
    this->MovingCameraEndSpeed = 0.00f;
    this->MovingCameraStartRotation = 0.00f;
    this->MovingCameraEndRotation = 0.00f;
    this->bExposureShiftSupport = false;
    this->ExposureShiftStart = 0.00f;
    this->ExposureShiftEnd = 0.00f;
}

