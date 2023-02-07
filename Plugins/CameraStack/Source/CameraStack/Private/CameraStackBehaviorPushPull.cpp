#include "CameraStackBehaviorPushPull.h"

UCameraStackBehaviorPushPull::UCameraStackBehaviorPushPull() {
    this->bEnableLag = true;
    this->LagSpeed = 12.00f;
    this->MaxArmLength2D = 360.00f;
    this->MinArmLength2D = 200.00f;
    this->YawMinMax = 0.00f;
}

