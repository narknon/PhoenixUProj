#include "BTTask_Creature_SetStance.h"

UBTTask_Creature_SetStance::UBTTask_Creature_SetStance() {
    this->Stance = ECreatureStance::Standing;
    this->bWait = true;
}

