#include "AblCustomEventTask.h"

UAblCustomEventTask::UAblCustomEventTask() {
    this->m_TaskRealm = EAblAbilityTaskRealm::Client;
    this->bNotifyOtherAbilitiesOnChannel = false;
}

