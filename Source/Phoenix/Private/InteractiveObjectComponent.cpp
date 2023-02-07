#include "InteractiveObjectComponent.h"

class UObject;

void UInteractiveObjectComponent::SetState(EInteractiveState State) {
}

void UInteractiveObjectComponent::SetEnabled(bool bEnable) {
}

void UInteractiveObjectComponent::HandleInteract(const UObject* i_caller) {
}

EInteractiveState UInteractiveObjectComponent::GetState() {
    return EInteractiveState::Normal;
}

bool UInteractiveObjectComponent::GetEnabled() {
    return false;
}

void UInteractiveObjectComponent::CheckForStateChange(EInteractiveAction Action) {
}

UInteractiveObjectComponent::UInteractiveObjectComponent() {
    this->m_initialState = EInteractiveState::None;
    this->bCustomInteract = false;
}

