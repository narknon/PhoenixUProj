#include "RPGTriggerEffect_ModifyObjectStateOnTimer.h"

void URPGTriggerEffect_ModifyObjectStateOnTimer::OnTimerTick() {
}

URPGTriggerEffect_ModifyObjectStateOnTimer::URPGTriggerEffect_ModifyObjectStateOnTimer() {
    this->TickRate = 1.00f;
    this->FirstTickDelay = -1.00f;
    this->bLoop = false;
    this->bModifyHealthByValue = false;
    this->HealthModificationAmount = 0.00f;
    this->bModifyHealthByPercentage = false;
    this->HealthModificationPercentage = 0.00f;
}

