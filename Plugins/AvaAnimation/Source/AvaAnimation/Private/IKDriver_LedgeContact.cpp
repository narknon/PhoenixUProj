#include "IKDriver_LedgeContact.h"

UIKDriver_LedgeContact::UIKDriver_LedgeContact() {
    this->LedgePoseAnimSequence = NULL;
    this->LedgePoseTime = 0.00f;
    this->TraceChannel = ECC_WorldStatic;
}

