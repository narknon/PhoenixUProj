#include "LocalStencilAutoStartComponent.h"

bool ULocalStencilAutoStartComponent::LocalStencilEffectStart() {
    return false;
}

ULocalStencilAutoStartComponent::ULocalStencilAutoStartComponent() {
    this->bStartOnBeginPlay = true;
}

