#include "WorldBaseHeightBase.h"

void AWorldBaseHeightBase::SetPriority(float NewPriority) {
}

AWorldBaseHeightBase::AWorldBaseHeightBase() {
    this->Affects = 7;
    this->Priority = 0.00f;
    this->bEnabled = true;
}

