#include "AblSetRightArmStateTask.h"

UAblSetRightArmStateTask::UAblSetRightArmStateTask() {
    this->RightArmState = ERightArmState::None;
    this->bUseEndState = false;
    this->EndRightArmState = ERightArmState::None;
    this->RightArmPriority = ERightArmPriority::None;
    this->bBroadcastChange = false;
}

