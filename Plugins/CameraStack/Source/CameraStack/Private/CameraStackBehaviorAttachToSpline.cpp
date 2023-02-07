#include "CameraStackBehaviorAttachToSpline.h"

UCameraStackBehaviorAttachToSpline::UCameraStackBehaviorAttachToSpline() {
    this->SplineGetter = NULL;
    this->DistanceFromTarget = -500.00f;
    this->bDebugDraw = false;
}

