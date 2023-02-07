#include "Transform_CastRay.h"

UTransform_CastRay::UTransform_CastRay() {
    this->RaycastStart = NULL;
    this->ComponentTransform = NULL;
    this->Direction = NULL;
    this->SearchDistance = 100.00f;
    this->OffsetDistance = 0.00f;
    this->TraceType = TraceTypeQuery1;
}

