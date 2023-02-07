#include "StateEffectComponent.h"

void UStateEffectComponent::SetDuration(float InDuration) {
}

void UStateEffectComponent::ResetDuration() {
}

float UStateEffectComponent::GetRemainingTime() const {
    return 0.0f;
}

void UStateEffectComponent::EndEffect() {
}

UStateEffectComponent::UStateEffectComponent() {
    this->ObjectStateInfo = NULL;
    this->Instigator = NULL;
    this->SpellTool = NULL;
}

