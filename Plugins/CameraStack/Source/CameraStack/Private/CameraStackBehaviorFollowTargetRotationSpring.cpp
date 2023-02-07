#include "CameraStackBehaviorFollowTargetRotationSpring.h"

UCameraStackBehaviorFollowTargetRotationSpring::UCameraStackBehaviorFollowTargetRotationSpring() {
    this->Frequency = 2.00f;
    this->DampingRatio = 1.00f;
    this->bAffectYaw = true;
    this->bAffectPitch = false;
    this->bUseSubstepping = true;
    this->MaxTimeStep = 0.02f;
}

