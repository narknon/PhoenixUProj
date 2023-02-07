#include "RPGTriggerEffect_ManageTacticianTokens.h"

URPGTriggerEffect_ManageTacticianTokens::URPGTriggerEffect_ManageTacticianTokens() {
    this->MaxTokens = 5;
    this->Ability = NULL;
    this->AbilityDuration = -1.00f;
    this->AbilityOnPlayer = false;
}

