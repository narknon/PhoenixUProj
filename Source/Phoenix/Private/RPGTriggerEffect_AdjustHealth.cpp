#include "RPGTriggerEffect_AdjustHealth.h"

URPGTriggerEffect_AdjustHealth::URPGTriggerEffect_AdjustHealth() {
    this->bRelyOnItemEffectiveness = false;
    this->HealthAdjustAmount = 0.00f;
    this->bAdjustAsPercentage = false;
    this->bApplyOnce = false;
    this->Duration = -1.00f;
}

