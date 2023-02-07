#include "CameraStackBehaviorLookAhead.h"

UCameraStackBehaviorLookAhead::UCameraStackBehaviorLookAhead() {
    this->TimeAhead = 1.00f;
    this->VelocityFilterHalflife = 0.20f;
    this->LocationFilterHalflife = 0.20f;
    this->bDrawDebug = false;
}

