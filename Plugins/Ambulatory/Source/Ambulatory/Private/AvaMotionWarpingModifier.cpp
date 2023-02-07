#include "AvaMotionWarpingModifier.h"

FAvaMotionWarpingModifier::FAvaMotionWarpingModifier() {
    this->StartTime = 0.00f;
    this->EndTime = 0.00f;
    this->PreviousPosition = 0.00f;
    this->CurrentPosition = 0.00f;
    this->weight = 0.00f;
    this->bInLocalSpace = false;
    this->State = EAvaMotionWarpingModifierState::Waiting;
}

