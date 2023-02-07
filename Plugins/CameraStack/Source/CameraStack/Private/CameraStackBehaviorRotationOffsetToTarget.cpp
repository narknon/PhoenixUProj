#include "CameraStackBehaviorRotationOffsetToTarget.h"

UCameraStackBehaviorRotationOffsetToTarget::UCameraStackBehaviorRotationOffsetToTarget() {
    this->SecondaryTarget = NULL;
    this->DistanceToYaw = NULL;
    this->bSymmetricalYaw = true;
    this->bCommitToDirection = true;
    this->bOtherSide = false;
    this->AngleBias = 0.00f;
}

