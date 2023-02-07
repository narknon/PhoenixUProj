#include "AIPerformTaskRotateTo.h"

void UAIPerformTaskRotateTo::RotateToComplete(EEnemyAIAction InAction, EEnemyAIActionDoneReason InReason) {
}

UAIPerformTaskRotateTo::UAIPerformTaskRotateTo() {
    this->Yaw = 0.00f;
    this->bRelative = false;
}

