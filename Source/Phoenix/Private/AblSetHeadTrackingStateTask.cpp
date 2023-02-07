#include "AblSetHeadTrackingStateTask.h"

UAblSetHeadTrackingStateTask::UAblSetHeadTrackingStateTask() {
    this->HeadTrackingState = EHeadTrackingState::None;
    this->bUseEndState = false;
    this->EndHeadTrackingState = EHeadTrackingState::None;
    this->HeadTrackingPriority = EHeadTrackingPriority::None;
    this->bBroadcastChange = false;
}

