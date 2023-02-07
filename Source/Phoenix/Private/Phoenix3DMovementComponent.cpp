#include "Phoenix3DMovementComponent.h"

void UPhoenix3DMovementComponent::OnFullRagdollStart() {
}

UPhoenix3DMovementComponent::UPhoenix3DMovementComponent() {
    this->bEnableRootMotion = true;
    this->bEnablePhysicsInteraction = true;
    this->bPushForceScaledToMass = false;
    this->bPushForceUsingZOffset = false;
    this->bScalePushForceToVelocity = true;
    this->InitialPushForceFactor = 500.00f;
    this->PushForceFactor = 750000.00f;
    this->PushForcePointZOffsetFactor = -0.75f;
}

