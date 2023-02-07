#include "AblBlendSpaceParameterGetter_StrafeMoveStop.h"

UAblBlendSpaceParameterGetter_StrafeMoveStop::UAblBlendSpaceParameterGetter_StrafeMoveStop() {
    this->bUseWorldSpeedTracker = true;
    this->bOverrideWalkSpeed = false;
    this->WalkSpeedOverride = 150.00f;
    this->bOverrideJogSpeed = false;
    this->JogSpeedOverride = 450.00f;
}

