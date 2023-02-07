#include "EmissiveAdaptationOverrideComponent.h"

void UEmissiveAdaptationOverrideComponent::SetState(EEmissiveAdaptationOverrideState NewState) {
}

void UEmissiveAdaptationOverrideComponent::Reset() {
}

void UEmissiveAdaptationOverrideComponent::GetState(EEmissiveAdaptationOverrideState& CurrentState) const {
}

UEmissiveAdaptationOverrideComponent::UEmissiveAdaptationOverrideComponent() {
    this->BlendInTime = 0.00f;
    this->SustainTime = 0.00f;
    this->BlendOutTime = 0.00f;
    this->Priority = 0.00f;
    this->bInfiniteSustain = true;
    this->bAutoStart = false;
    this->bUsePriority = false;
    this->StateStartTime = 0.00f;
    this->State = EEmissiveAdaptationOverrideState::Begin;
    this->bRegisteredAdaptationInterface = false;
}

