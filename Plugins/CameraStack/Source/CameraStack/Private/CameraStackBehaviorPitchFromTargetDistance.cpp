#include "CameraStackBehaviorPitchFromTargetDistance.h"

UCameraStackBehaviorPitchFromTargetDistance::UCameraStackBehaviorPitchFromTargetDistance() {
    this->SecondaryTarget = NULL;
    this->PitchA = 0.00f;
    this->PitchB = 0.00f;
    this->bUseDistanceToTargetBounds = true;
}

