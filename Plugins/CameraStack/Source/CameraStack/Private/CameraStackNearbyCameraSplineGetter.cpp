#include "CameraStackNearbyCameraSplineGetter.h"

UCameraStackNearbyCameraSplineGetter::UCameraStackNearbyCameraSplineGetter() {
    this->SplineType = ECameraStackSplineType::LookAheadSpline;
    this->DistanceThreshold = 500.00f;
    this->LookAheadDistance = 0.00f;
}

