#include "CameraStackBehaviorLookAheadAlongSpline.h"

UCameraStackBehaviorLookAheadAlongSpline::UCameraStackBehaviorLookAheadAlongSpline() {
    this->SplineGetter = NULL;
    this->LookAheadDistance = 500.00f;
    this->PointOrDirectionInterp = 0.00f;
    this->TargetOffsetFactor = 1.00f;
    this->bOnlyInForwardDirection = false;
    this->bReturnPitchToDefault = false;
    this->bDebugDraw = false;
}

