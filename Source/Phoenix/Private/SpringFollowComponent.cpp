#include "SpringFollowComponent.h"

void USpringFollowComponent::ResetPhysics() {
}

void USpringFollowComponent::RemoveChildOffset() {
}

USpringFollowComponent::USpringFollowComponent() {
    this->bAlignToVelocity = true;
    this->bSpringActive = true;
}

