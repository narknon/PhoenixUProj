#include "CameraStackBehaviorResetRotation.h"

UCameraStackBehaviorResetRotation::UCameraStackBehaviorResetRotation() {
    this->ResetDuration = 0.50f;
    this->DefaultPitch = 0.00f;
    this->ResetCurve = NULL;
    this->bCancelResetOnInput = true;
    this->bResetYaw = true;
    this->bResetPitch = true;
}

