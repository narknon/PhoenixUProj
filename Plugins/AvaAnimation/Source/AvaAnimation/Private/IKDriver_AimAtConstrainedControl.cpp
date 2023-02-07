#include "IKDriver_AimAtConstrainedControl.h"

FIKDriver_AimAtConstrainedControl::FIKDriver_AimAtConstrainedControl() {
    this->DirectionDriver = EAnimationDirections::MovingDirection;
    this->bLimitDirectionToCone = false;
    this->YawLimit = 0.00f;
    this->PitchLimit = 0.00f;
    this->YawFrequency = 0.00f;
    this->YawDampingRatio = 0.00f;
    this->PitchFrequency = 0.00f;
    this->PitchDampingRatio = 0.00f;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->BackDeadZoneAngle = 0.00f;
}

