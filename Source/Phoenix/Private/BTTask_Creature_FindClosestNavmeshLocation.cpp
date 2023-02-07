#include "BTTask_Creature_FindClosestNavmeshLocation.h"

UBTTask_Creature_FindClosestNavmeshLocation::UBTTask_Creature_FindClosestNavmeshLocation() {
    this->bUseCreaturePreferredAreaFlags = true;
    this->bCheckReachable = false;
    this->bFailIfNoLocationFound = false;
}

