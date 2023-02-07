#include "RPGTriggerEffect_OnEpiskey.h"

class UObject;

void URPGTriggerEffect_OnEpiskey::OnHealing(const UObject* i_caller, float InHealthChange) {
}

URPGTriggerEffect_OnEpiskey::URPGTriggerEffect_OnEpiskey() {
    this->HealthThresholdBefore = 1.00f;
    this->HealthThresholdAfter = 0.00f;
    this->Owner = NULL;
}

