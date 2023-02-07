#include "AblBlendSpaceParameterGetter_Sprint.h"

UAblBlendSpaceParameterGetter_Sprint::UAblBlendSpaceParameterGetter_Sprint() {
    this->MaxAngle = 45.00f;
    this->AngleRatioNearZeroTolerance = 0.01f;
    this->XInterpInSpeed = 1.00f;
    this->XInterpInType = ECustomInterpType::EaseIn;
    this->XInterpOutSpeed = 1.00f;
    this->XInterpOutType = ECustomInterpType::EaseIn;
    this->MinSlope = 10.00f;
    this->MaxSlope = 30.00f;
    this->bBlendInputOnTransitionOut = true;
    this->bUseVelocity = false;
}

