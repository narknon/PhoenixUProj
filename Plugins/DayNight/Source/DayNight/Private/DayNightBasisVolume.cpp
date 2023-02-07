#include "DayNightBasisVolume.h"

void ADayNightBasisVolume::SetPriority(float NewPriority) {
}

ADayNightBasisVolume::ADayNightBasisVolume() {
    this->BasisOverride = NULL;
    this->Priority = 0.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
}

