#include "RenderSettingsCustomBlendDomainVolume.h"

void ARenderSettingsCustomBlendDomainVolume::SetPriority(float NewPriority) {
}

ARenderSettingsCustomBlendDomainVolume::ARenderSettingsCustomBlendDomainVolume() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
}

