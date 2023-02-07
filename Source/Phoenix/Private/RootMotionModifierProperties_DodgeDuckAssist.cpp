#include "RootMotionModifierProperties_DodgeDuckAssist.h"

URootMotionModifierProperties_DodgeDuckAssist::URootMotionModifierProperties_DodgeDuckAssist() {
    this->bInstantRecovery = false;
    this->YawRecoverySpeed = 360.00f;
    this->TurnAssistSpeed = 0.00f;
    this->TurnAssistType = ECustomInterpType::None;
}

