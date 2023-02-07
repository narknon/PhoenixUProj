#include "RPGTriggerEffect_OnHitBySpell.h"

URPGTriggerEffect_OnHitBySpell::URPGTriggerEffect_OnHitBySpell() {
    this->bCheckSpellGroup = false;
    this->SpellGroup = SOCIAL_SEMANTIC_DADA;
    this->bCheckSpellName = false;
    this->SpellName = SOCIAL_ACTION_STUPEFY;
    this->Owner = NULL;
}

