#include "AblBlendSpaceParameterGetter_Slide.h"

UAblBlendSpaceParameterGetter_Slide::UAblBlendSpaceParameterGetter_Slide() {
    this->NonStickMax = 50.00f;
    this->DeadZone = 20.00f;
    this->XInterpType = ECustomInterpType::EaseInOut;
    this->XInterpSpeed = 0.90f;
    this->XFastInterpType = ECustomInterpType::EaseInOut;
    this->XFastInterpSpeed = 0.10f;
    this->YInterpType = ECustomInterpType::EaseInOut;
    this->YInterpSpeed = 0.90f;
    this->bSlipAndFall = false;
    this->bReverseDirection = false;
    this->bGetBlendParamsFromLast = false;
}

