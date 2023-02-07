#include "AblBlendSpaceParameterGetter_StairsAndSlopes.h"

UAblBlendSpaceParameterGetter_StairsAndSlopes::UAblBlendSpaceParameterGetter_StairsAndSlopes() {
    this->StairsDirection = EStairsDirectionState::None;
    this->MinSlope = 10.00f;
    this->MaxSlope = 30.00f;
    this->bBlendInputOnTransitionOut = true;
    this->bUseVelocity = false;
}

