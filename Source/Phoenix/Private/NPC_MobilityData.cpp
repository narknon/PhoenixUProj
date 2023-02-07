#include "NPC_MobilityData.h"

FNPC_MobilityData::FNPC_MobilityData() {
    this->bApplySpeed = false;
    this->SpeedMin = 0.00f;
    this->SpeedMax = 0.00f;
    this->MaxTravelDist = 0.00f;
    this->EnergyCost = 0.00f;
    this->MoveDistThreshold = 0.00f;
    this->DestinationTolerance = 0.00f;
    this->MoveMaxHeadingChangeAngle = 0.00f;
    this->MoveToWaypointOffScreen = false;
    this->bMoveStopOnOverlap = false;
    this->bDoLOSCheck = false;
    this->LOSCollisionInterval = 0.00f;
    this->LOSCollisionDist = 0.00f;
    this->bUseCorridorCheck = false;
    this->bDoRunPastCheck = false;
    this->bDoWaypointAwayCheck = false;
    this->bDoProgressTowardsCheck = false;
    this->bDoDestinationAwayCheck = false;
    this->bAbruptDestinationChangeCheck = false;
    this->AbruptDestinationChangeAngle = 0.00f;
    this->PathSpec = ENPC_PathSpec::None;
}

