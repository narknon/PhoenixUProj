#include "SlideNavLinkComponent.h"

void USlideNavLinkComponent::UpdateNavLink(const FNavSlideInfo& Info) {
}

void USlideNavLinkComponent::RegisterNavLink() {
}

bool USlideNavLinkComponent::HasValidLinks() const {
    return false;
}

USlideNavLinkComponent::USlideNavLinkComponent() {
    this->bIsBottomLinkPosValid = false;
    this->bIsTopLinkPosValid = false;
}

