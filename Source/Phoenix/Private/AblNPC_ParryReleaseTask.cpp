#include "AblNPC_ParryReleaseTask.h"

UAblNPC_ParryReleaseTask::UAblNPC_ParryReleaseTask() {
    this->bOverrideDBParryToRelease = false;
    this->ParryToRelease = 5.00f;
    this->bTriggerFiredEvent = false;
    this->FiredEventType = EEnemy_ParryType::None;
}

