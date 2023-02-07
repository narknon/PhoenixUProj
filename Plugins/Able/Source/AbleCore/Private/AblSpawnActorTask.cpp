#include "AblSpawnActorTask.h"

UAblSpawnActorTask::UAblSpawnActorTask() {
    this->m_actorClass = NULL;
    this->m_SetOwner = true;
    this->m_OwnerTargetType = Self;
    this->m_AttachToOwnerSocket = false;
    this->m_AttachmentRule = EAttachmentRule::KeepRelative;
    this->m_InheritOwnerLinearVelocity = false;
    this->m_MarkAsTransient = true;
    this->m_DestroyAtEnd = false;
    this->m_fireEvent = false;
}

