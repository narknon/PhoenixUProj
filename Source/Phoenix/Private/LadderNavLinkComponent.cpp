#include "LadderNavLinkComponent.h"

void ULadderNavLinkComponent::UpdateNavLink(const FOdcLadderInfo& Info) {
}

void ULadderNavLinkComponent::RegisterNavLink() {
}

bool ULadderNavLinkComponent::HasValidLinks() const {
    return false;
}

ULadderNavLinkComponent::ULadderNavLinkComponent() {
    this->bIsBottomLinkPosValid = false;
    this->bIsTopLinkPosValid = false;
}

