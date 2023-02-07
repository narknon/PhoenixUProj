#include "AblBlendSpaceParameterGetter_MoveStrafe.h"

UAblBlendSpaceParameterGetter_MoveStrafe::UAblBlendSpaceParameterGetter_MoveStrafe() {
    this->MagnitudeInterpSpeed = 1.00f;
    this->AngleInterpSpeed = 1.00f;
    this->bBlendInputOnTransitionOut = true;
    this->bUseVelocity = false;
}

