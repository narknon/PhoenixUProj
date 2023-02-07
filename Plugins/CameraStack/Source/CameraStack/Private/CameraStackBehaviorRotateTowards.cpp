#include "CameraStackBehaviorRotateTowards.h"

UCameraStackBehaviorRotateTowards::UCameraStackBehaviorRotateTowards() {
    this->bRotateYaw = false;
    this->bRotatePitch = false;
    this->bRotateRoll = false;
    this->RotationSpeed = 90.00f;
    this->AngleToRotationSpeed = NULL;
}

