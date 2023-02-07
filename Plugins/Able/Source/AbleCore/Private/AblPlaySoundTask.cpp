#include "AblPlaySoundTask.h"

UAblPlaySoundTask::UAblPlaySoundTask() {
    this->m_Sound = NULL;
    this->m_2DSound = false;
    this->m_AttachToSocket = false;
    this->m_DestroyOnEnd = false;
    this->m_DestroyFadeOutDuration = 0.25f;
}

