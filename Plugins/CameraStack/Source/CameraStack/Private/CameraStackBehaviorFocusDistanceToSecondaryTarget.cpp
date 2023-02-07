#include "CameraStackBehaviorFocusDistanceToSecondaryTarget.h"

UCameraStackBehaviorFocusDistanceToSecondaryTarget::UCameraStackBehaviorFocusDistanceToSecondaryTarget() {
    this->SecondaryTarget = NULL;
    this->bSetToPrimaryTargetIfTargetIsInvalid = false;
    this->bKeepLastFocusDistance = true;
}

