#include "AblSetMaxHeightModifiersTask.h"

UAblSetMaxHeightModifiersTask::UAblSetMaxHeightModifiersTask() {
    this->bEnableMaxHeightModifiers = true;
    this->bOverrideMaxHeightValue = false;
    this->OverrideMaxHeightValue = 100.00f;
    this->Priority = EStandardManagedPriority::Lowest;
    this->bMustPassAllConditions = false;
}

