#include "BlendDomainParentVisibilityComponent.h"

class UBlendDomainParentVisibilityComponent;
class USceneComponent;

UBlendDomainParentVisibilityComponent* UBlendDomainParentVisibilityComponent::CreateForParentComponent(USceneComponent* Parent, bool bTransient, bool bStartEnabled) {
    return NULL;
}

UBlendDomainParentVisibilityComponent::UBlendDomainParentVisibilityComponent() {
    this->bPropagateToChildren = false;
}

