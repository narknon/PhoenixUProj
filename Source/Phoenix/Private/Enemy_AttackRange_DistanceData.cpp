#include "Enemy_AttackRange_DistanceData.h"

FEnemy_AttackRange_DistanceData::FEnemy_AttackRange_DistanceData() {
    this->EnemyMoveState = EEnemyMovementState::Stop;
    this->MinDistance = 0.00f;
    this->MaxDistance = 0.00f;
}

