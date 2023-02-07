#include "IcarusNavigationComponent.h"

void UIcarusNavigationComponent::SetUseTurnSmoothing(bool bInUseTurnSmoothing) {
}

bool UIcarusNavigationComponent::GetUseTurnSmoothing() const {
    return false;
}

UIcarusNavigationComponent::UIcarusNavigationComponent() {
    this->TurningCircleLookAheadTime = 0.25f;
    this->CurrentPath = NULL;
    this->NewPath = NULL;
}

