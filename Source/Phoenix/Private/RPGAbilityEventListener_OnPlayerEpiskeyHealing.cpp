#include "RPGAbilityEventListener_OnPlayerEpiskeyHealing.h"

class AActor;

void URPGAbilityEventListener_OnPlayerEpiskeyHealing::OnEpiskeyHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor) {
}

URPGAbilityEventListener_OnPlayerEpiskeyHealing::URPGAbilityEventListener_OnPlayerEpiskeyHealing() {
    this->HealthThresholdBefore = 1.00f;
}

