#include "CombatParryButtonCallout.h"

void UCombatParryButtonCallout::SetPerfectTimingState(const bool bPerfectTiming) {
}

void UCombatParryButtonCallout::SetParryType(const ECombatParryType ParryType) {
}

void UCombatParryButtonCallout::SetExpectedLifetime(float LifeTime) {
}




UCombatParryButtonCallout::UCombatParryButtonCallout() {
    this->CombatParryType = ECombatParryType::CPT_Parry;
    this->bInPerfectTimingWindow = false;
    this->ExpectedLifetime = 0.00f;
}

