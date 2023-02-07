#include "AblTetherLocSyncPointUpdater.h"

UAblTetherLocSyncPointUpdater::UAblTetherLocSyncPointUpdater() {
    this->TetherDistance = 500.00f;
    this->TetherDistanceRandomFloor = 0.20f;
    this->TetherDistanceRandomCeiling = 1.00f;
    this->StartVectorMethod = EStartVecMethod::None;
    this->MinRandomAngle = 0.00f;
    this->MaxRandomAngle = 180.00f;
    this->MaxTetherAngle = 360.00f;
    this->Divisions = 6;
    this->bInApplyTether = false;
    this->TetherType = ENPC_Tether::None;
    this->DesiredDistanceToTarget = 0.00f;
    this->bAllowPositiveTravel = true;
    this->bAllowNegativeTravel = true;
}

