#include "CreatureCombatAttackData.h"

UCreatureCombatAttackData::UCreatureCombatAttackData() {
    this->AttackCommitTime = 0.00f;
    this->AttackPatternWeight = 1.00f;
    this->bAttackRequiresStraightLineReachable = false;
    this->StraightLineReachableDistanceThreshold = 0.00f;
    this->bUseAttackExecutionPathSpec = true;
}

