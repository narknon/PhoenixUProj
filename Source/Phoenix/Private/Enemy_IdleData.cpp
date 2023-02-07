#include "Enemy_IdleData.h"

FEnemy_IdleData::FEnemy_IdleData() {
    this->bEnable = false;
    this->AtLocationRadius = 0.00f;
    this->SuccessCooldown = 0.00f;
    this->SuccessCooldownDeviation = 0.00f;
    this->FailedCooldown = 0.00f;
    this->FailedCooldownDeviation = 0.00f;
    this->AbortMaxAngle = 0.00f;
    this->AbortMinDist = 0.00f;
    this->AbortChanceIfTicketAvailable = 0.00f;
    this->IAAsset = NULL;
}

