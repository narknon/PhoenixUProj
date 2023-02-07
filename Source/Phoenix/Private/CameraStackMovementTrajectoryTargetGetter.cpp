#include "CameraStackMovementTrajectoryTargetGetter.h"

UCameraStackMovementTrajectoryTargetGetter::UCameraStackMovementTrajectoryTargetGetter() {
    this->TimeAhead = 2.00f;
    this->InterpolationSpeed = 0.90f;
    this->bDrawDebug = false;
}

