#include "RenderSettingsCustomBlendDomainVolumeAttached.h"

void ARenderSettingsCustomBlendDomainVolumeAttached::SetPriority(float NewPriority) {
}

ARenderSettingsCustomBlendDomainVolumeAttached::ARenderSettingsCustomBlendDomainVolumeAttached(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AttachTo = NULL;
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
}

