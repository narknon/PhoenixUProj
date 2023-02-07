#include "Transform_FindLedgeFromAbove.h"

UTransform_FindLedgeFromAbove::UTransform_FindLedgeFromAbove() {
    this->horizontalOffset = 0.00f;
    this->InitialHeight = 0.00f;
    this->SearchDistance = 0.00f;
    this->SphereRadius = 0.00f;
    this->RaycastStart = NULL;
    this->TraceType = TraceTypeQuery1;
}

