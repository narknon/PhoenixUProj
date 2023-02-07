#include "AblCollisionSweepTask.h"

UAblCollisionSweepTask::UAblCollisionSweepTask() {
    this->m_SweepShape = NULL;
    this->m_fireEvent = false;
    this->m_CopyResultsToContext = false;
    this->m_AllowDuplicateEntries = false;
    this->m_TaskRealm = EAblAbilityTaskRealm::ClientAndServer;
}

