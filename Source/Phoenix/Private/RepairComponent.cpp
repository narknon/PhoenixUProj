#include "RepairComponent.h"

class AActor;
class UPrimitiveComponent;

void URepairComponent::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void URepairComponent::OnChaosPhysicsCollision(const FChaosPhysicsCollisionInfo& CollisionInfo) {
}

void URepairComponent::HandleRemovalCompletedEvent(const FChaosRemovalCompletedEvent& RemovalCompletedEvent) {
}

void URepairComponent::HandleBreakEvent(const FChaosBreakEvent& BreakEvent) {
}

void URepairComponent::EntireRepairComplete() {
}

void URepairComponent::ApplyDestuctiveForce(const FVector& HitLocation, const FVector& HitDirection, float Radius, float ObjectStrain, float ImpulseStrength, float RadialImpulseStrength, float AngularForceMultiplier) {
}

void URepairComponent::AddRadialImpulse(FVector Location, float Radius, float Strength, float AngularForceMultiplier, TEnumAsByte<EFieldFalloffType> Falloff, bool bVelChange) {
}

void URepairComponent::AddImpulse(FVector Impulse, FVector ImpulseLocation, float Radius, float AngularForceMultiplier, TEnumAsByte<EFieldFalloffType> Falloff, bool bVelChange) {
}

URepairComponent::URepairComponent() {
    this->AnchorActor = NULL;
    this->GeometryCollectionComponent = NULL;
    this->DestroyedBaseMesh = NULL;
    this->GeometryCollection = NULL;
    this->RepairInfo = NULL;
}

