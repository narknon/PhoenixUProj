#include "AIPerformTaskCombatMode.h"

void UAIPerformTaskCombatMode::FinishAfterDuration() {
}

UAIPerformTaskCombatMode::UAIPerformTaskCombatMode() {
    this->bStartCombatMode = false;
    this->Duration = 0.00f;
    this->CombatMode = EPerformTaskCombatMode::Normal;
}

