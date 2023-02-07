#include "CameraStackBehaviorRotateTowardsSecondaryTarget.h"

UCameraStackBehaviorRotateTowardsSecondaryTarget::UCameraStackBehaviorRotateTowardsSecondaryTarget() {
    this->SecondaryTarget = NULL;
    this->DistanceToYaw = NULL;
    this->bSymmetricalYaw = true;
    this->bCommitToDirection = true;
    this->bOtherSide = false;
    this->RotationSpeed = 90.00f;
    this->AngleToRotationSpeed = NULL;
    this->AngleBias = 0.00f;
    this->AccumulatedRotationAmount = 0.00f;
}

