#include "AblSetMeshHiddenInGameTask.h"

UAblSetMeshHiddenInGameTask::UAblSetMeshHiddenInGameTask() {
    this->SkeletalMeshTargetInOwner = NULL;
    this->RestoreHiddenValueAtEndOfTask = false;
    this->SetHiddenValue = false;
}

