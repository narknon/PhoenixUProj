#include "Enemy_MobilityMovementData.h"

FEnemy_MobilityMovementData::FEnemy_MobilityMovementData() {
    this->bUseAcceleration = false;
    this->bOrientToMovement = false;
    this->bRestoreTurnRate = false;
    this->TurnRate = 0.00f;
    this->bResetDirection = false;
}

