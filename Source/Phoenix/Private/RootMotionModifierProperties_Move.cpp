#include "RootMotionModifierProperties_Move.h"

URootMotionModifierProperties_Move::URootMotionModifierProperties_Move() {
    this->MoveDirectionRule = EMoveDirectionRule::ForwardVector;
    this->MoveMinSpeedRule = EMoveMinSpeedRule::ZeroSpeed;
    this->MoveMaxSpeedRule = EMoveMaxSpeedRule::DesiredSpeed;
    this->MoveInterpRule = EMoveInterpRule::NoInterp;
    this->bNegateDirection = false;
    this->FixedMinSpeed = 0.00f;
    this->FixedMaxSpeed = 1000.00f;
    this->InterpSpeed = 1000.00f;
    this->bOverrideWalkSpeed = false;
    this->WalkSpeedOverride = 150.00f;
    this->bEnabled = true;
}

