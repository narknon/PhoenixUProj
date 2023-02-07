#include "AblPlayDialogTask.h"

UAblPlayDialogTask::UAblPlayDialogTask() {
    this->DialogEvent = NULL;
    this->bStopWhenAttachedToDestroyed = false;
    this->bStopDialogueOnEndTask = false;
}

