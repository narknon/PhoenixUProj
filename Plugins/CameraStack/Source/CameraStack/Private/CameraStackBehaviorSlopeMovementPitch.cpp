#include "CameraStackBehaviorSlopeMovementPitch.h"

UCameraStackBehaviorSlopeMovementPitch::UCameraStackBehaviorSlopeMovementPitch() {
    this->PitchSpeed = 20.00f;
    this->PitchToPitchSpeed = NULL;
    this->MovementPitchFrequency = 2.00f;
    this->MovementPitchDamping = 2.00f;
    this->SpeedRampUpFrequency = 2.00f;
    this->SpeedRampDownFrequency = 20.00f;
    this->SpeedDamping = 2.00f;
}

