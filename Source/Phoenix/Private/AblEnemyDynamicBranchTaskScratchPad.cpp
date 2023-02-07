#include "AblEnemyDynamicBranchTaskScratchPad.h"

UAblEnemyDynamicBranchTaskScratchPad::UAblEnemyDynamicBranchTaskScratchPad() {
    this->ElapsedTime = 0.00f;
    this->TaskState = EEnemy_Ability::Idle;
    this->BranchCriteriaFromParent = false;
}

