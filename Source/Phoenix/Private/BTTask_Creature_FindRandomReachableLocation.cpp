#include "BTTask_Creature_FindRandomReachableLocation.h"

UBTTask_Creature_FindRandomReachableLocation::UBTTask_Creature_FindRandomReachableLocation() {
    this->LocationTestRadius = 100.00f;
    this->bCheckLocationHasPreferredAreaFlag = false;
    this->bCheckLocationForDistanceToPath = true;
    this->bCheckLocationForMaxGroundSlope = true;
    this->bUseMaxHeadingAngle = false;
    this->MaxHeadingAngleFromForward = 180.00f;
    this->bUseTether = true;
    this->bFailIfNoLocationFound = false;
    this->bReportErrorOnFailure = false;
    this->ErrorTimeout = 5.00f;
    this->SearchTicks = 10;
    this->SearchTriesPerTick = 1;
    this->SearchReductions = 2;
}

