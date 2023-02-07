#include "PostProcessWithBlendDomainComponent.h"

class IBlendableInterface;
class UBlendableInterface;

void UPostProcessWithBlendDomainComponent::AddOrUpdateBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight) {
}

UPostProcessWithBlendDomainComponent::UPostProcessWithBlendDomainComponent() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbound = true;
}

