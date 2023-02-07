#include "RenderSettingsCustomBlendDomainComponent.h"

void URenderSettingsCustomBlendDomainComponent::SetPriority(float NewPriority) {
}

URenderSettingsCustomBlendDomainComponent::URenderSettingsCustomBlendDomainComponent() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
}

