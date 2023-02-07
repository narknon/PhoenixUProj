#include "RPGAbilityEventListener_OnSpellCast.h"

class ASpellTool;

void URPGAbilityEventListener_OnSpellCast::OnSpellCast(ASpellTool* SpellTool) {
}

URPGAbilityEventListener_OnSpellCast::URPGAbilityEventListener_OnSpellCast() {
    this->bCheckSpellGroup = false;
    this->SpellGroup = SOCIAL_SEMANTIC_DADA;
    this->bListenToPlayer = false;
    this->Wand = NULL;
}

