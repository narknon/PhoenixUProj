#include "RootMotionModifierProperties_JumpControl.h"

URootMotionModifierProperties_JumpControl::URootMotionModifierProperties_JumpControl() {
    this->InitialSpeed = 0.00f;
    this->MaxSpeed = 100.00f;
    this->AccelerationInterpSpeed = 1.00f;
    this->BrakingInterpSpeed = 1.00f;
    this->JumpControlType = EJumpControlType::Velocity;
    this->BlendInTime = 0.00f;
}

