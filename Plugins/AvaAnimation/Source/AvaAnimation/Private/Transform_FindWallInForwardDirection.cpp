#include "Transform_FindWallInForwardDirection.h"

UTransform_FindWallInForwardDirection::UTransform_FindWallInForwardDirection() {
    this->verticalOffset = 0.00f;
    this->SearchDistance = 0.00f;
    this->SphereRadius = 0.00f;
    this->RaycastStart = NULL;
    this->TraceType = TraceTypeQuery1;
}

