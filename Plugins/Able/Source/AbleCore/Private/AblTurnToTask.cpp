#include "AblTurnToTask.h"

UAblTurnToTask::UAblTurnToTask() {
    this->m_RotationTarget = TargetActor;
    this->m_TrackTarget = false;
    this->m_SetYaw = true;
    this->m_SetPitch = false;
}

