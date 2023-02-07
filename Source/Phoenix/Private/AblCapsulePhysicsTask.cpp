#include "AblCapsulePhysicsTask.h"

UAblCapsulePhysicsTask::UAblCapsulePhysicsTask() {
    this->bEnablePhysicsAtStart = false;
    this->bEnableGravityAtStart = false;
    this->bEnablePhysicsAtEnd = false;
    this->bEnableGravityAtEnd = false;
    this->bLockXRotation = false;
    this->bLockYRotation = false;
    this->bLockZRotation = false;
    this->LinearDampening = 0.50f;
}

