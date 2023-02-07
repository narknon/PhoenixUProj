#include "AblTaskConditionScratchpad_OppugnoProxy.h"

class ATool;

void UAblTaskConditionScratchpad_OppugnoProxy::OnActiveSpellToolChanged(ATool* ActivatedSpell, ATool* DeactivatedSpell) {
}

UAblTaskConditionScratchpad_OppugnoProxy::UAblTaskConditionScratchpad_OppugnoProxy() {
    this->instancedProxy = NULL;
    this->EnemyOwner = NULL;
}

