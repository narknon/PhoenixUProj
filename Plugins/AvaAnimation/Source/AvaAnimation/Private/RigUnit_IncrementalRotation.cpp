#include "RigUnit_IncrementalRotation.h"

FRigUnit_IncrementalRotation::FRigUnit_IncrementalRotation() {
    this->Blending = 0.00f;
    this->RotationEaseType = EControlRigAnimEasingType::Linear;
    this->bPropagateToChildren = false;
}

