#include "ablNPC_TurnAssistTask.h"

UablNPC_TurnAssistTask::UablNPC_TurnAssistTask() {
    this->TurnAssistMode = ENPC_TurnAssist::None;
    this->bUseFixedDirection = false;
    this->FixedSource = EablNPC_FixedSource::Param;
    this->FixedRelativeAngle = 0.00f;
    this->bFollowPlayer = false;
    this->bTurnToPlayer = false;
    this->bFollowTarget = false;
    this->bTurnToTarget = false;
    this->bFollowInstigator = false;
    this->bTurnToInstigator = false;
    this->bIgnoreTargetTracker = false;
}

