#include "CameraStackBehaviorUserInput.h"

UCameraStackBehaviorUserInput::UCameraStackBehaviorUserInput() {
    this->YawSpeed = 180.00f;
    this->DefaultPitchSpeed = 90.00f;
    this->PitchToPitchSpeedPositive = NULL;
    this->PitchToPitchSpeedNegative = NULL;
    this->DefaultPitch = 0.00f;
    this->InputMappingCurve = NULL;
    this->MinGamepadInputForAcceleration = 0.90f;
    this->AccelerationSpeedFactor = 2.75f;
    this->AccelerationEaseSpeed = 2.00f;
    this->DecelerationEaseSpeed = 27.50f;
    this->ResetTime = 0.50f;
    this->ResetCurve = NULL;
    this->bSwapCameraSticks = false;
}

