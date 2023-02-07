#include "AblAbilityTask.h"

UAblAbilityTask::UAblAbilityTask() {
    this->m_TaskTargets.AddDefaulted(1);
    this->m_Verbose = false;
    this->m_IsDone = false;
}

