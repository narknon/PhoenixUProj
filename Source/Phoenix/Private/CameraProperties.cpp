#include "CameraProperties.h"

FCameraProperties::FCameraProperties() {
    this->MinDistance = 0.00f;
    this->MaxDistance = 0.00f;
    this->MinPitch = 0.00f;
    this->MaxPitch = 0.00f;
    this->minYaw = 0.00f;
    this->MaxYaw = 0.00f;
    this->minRoll = 0.00f;
    this->MaxRoll = 0.00f;
    this->minFOV = 0.00f;
    this->maxFOV = 0.00f;
    this->BlendInTime = 0.00f;
    this->BlendOutTime = 0.00f;
    this->horizontalOffset = 0.00f;
    this->verticalOffset = 0.00f;
    this->weight = 0.00f;
    this->bSetToDefaultOnExit = false;
}

