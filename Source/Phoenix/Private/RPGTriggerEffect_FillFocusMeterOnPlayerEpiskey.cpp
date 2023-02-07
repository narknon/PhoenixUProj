#include "RPGTriggerEffect_FillFocusMeterOnPlayerEpiskey.h"

class AActor;

void URPGTriggerEffect_FillFocusMeterOnPlayerEpiskey::OnEpiskeyHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor) {
}

URPGTriggerEffect_FillFocusMeterOnPlayerEpiskey::URPGTriggerEffect_FillFocusMeterOnPlayerEpiskey() {
    this->HealthThresholdBefore = 1.00f;
    this->HealthToFocusRatio = 1.00f;
    this->Owner = NULL;
}

