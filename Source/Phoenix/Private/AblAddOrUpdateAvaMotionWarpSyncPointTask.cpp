#include "AblAddOrUpdateAvaMotionWarpSyncPointTask.h"

UAblAddOrUpdateAvaMotionWarpSyncPointTask::UAblAddOrUpdateAvaMotionWarpSyncPointTask() {
    this->SyncPointUpdater = NULL;
    this->bUpdateSyncPointOnTick = false;
    this->bRemoveSyncPointOnEndOfTask = true;
}

