#include "RPGAbilityEventListener.h"

URPGAbilityEventListener::URPGAbilityEventListener() {
    this->bTriggerRandom = false;
    this->RandomTriggerChance = 100.00f;
    this->OwnerActor = NULL;
    this->ModComponent = NULL;
    this->AbilityComponent = NULL;
    this->bTriggered = false;
}

