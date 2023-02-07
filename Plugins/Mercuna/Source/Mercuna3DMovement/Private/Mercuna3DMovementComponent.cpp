#include "Mercuna3DMovementComponent.h"

void UMercuna3DMovementComponent::SetVelocity(FVector NewVelocity) {
}

void UMercuna3DMovementComponent::SetAngularVelocity(FVector NewAngVel) {
}

FVector UMercuna3DMovementComponent::GetLocalVelocity() const {
    return FVector{};
}

FRotator UMercuna3DMovementComponent::GetLocalRotationRate() const {
    return FRotator{};
}

void UMercuna3DMovementComponent::AddImpulse(FVector Impulse) {
}

UMercuna3DMovementComponent::UMercuna3DMovementComponent() {
    this->bPositionCorrected = false;
    this->MaxSimulationTimeStep = 0.50f;
    this->MaxSimulationIterations = 1;
}

