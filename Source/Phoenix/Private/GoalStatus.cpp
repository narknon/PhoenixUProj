#include "GoalStatus.h"

FGoalStatus::FGoalStatus() {
    this->GoalIsActive = false;
    this->SiteIsActive = false;
    this->StationIsActive = false;
    this->Status = EGoalStatusFlags::STATUS_FLAG_NONE;
}

