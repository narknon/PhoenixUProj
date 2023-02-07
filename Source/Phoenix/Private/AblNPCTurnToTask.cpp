#include "AblNPCTurnToTask.h"

UAblNPCTurnToTask::UAblNPCTurnToTask() {
    this->RotationTarget = EAblNPCTurnToTaskDestination::Self;
    this->bTrackTarget = false;
    this->SetYaw = true;
    this->SetPitch = false;
}

