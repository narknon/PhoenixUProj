#include "IKDriver_AimHead.h"

UIKDriver_AimHead::UIKDriver_AimHead() {
    this->YawLimit = 90.00f;
    this->PitchLimit = 50.00f;
    this->BackDeadZoneAngle = 45.00f;
    this->BlendSpeed = 6.50f;
    this->TimeDelay = 0.00f;
    this->DelayStartTime = 0.00f;
}

