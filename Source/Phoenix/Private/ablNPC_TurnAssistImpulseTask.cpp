#include "ablNPC_TurnAssistImpulseTask.h"

UablNPC_TurnAssistImpulseTask::UablNPC_TurnAssistImpulseTask() {
    this->TurnAssistType = ENPC_TurnAssistType::None;
    this->bAllowFollow = false;
    this->RelativeAngle = 0.00f;
    this->TurnAssistMode = ENPC_TurnAssist::None;
}

