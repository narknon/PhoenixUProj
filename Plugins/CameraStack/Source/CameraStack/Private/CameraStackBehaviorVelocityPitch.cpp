#include "CameraStackBehaviorVelocityPitch.h"

UCameraStackBehaviorVelocityPitch::UCameraStackBehaviorVelocityPitch() {
    this->MaxVerticalSpeed = 300.00f;
    this->MaxPitchSpeed = 40.00f;
    this->PitchToPitchSpeedPositive = NULL;
    this->PitchToPitchSpeedNegative = NULL;
}

