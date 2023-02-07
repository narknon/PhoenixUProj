#include "AblTargetTrackerTask.h"

UAblTargetTrackerTask::UAblTargetTrackerTask() {
    this->TargetTrackerType = ETask_TargetTrackerType::None;
    this->TargetType = ETask_TargetType::None;
    this->TargetPriority = ETargetID::None;
}

