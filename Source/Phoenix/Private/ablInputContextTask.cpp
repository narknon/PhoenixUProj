#include "ablInputContextTask.h"

UablInputContextTask::UablInputContextTask() {
    this->ContextTaskOperation = EContextTaskOperationType::SetAndClear;
    this->bOnlyDoOperationDuringCombatMode = false;
    this->bOnlyDoOperationInNonCombatMode = false;
}

