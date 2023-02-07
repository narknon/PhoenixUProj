#include "RootMotionModifierProperties_SplineLock.h"

URootMotionModifierProperties_SplineLock::URootMotionModifierProperties_SplineLock() {
    this->MaxOffset = 0.00f;
    this->bAllowReverseDirection = true;
    this->bAllowOrientReverseDirection = true;
    this->bLimitToEndPoints = false;
    this->OffsetInterpType = ECustomInterpType::EaseInOut;
    this->OffsetInterpSpeed = 0.90f;
    this->bLockIn2D = true;
    this->bZeroOutRootMotionNotInSplineDirection = false;
    this->bOrientToSplineDirection = false;
    this->RotationInterpType = ECustomInterpType::EaseInOut;
    this->RotationInterpSpeed = 0.90f;
}

