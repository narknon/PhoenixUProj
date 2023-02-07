#include "RPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent.h"

URPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent::URPGTriggerEffect_OnSuccessfulSpell_BroadcastAIEvent() {
    this->WandTool = NULL;
    this->bCheckSpellGroup = false;
    this->RequiredSpellGroup = SOCIAL_SEMANTIC_DARKARTS;
    this->bRequiresCharacterTarget = false;
}

