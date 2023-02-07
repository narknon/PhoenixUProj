#include "CameraStackBehaviorSetRotationLimitsRelativeToTarget.h"

UCameraStackBehaviorSetRotationLimitsRelativeToTarget::UCameraStackBehaviorSetRotationLimitsRelativeToTarget() {
    this->SecondaryTarget = NULL;
    this->bEnablePitchLimits = false;
    this->MinPitch = -90.00f;
    this->MaxPitch = 90.00f;
    this->bEnableYawLimits = false;
    this->minYaw = -340282346638528859811704183484516925440.00f;
    this->MaxYaw = 340282346638528859811704183484516925440.00f;
}

