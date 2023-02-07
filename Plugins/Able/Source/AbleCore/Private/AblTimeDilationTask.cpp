#include "AblTimeDilationTask.h"

UAblTimeDilationTask::UAblTimeDilationTask() {
    this->TimeDilationTarget = ETimeDilationTarget::World;
    this->TimeDilationCurve = NULL;
    this->TimeDilation = 1.00f;
    this->EaseInDuration = 0.15f;
    this->bCounterWorld = false;
    this->bEndTaskOnReactionDone = false;
    this->bTestAgainstWorldTime = false;
}

