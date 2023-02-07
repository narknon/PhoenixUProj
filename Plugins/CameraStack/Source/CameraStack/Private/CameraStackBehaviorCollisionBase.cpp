#include "CameraStackBehaviorCollisionBase.h"

UCameraStackBehaviorCollisionBase::UCameraStackBehaviorCollisionBase() {
    this->ProbeSize = 12.00f;
    this->MinArmLengthLimit = 10.00f;
    this->ProbeChannel = ECC_Camera;
    this->CollisionInterpSpeed = 0.03f;
    this->ReturnInterpSpeed = 0.00f;
    this->MinCameraSpeedToReturn = 10.00f;
    this->MaxCameraSpeedToReturn = 400.00f;
    this->bDrawDebug = false;
}

