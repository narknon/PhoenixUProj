#include "Ambulatory_MobilityMode.h"

FAmbulatory_MobilityMode::FAmbulatory_MobilityMode() {
    this->bApplyMovementSpeeds = false;
    this->MinimumMovementSpeed = 0.00f;
    this->MaximumMovementSpeed = 0.00f;
    this->SlowWalkTargetSpeed = 0.00f;
    this->WalkTargetSpeed = 0.00f;
    this->JogTargetSpeed = 0.00f;
    this->SprintTargetSpeed = 0.00f;
    this->UseStrafe = false;
}

