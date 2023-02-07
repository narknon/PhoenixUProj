#include "CameraStackBehaviorCollisionSweepVertical.h"

UCameraStackBehaviorCollisionSweepVertical::UCameraStackBehaviorCollisionSweepVertical() {
    this->ProbeSize = 12.00f;
    this->ProbeChannel = ECC_Camera;
    this->SweepStartHeight = 50.00f;
}

