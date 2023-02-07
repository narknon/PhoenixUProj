#include "VelocityTrackerComponent.h"

class AActor;
class UScheduledEntity;

void UVelocityTrackerComponent::SetMaintainVelocity(FVector Velocity, float Time) {
}

void UVelocityTrackerComponent::SetLastVelocity(FVector Vel) {
}

void UVelocityTrackerComponent::SetInstigator(AActor* InInstigator) {
}

void UVelocityTrackerComponent::SetComponentLifetime(float Seconds) {
}

void UVelocityTrackerComponent::ResetComponentLifetime() {
}

void UVelocityTrackerComponent::RemoveWhenStopped(bool Value) {
}

void UVelocityTrackerComponent::OnFleshDestroyed(AActor* InActor, UScheduledEntity* InScheduledEntity) {
}

AActor* UVelocityTrackerComponent::GetInstigator() const {
    return NULL;
}

UVelocityTrackerComponent::UVelocityTrackerComponent() {
    this->ComponentLifetime = 10.00f;
    this->Instigator = NULL;
    this->SendTargetActor = NULL;
    this->ObjectStateInfo = NULL;
    this->MovementComponent = NULL;
}

