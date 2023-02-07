#include "ablAbilityDoneTask.h"

UablAbilityDoneTask::UablAbilityDoneTask() {
    this->NextAbility = EEnemy_Ability::Idle;
    this->bDelayBranchIfNextIsIdle = false;
    this->bMustPassAllConditions = true;
}

