#include "IKDriver_LadderContactControl.h"

FIKDriver_LadderContactControl::FIKDriver_LadderContactControl() {
    this->Enable = false;
    this->DebugDraw = false;
    this->OffsetZ = 0.00f;
    this->HandOffset = 0.00f;
    this->LadderUpPlaneOffset = 0.00f;
    this->LadderDownPlaneOffset = 0.00f;
    this->LockVelocityThreshold = 0.00f;
    this->UnlockVelocityThreshold = 0.00f;
    this->UnlockMoveThreshold = 0.00f;
    this->JumpToNextRungThreshold = 0.00f;
    this->UnlockPastTopExtentThreshold = 0.00f;
    this->LockBlendTime = 0.00f;
    this->UnlockBlendTime = 0.00f;
    this->InitDelay = 0.00f;
}

