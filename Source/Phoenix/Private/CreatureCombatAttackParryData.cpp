#include "CreatureCombatAttackParryData.h"

FCreatureCombatAttackParryData::FCreatureCombatAttackParryData() {
    this->bUnblockableByPlayer = false;
    this->UnblockableByNPC = EEnemyShieldBreaker::None;
    this->ParryLeadIn = 0.00f;
    this->ParryToRelease = 0.00f;
    this->ParryPerfectBegin = 0.00f;
    this->ParryCounterType = EEnemy_ParryCounterType::Default;
    this->ParryResponseType = EEnemy_ParryResponseType::Default;
    this->ParryCounterStepDirection = EEnemy_ParryCounterStepDirection::Default;
    this->ParryCounterStyle = EEnemy_ParryCounterStyle::Default;
    this->ParryDodgeStyle = EEnemy_ParryDodgeStyle::RollAway;
    this->ParryAbortDistance = 0.00f;
}

