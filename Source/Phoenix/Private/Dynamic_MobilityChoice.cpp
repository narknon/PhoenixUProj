#include "Dynamic_MobilityChoice.h"

UDynamic_MobilityChoice::UDynamic_MobilityChoice() {
    this->StrafeMinDistToDest = 600.00f;
    this->StrafeMinDistToTarget = 800.00f;
    this->StrafeMaxAngleToDest = 90.00f;
    this->StrafeIgnoreAngleDist = 3000.00f;
    this->SprintMinDist = 800.00f;
    this->SprintDistStart = 2500.00f;
    this->SprintDistStop = 1500.00f;
    this->StartChangeInterval = 1.50f;
    this->ChangeInterval = 1.00f;
    this->DebugMobility = ENPC_Mobility::None;
}

