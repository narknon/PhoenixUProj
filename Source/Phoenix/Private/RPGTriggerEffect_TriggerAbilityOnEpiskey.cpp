#include "RPGTriggerEffect_TriggerAbilityOnEpiskey.h"

URPGTriggerEffect_TriggerAbilityOnEpiskey::URPGTriggerEffect_TriggerAbilityOnEpiskey() {
    this->AbilityBaseTime = 0.00f;
    this->AbilityTimePerHealth = 0.00f;
    this->AbilityTimeMax = 15.00f;
    this->AbilityOnPlayer = false;
    this->Ability = NULL;
}

