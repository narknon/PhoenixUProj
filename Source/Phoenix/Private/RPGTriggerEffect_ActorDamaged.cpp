#include "RPGTriggerEffect_ActorDamaged.h"

URPGTriggerEffect_ActorDamaged::URPGTriggerEffect_ActorDamaged() {
    this->OnlyOnCharacterDied = false;
    this->OnEnemy = false;
    this->Owner = NULL;
}

