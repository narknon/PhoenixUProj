#include "CameraStackBehaviorLinearSpring.h"

UCameraStackBehaviorLinearSpring::UCameraStackBehaviorLinearSpring() {
    this->bDrawDebug = false;
    this->bUseSubstepping = false;
    this->MaxTimeStep = 0.00f;
    this->SpeedX = 48.00f;
    this->SpeedY = 48.00f;
    this->SpeedZ = 48.00f;
    this->FrequencyX = 8.00f;
    this->FrequencyY = 8.00f;
    this->FrequencyZ = 8.00f;
    this->DampingRatioX = 1.00f;
    this->DampingRatioY = 1.00f;
    this->DampingRatioZ = 1.00f;
    this->DefaultSpeed = 64.00f;
    this->bEnableSpring = false;
}

