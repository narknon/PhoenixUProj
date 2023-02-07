#include "RPGAbilityEventListener_OnTargetHitWithMunition.h"

class UObject;

void URPGAbilityEventListener_OnTargetHitWithMunition::OnMunitionHit(const UObject* Caller, const FMunitionToInstigatorData& MunitionData) {
}

URPGAbilityEventListener_OnTargetHitWithMunition::URPGAbilityEventListener_OnTargetHitWithMunition() {
    this->MunitionTypeFilter = NULL;
}

