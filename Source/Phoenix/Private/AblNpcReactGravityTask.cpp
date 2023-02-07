#include "AblNpcReactGravityTask.h"

UAblNpcReactGravityTask::UAblNpcReactGravityTask() {
    this->bModifyGravityAtTaskStart = false;
    this->TaskStartGravityMultiplier = 1.00f;
    this->bModifyGravityAtTaskEnd = false;
    this->TaskEndGravityMultiplier = 1.00f;
    this->bRestoreGravityAtTaskEnd = true;
}

