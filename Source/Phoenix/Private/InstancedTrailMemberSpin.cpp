#include "InstancedTrailMemberSpin.h"

FInstancedTrailMemberSpin::FInstancedTrailMemberSpin() {
    this->RotationsMin = 0.00f;
    this->RotationsMax = 0.00f;
    this->RotationConstraint = EInstancedTrailMemberRotationConstraint::ITMRC_NONE;
    this->Speed = 0.00f;
    this->Friction = 0.00f;
    this->bFlipFlopSpeed = false;
    this->RandomizeAxisConeHalfAngle = 0.00f;
    this->MinDelay = 0.00f;
    this->MaxDelay = 0.00f;
    this->ChanceOfNoRotations = 0.00f;
}

