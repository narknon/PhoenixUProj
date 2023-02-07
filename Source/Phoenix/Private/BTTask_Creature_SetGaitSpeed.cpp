#include "BTTask_Creature_SetGaitSpeed.h"

UBTTask_Creature_SetGaitSpeed::UBTTask_Creature_SetGaitSpeed() {
    this->bSetGait = true;
    this->Gait = ECreatureMovementSpeed::Stop;
    this->bSetPathEndMode = true;
    this->PathEndMode = ECreaturePathEndMode::Stop;
    this->bSetStoppingMode = true;
    this->StoppingMode = ECreatureStoppingMode::Rapid;
}

