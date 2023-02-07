#include "BlendDomainChildVisibilityComponent.h"

class UBlendDomainChildVisibilityComponent;
class USceneComponent;

UBlendDomainChildVisibilityComponent* UBlendDomainChildVisibilityComponent::CreateForChildComponents(USceneComponent* Parent, bool bTransient, bool bStartEnabled) {
    return NULL;
}

UBlendDomainChildVisibilityComponent::UBlendDomainChildVisibilityComponent() {
    this->bChildrenOfChildren = true;
}

