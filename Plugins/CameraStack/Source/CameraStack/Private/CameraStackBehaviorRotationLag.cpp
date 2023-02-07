#include "CameraStackBehaviorRotationLag.h"

UCameraStackBehaviorRotationLag::UCameraStackBehaviorRotationLag() {
    this->LagSpeed = 10.00f;
    this->bLagPreviousBehaviorOnly = false;
    this->bAffectsYaw = true;
    this->bAffectsPitch = true;
    this->bAffectsRoll = true;
    this->bUseSubstepping = true;
    this->MaxTimeStep = 0.02f;
}

