#include "Enemy_Follow_QBUpdateData.h"

UEnemy_Follow_QBUpdateData::UEnemy_Follow_QBUpdateData() {
    this->MinDistance = 500.00f;
    this->MaxDistance = 2000.00f;
    this->Threshold = 200.00f;
    this->ActorToFollow = NULL;
    this->SuccessCooldown = 5.00f;
    this->FailedCooldown = 2.00f;
    this->MinAngle = 45.00f;
    this->MaxAngle = 60.00f;
}

