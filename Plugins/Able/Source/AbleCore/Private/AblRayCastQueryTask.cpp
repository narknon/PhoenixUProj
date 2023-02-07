#include "AblRayCastQueryTask.h"

UAblRayCastQueryTask::UAblRayCastQueryTask() {
    this->m_Length = 100.00f;
    this->m_OnlyReturnBlockingHit = false;
    this->m_CollisionChannel = ECC_WorldDynamic;
    this->m_fireEvent = false;
    this->m_CopyResultsToContext = false;
    this->m_AllowDuplicateEntries = false;
    this->m_TaskRealm = EAblAbilityTaskRealm::Server;
    this->m_UseAsyncQuery = false;
}

