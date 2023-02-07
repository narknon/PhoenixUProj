#include "AblCollisionQueryTask.h"

UAblCollisionQueryTask::UAblCollisionQueryTask() {
    this->m_fireEvent = false;
    this->m_QueryShape = NULL;
    this->m_CopyResultsToContext = false;
    this->m_AllowDuplicateEntries = false;
    this->m_TaskRealm = EAblAbilityTaskRealm::ClientAndServer;
}

