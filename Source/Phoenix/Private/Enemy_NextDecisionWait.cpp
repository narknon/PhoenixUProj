#include "Enemy_NextDecisionWait.h"

FEnemy_NextDecisionWait::FEnemy_NextDecisionWait() {
    this->State = EEnemy_AttackUpdateState::None;
    this->Time = 0.00f;
}

