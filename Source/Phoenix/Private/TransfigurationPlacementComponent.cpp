#include "TransfigurationPlacementComponent.h"

class UPrimitiveComponent;

void UTransfigurationPlacementComponent::SetTargetTransform(const FTransform InTransform) {
}

void UTransfigurationPlacementComponent::GrabComponent(UPrimitiveComponent* InComponent, const FName InBoneName, const FVector InGrabLocation) {
}

FTransform UTransfigurationPlacementComponent::GetTargetTransform() const {
    return FTransform{};
}

UTransfigurationPlacementComponent::UTransfigurationPlacementComponent() {
    this->PhysicsHandleLinearStiffness = 750.00f;
    this->PhysicsHandleLinearDamping = 200.00f;
    this->bConstrainAngular = true;
    this->PhysicsHandleAngularStiffness = 750.00f;
    this->PhysicsHandleAngularDamping = 500.00f;
    this->PhysicsHandleInterpolationSpeed = 50.00f;
    this->TransitionDuration = 2.00f;
    this->PhysicsHandleComponent = NULL;
}

