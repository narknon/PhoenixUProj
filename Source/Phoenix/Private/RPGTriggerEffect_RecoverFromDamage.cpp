#include "RPGTriggerEffect_RecoverFromDamage.h"

URPGTriggerEffect_RecoverFromDamage::URPGTriggerEffect_RecoverFromDamage() {
    this->RequiresCursed = false;
    this->RequiresDeadlySpell = false;
    this->RequiresAirborne = false;
    this->RequiresUnaware = false;
    this->RequiresNotInCombatMode = false;
    this->RequiresRadiantAura = false;
    this->PlayerInstigator = false;
    this->OnPlayer = false;
    this->OnTeammate = false;
    this->OnNeutral = false;
    this->DamageFromFinisher = false;
    this->AdjustmentPerPointOfDamage = true;
    this->CooldownSecondsPerPointOfDamage = 0.00f;
    this->FocusAmount = 0.00f;
    this->HealthAmount = 0.00f;
    this->HealthPercentage = 0.00f;
    this->UseHealthRecoveryEffects = false;
    this->Ability = NULL;
    this->AbilityDuration = -1.00f;
    this->AbilityOnPlayer = false;
    this->AbilityOnInstigator = false;
    this->TriggerEffect = NULL;
}

