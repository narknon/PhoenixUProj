#include "AblSetCollisionChannelResponseTask.h"

UAblSetCollisionChannelResponseTask::UAblSetCollisionChannelResponseTask() {
    this->m_Channel = ECC_WorldDynamic;
    this->m_Response = ECR_Ignore;
    this->m_SetAllChannelsToResponse = false;
    this->m_RestoreOnEnd = true;
}

