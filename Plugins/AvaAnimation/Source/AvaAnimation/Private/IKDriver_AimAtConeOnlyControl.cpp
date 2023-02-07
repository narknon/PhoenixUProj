#include "IKDriver_AimAtConeOnlyControl.h"

FIKDriver_AimAtConeOnlyControl::FIKDriver_AimAtConeOnlyControl() {
    this->DirectionDriver = EAnimationDirections::MovingDirection;
    this->YawLimit = 0.00f;
    this->PitchLimit = 0.00f;
    this->ReduceConeWithSpeed = false;
    this->SpeedForReduction = 0.00f;
    this->RatioToReduce = 0.00f;
    this->BackDeadZoneAngle = 0.00f;
    this->TimeDelay = 0.00f;
    this->DelayStartTime = 0.00f;
}

