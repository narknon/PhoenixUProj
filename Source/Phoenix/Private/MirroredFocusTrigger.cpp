#include "MirroredFocusTrigger.h"

AMirroredFocusTrigger::AMirroredFocusTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MirroredFocusProbablity = 1.00f;
    this->MirroredCalloutProbablity = 0.60f;
    this->MirroredPlayerFocusProbablity = 1.00f;
    this->MirroredPlayerCalloutProbablity = 0.00f;
    this->bUseCalloutOffset = false;
}

