#include "AblBlendSpaceParameterGetter_MoveFwdLoop.h"

UAblBlendSpaceParameterGetter_MoveFwdLoop::UAblBlendSpaceParameterGetter_MoveFwdLoop() {
    this->InterpSpeed = 1.00f;
    this->WadingInterpSpeed = 1.00f;
    this->InterpType = ECustomInterpType::Interp;
    this->bBlendInputOnTransitionOut = true;
    this->bUseVelocity = false;
}

