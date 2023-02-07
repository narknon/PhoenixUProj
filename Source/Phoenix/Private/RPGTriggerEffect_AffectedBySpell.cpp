#include "RPGTriggerEffect_AffectedBySpell.h"

URPGTriggerEffect_AffectedBySpell::URPGTriggerEffect_AffectedBySpell() {
    this->TargetIsPlayer = false;
    this->TargetIsTeammate = false;
    this->TargetIsEnemy = false;
    this->TargetIsNeutral = false;
    this->InstigatorIsPlayer = true;
    this->InstigatorIsCompanion = false;
    this->RequiresCursed = false;
    this->RequiresAirborne = false;
    this->RequiresUnaware = false;
    this->RequiresRadiantAura = false;
    this->FocusAmount = 0.00f;
    this->TriggerEffect = NULL;
    this->TriggerEffectOnPlayer = false;
    this->TriggerEffectOnInstigator = false;
    this->Owner = NULL;
}

