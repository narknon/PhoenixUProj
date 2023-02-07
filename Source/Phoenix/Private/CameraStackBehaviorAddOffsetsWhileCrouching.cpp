#include "CameraStackBehaviorAddOffsetsWhileCrouching.h"

UCameraStackBehaviorAddOffsetsWhileCrouching::UCameraStackBehaviorAddOffsetsWhileCrouching() {
    this->TargetZOffset = 0.00f;
    this->ArmOriginZOffset = 0.00f;
    this->bApplyToStealthOnly = false;
    this->BlendDuration = 0.50f;
    this->bAddArmOriginZOffsetWhileMoving = false;
    this->ArmOriginZOffsetWhileMoving = 0.00f;
    this->MovingBlendDuration = 0.50f;
}

