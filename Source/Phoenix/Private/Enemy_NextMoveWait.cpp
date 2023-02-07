#include "Enemy_NextMoveWait.h"

FEnemy_NextMoveWait::FEnemy_NextMoveWait() {
    this->State = EEnemy_AttackUpdateState::None;
    this->Time = 0.00f;
}

