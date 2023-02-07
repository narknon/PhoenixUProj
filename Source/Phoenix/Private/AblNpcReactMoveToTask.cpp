#include "AblNpcReactMoveToTask.h"

UAblNpcReactMoveToTask::UAblNpcReactMoveToTask() {
    this->DestinationType = EAblNpcReactMoveToDestinationType::CustomGlobal;
    this->SpeedType = EAblNpcReactMoveToSpeedType::Custom;
    this->Curve = NULL;
    this->CustomSpeed = 100.00f;
    this->bTrackTarget = false;
    this->bStompVelocityAtStart = false;
    this->bDoNotAllowHorizontalMovementAwayFromInstigator = false;
    this->bUseMaxHeight = false;
    this->bIgnoreCapsuleHalfHeight = true;
}

