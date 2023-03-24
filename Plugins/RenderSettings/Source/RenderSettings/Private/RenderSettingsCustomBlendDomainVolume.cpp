#include "RenderSettingsCustomBlendDomainVolume.h"

void ARenderSettingsCustomBlendDomainVolume::SetPriority(float NewPriority) {
}

ARenderSettingsCustomBlendDomainVolume::ARenderSettingsCustomBlendDomainVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
}

