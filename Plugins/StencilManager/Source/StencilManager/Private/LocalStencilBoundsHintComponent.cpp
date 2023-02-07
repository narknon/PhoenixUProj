#include "LocalStencilBoundsHintComponent.h"

ULocalStencilBoundsHintComponent::ULocalStencilBoundsHintComponent() {
    this->Mode = ELocalStencilBoundsHintMode::Override;
    this->bIgnoreVisibility = true;
    this->bEnabled = true;
}

