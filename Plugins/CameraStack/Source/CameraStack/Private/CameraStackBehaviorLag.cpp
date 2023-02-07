#include "CameraStackBehaviorLag.h"

UCameraStackBehaviorLag::UCameraStackBehaviorLag() {
    this->SpeedX = 48.00f;
    this->SpeedY = 48.00f;
    this->SpeedZ = 48.00f;
    this->bWorldSpace = true;
    this->bLagPreviousBehaviorOnly = false;
    this->bUseSubstepping = true;
    this->MaxTimeStep = 0.02f;
}

