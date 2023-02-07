#include "AblPushAwayFromInstigatorTask.h"

UAblPushAwayFromInstigatorTask::UAblPushAwayFromInstigatorTask() {
    this->Distance = 300.00f;
    this->Speed = 500.00f;
    this->bContinuousDistanceCheck = true;
    this->bIncludeCapsuleSizeInDistanceCheck = true;
}

