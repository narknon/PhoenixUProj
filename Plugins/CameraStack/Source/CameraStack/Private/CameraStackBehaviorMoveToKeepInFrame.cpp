#include "CameraStackBehaviorMoveToKeepInFrame.h"

UCameraStackBehaviorMoveToKeepInFrame::UCameraStackBehaviorMoveToKeepInFrame() {
    this->bConsiderTargetBounds = false;
    this->bTruck = true;
    this->bPedestal = true;
    this->bUseUnblendedStackValues = false;
}

