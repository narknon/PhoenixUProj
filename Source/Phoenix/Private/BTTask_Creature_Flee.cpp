#include "BTTask_Creature_Flee.h"

UBTTask_Creature_Flee::UBTTask_Creature_Flee() {
    this->AcceptableRadius = 5.00f;
    this->MaximumMovementSpeed = ECreatureMovementSpeed::Sprint;
    this->bFollowLeader = false;
    this->bMatchLeadActorGait = false;
    this->SecondsBeforeFade = 5;
    this->SecondsBeforeFinishingTask = -1.00f;
}

