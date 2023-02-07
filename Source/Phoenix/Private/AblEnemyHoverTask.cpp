#include "AblEnemyHoverTask.h"

UAblEnemyHoverTask::UAblEnemyHoverTask() {
    this->Mode = Start;
    this->HoverTime = 0.00f;
    this->AttackerLocationVFX = NULL;
    this->TargetLocationVFX = NULL;
    this->AttackLandVFX = NULL;
}

