#include "CameraStackBehaviorSteerAroundCorners.h"

UCameraStackBehaviorSteerAroundCorners::UCameraStackBehaviorSteerAroundCorners() {
    this->RotationSpeed = 90.00f;
    this->BlendExponent = 3.00f;
    this->AccelerationEaseSpeed = 2.00f;
    this->DecelerationEaseSpeed = 6.00f;
}

