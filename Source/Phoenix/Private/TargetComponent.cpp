#include "TargetComponent.h"

void UTargetComponent::SetSendTargetPriority(uint8 InPriority) {
}

void UTargetComponent::SetEnabled(bool bInEnabled) {
}

bool UTargetComponent::IsEnabled() const {
    return false;
}

uint8 UTargetComponent::GetSendTargetPriority() const {
    return 0;
}

UTargetComponent::UTargetComponent() {
    this->Priority = 0;
    this->bEnabled = true;
}

