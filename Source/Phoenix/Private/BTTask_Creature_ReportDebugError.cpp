#include "BTTask_Creature_ReportDebugError.h"

UBTTask_Creature_ReportDebugError::UBTTask_Creature_ReportDebugError() {
    this->ErrorText = TEXT("Undefined Error");
    this->bPersistent = false;
    this->LifeTime = 5.00f;
    this->bRemoveExistingPersistentErrors = false;
}

