#include "CameraStackBehaviorAdjustArmFromTargetVelocity.h"

void UCameraStackBehaviorAdjustArmFromTargetVelocity::SetVelocityFilterHalflife(float InHalflife) {
}

void UCameraStackBehaviorAdjustArmFromTargetVelocity::SetScaleFilterHalflife(float InHalflife) {
}

UCameraStackBehaviorAdjustArmFromTargetVelocity::UCameraStackBehaviorAdjustArmFromTargetVelocity() {
    this->VelocityFilterHalflife = 0.00f;
    this->SpeedFilterHalflife = 0.00f;
    this->ScaleFilterHalflife = 0.00f;
    this->bDrawDebug = false;
}

