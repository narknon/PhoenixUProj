#include "LerpVolumeAttached.h"

void ALerpVolumeAttached::SetPriority(float NewPriority) {
}

void ALerpVolumeAttached::Recompute() {
}

ALerpVolumeAttached::ALerpVolumeAttached(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AttachVolume = NULL;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
}

