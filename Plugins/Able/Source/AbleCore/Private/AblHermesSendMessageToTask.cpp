#include "AblHermesSendMessageToTask.h"

UAblHermesSendMessageToTask::UAblHermesSendMessageToTask() {
    this->m_MessageSender = Self;
    this->m_MessageTarget = TargetActor;
}

