#include "CameraStackBehaviorSetRotationLimits.h"

UCameraStackBehaviorSetRotationLimits::UCameraStackBehaviorSetRotationLimits() {
    this->bEnablePitchLimits = false;
    this->MinPitch = -90.00f;
    this->MaxPitch = 90.00f;
    this->bEnableYawLimits = false;
    this->bLimitYawRelativeToTarget = false;
    this->minYaw = -1000000.00f;
    this->MaxYaw = 1000000.00f;
    this->bEnableRollLimits = false;
    this->minRoll = -180.00f;
    this->MaxRoll = 180.00f;
}

