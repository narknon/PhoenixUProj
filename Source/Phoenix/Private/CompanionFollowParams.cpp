#include "CompanionFollowParams.h"

FCompanionFollowParams::FCompanionFollowParams() {
    this->ReachDistance = 0.00f;
    this->BufferDistance = 0.00f;
    this->bShouldUseTimer = false;
    this->movementDelayTimer = 0.00f;
    this->BypassMovementDelayTimerDistance = 0.00f;
}

