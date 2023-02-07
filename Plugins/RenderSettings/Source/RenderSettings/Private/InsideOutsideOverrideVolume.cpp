#include "InsideOutsideOverrideVolume.h"

void AInsideOutsideOverrideVolume::SetPriority(float NewPriority) {
}

AInsideOutsideOverrideVolume::AInsideOutsideOverrideVolume() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
}

