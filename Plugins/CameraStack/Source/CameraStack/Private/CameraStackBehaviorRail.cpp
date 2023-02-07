#include "CameraStackBehaviorRail.h"

UCameraStackBehaviorRail::UCameraStackBehaviorRail() {
    this->SplineGetter = NULL;
    this->SplineMovementFrequency = 10.00f;
    this->BlendDuration = 2.00f;
    this->bFollowSplineRotation = false;
    this->bDebugDraw = false;
}

