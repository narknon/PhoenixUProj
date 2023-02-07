#include "AblDamageEventTask.h"

UAblDamageEventTask::UAblDamageEventTask() {
    this->m_damage = 1.00f;
    this->m_DamageSource = Self;
    this->m_TaskRealm = EAblAbilityTaskRealm::ClientAndServer;
    this->m_UseAsyncCalculate = false;
}

