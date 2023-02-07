#include "CameraStackBehaviorRotationLagSpringAttached.h"

UCameraStackBehaviorRotationLagSpringAttached::UCameraStackBehaviorRotationLagSpringAttached() {
    this->YawAmount = 1.00f;
    this->PitchAmount = 1.00f;
    this->RollAmount = 0.00f;
    this->MaxYawSpeed = 20.00f;
    this->MaxPitchSpeed = 20.00f;
    this->MaxRollSpeed = 20.00f;
    this->DamperHalflife = 0.20f;
    this->SpringHalflife = 0.20f;
}

