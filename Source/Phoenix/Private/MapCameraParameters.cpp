#include "MapCameraParameters.h"

UMapCameraParameters::UMapCameraParameters() {
    this->LimitRotationBasedOnPitch = true;
    this->LimitPitch = false;
    this->PitchDefault = 0.00f;
    this->PitchSpeedMultiplier = 70.00f;
    this->LimitYaw = false;
    this->YawDefault = 0.00f;
    this->YawSpeedMultiplier = 110.00f;
    this->LimitPitchBasedOnRadius = false;
    this->LimitRadius = false;
    this->RadiusDefault = 0.00f;
    this->RaduisSpeedMultiplier = 5.00f;
    this->ZoomSnapInterpSpeed = 4.00f;
    this->MoveSpeed = 15000.00f;
    this->MoveAccelerationFactor = 3.65f;
    this->MoveDecelerationFactor = 4.50f;
    this->MoveMouseDragMaxSpeedFactor = 2.00f;
    this->MoveMouseDragAccelerationFrequency = 20.00f;
    this->MoveMouseDragDecelerationFrequency = 10.00f;
    this->MoveMouseDragDampingFactor = 1.00f;
    this->MoveDecelerationFactorMouseFlick = 1.70f;
    this->GamepadCameraFollowAccelerationFrequency = 16.00f;
    this->GamepadCameraFollowDecelerationFrequency = 8.00f;
    this->GamepadCameraFollowDampingFactor = 1.00f;
}

