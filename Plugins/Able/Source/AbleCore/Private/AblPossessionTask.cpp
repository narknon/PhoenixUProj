#include "AblPossessionTask.h"

UAblPossessionTask::UAblPossessionTask() {
    this->m_Possessor = Self;
    this->m_PossessionTarget = TargetActor;
    this->m_UnPossessOnEnd = false;
}

