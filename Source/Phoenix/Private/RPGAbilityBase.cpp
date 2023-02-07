#include "RPGAbilityBase.h"




URPGAbilityBase::URPGAbilityBase() {
    this->bIsStackable = true;
    this->RemainingLifeTime = 0.00f;
    this->OwnerActor = NULL;
    this->bShowIcon = false;
}

