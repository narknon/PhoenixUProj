#include "EnemyAIAttackDistTableData.h"

FEnemyAIAttackDistTableData::FEnemyAIAttackDistTableData() {
    this->m_stateType = EEnemyAIAttackStateType::None;
    this->m_state = EEnemyAIAttackState::None;
    this->AttackMinRange = 0.00f;
    this->ApproachMinRange = 0.00f;
    this->ApproachMaxRange = 0.00f;
    this->AttackMaxRange = 0.00f;
    this->ApproachTolerance = 0.00f;
    this->AttackRangeTolerance = 0.00f;
}

