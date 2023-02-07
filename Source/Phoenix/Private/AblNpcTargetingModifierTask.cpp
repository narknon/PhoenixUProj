#include "AblNpcTargetingModifierTask.h"

UAblNpcTargetingModifierTask::UAblNpcTargetingModifierTask() {
    this->bModifyTargetingModifierAtTaskStart = false;
    this->TargetingModifierAtTaskStart = 1.00f;
    this->bModifyTargetingModifierAtTaskEnd = false;
    this->TargetingModifierAtTaskEnd = 1.00f;
    this->bRestoreTargetingModifierAtTaskEnd = true;
}

