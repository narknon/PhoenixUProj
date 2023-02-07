#include "CameraStackBehaviorInputToYawSpeed.h"

UCameraStackBehaviorInputToYawSpeed::UCameraStackBehaviorInputToYawSpeed() {
    this->MinRequiredInput = 0.30f;
    this->MinTargetSpeed = 50.00f;
    this->LagSpeed = 10.00f;
    this->AngleToYawSpeedCurve = NULL;
    this->SpeedMultiplier = 1.00f;
}

