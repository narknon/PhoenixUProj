#include "CameraFixupSetFocusDistanceOperation.h"

UCameraFixupSetFocusDistanceOperation::UCameraFixupSetFocusDistanceOperation() {
    this->DistanceTarget = NULL;
    this->DistanceOffsetProvider = NULL;
    this->DistanceOffset = 0.00f;
    this->DrawDebug = false;
}

