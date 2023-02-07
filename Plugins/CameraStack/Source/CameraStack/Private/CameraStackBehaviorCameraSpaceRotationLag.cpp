#include "CameraStackBehaviorCameraSpaceRotationLag.h"

UCameraStackBehaviorCameraSpaceRotationLag::UCameraStackBehaviorCameraSpaceRotationLag() {
    this->LagSpeedYaw = 10.00f;
    this->LagSpeedPitch = 10.00f;
    this->LagSpeedRoll = 10.00f;
    this->bLagPreviousBehaviorOnly = false;
    this->bWorldSpace = true;
    this->bUseSubstepping = true;
    this->MaxTimeStep = 0.02f;
}

