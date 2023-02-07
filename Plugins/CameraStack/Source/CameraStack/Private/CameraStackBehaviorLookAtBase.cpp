#include "CameraStackBehaviorLookAtBase.h"

UCameraStackBehaviorLookAtBase::UCameraStackBehaviorLookAtBase() {
    this->RotationSpeed = 90.00f;
    this->AngleToRotationSpeed = NULL;
    this->bAffectYaw = true;
    this->bAffectPitch = true;
    this->bDisableOnInput = false;
    this->bUseUnblendedStackValues = false;
}

