#include "ClimbSettings.h"

FClimbSettings::FClimbSettings() {
    this->bForceReachingClimbLinkEndLocation = false;
    this->bSnapRotationBeforeClimb = false;
    this->ClimbAbility = NULL;
    this->JumpToClimbAbility = NULL;
    this->SwimClimbAbility = NULL;
}

