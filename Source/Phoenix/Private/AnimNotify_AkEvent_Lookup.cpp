#include "AnimNotify_AkEvent_Lookup.h"

UAnimNotify_AkEvent_Lookup::UAnimNotify_AkEvent_Lookup() {
    this->bFollow = true;
    this->bObstructionAndOcclusion = true;
    this->MaxDistanceToListener = 5000.00f;
    this->bUseMotionListener = false;
    this->bUsePlayerOrientation = false;
}

