#include "AblPlayParticleEffectTask.h"

UAblPlayParticleEffectTask::UAblPlayParticleEffectTask() {
    this->m_EffectTemplate = NULL;
    this->m_AttachToSocket = false;
    this->m_UseSocketRotation = false;
    this->m_Scale = 1.00f;
    this->m_DestroyAtEnd = false;
}

