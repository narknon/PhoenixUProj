#include "Ambulatory_MovementComponent.h"

class UObject;

void UAmbulatory_MovementComponent::ZeroVelocity() {
}

void UAmbulatory_MovementComponent::ZeroLinearVelocity() {
}

void UAmbulatory_MovementComponent::UpdateSharedContinuousImpulse(FSharedContinuousImpulseHelper ImpulseContainer, const FVector& InImpulse, bool bInIgnoreMass) {
}

FSharedContinuousImpulseHelper UAmbulatory_MovementComponent::SetSharedContinuousLinearImpulse(const FVector& InImpulse) {
    return FSharedContinuousImpulseHelper{};
}

void UAmbulatory_MovementComponent::SetFrictionOverride(const float InFrictionOverride) {
}

void UAmbulatory_MovementComponent::SetFallImpulse(const FVector& Impulse) {
}

void UAmbulatory_MovementComponent::SetAllowTransitionalImpulse(bool bFlag) {
}

void UAmbulatory_MovementComponent::HermesBindSurfaceTypeChanged(FHermesSurfaceTypeChangedDelegate Delegate_SurfaceTypeChanged, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

float UAmbulatory_MovementComponent::GetSurfaceIncline() {
    return 0.0f;
}

FVector UAmbulatory_MovementComponent::GetFallLineFlat() {
    return FVector{};
}

FVector UAmbulatory_MovementComponent::GetFallLine() {
    return FVector{};
}

float UAmbulatory_MovementComponent::GetFallAlongSurfaceDistance() {
    return 0.0f;
}

TEnumAsByte<EPhysicalSurface> UAmbulatory_MovementComponent::GetCurrentSurfaceType() {
    return SurfaceType_Default;
}

FVector UAmbulatory_MovementComponent::GetAdditiveToRootMotionVelocity() const {
    return FVector{};
}

FVector UAmbulatory_MovementComponent::ComputeSurfaceAccelerationDirection(bool& bFlatGround) {
    return FVector{};
}

void UAmbulatory_MovementComponent::ClearTransitionalImpulse() {
}

void UAmbulatory_MovementComponent::ClearSharedContinuousImpulse(FSharedContinuousImpulseHelper ImpulseContainer) {
}

void UAmbulatory_MovementComponent::ClearLastSurfaceType() {
}

void UAmbulatory_MovementComponent::ClearAdditiveToRootMotionVelocity() {
}

void UAmbulatory_MovementComponent::AddToRootMotionVelocity(const FVector InAdditiveToRootMotionVelocity) {
}

UAmbulatory_MovementComponent::UAmbulatory_MovementComponent() {
    this->bOverridePhysWalking = true;
    this->bComputeDistanceToSurfaceWhenFalling = false;
    this->SuckHeight = 10.00f;
    this->bAllowTransitionalImpulse = false;
    this->AdditionalGravityScale = 1.00f;
    this->bUseNavMetricsForStepUp = false;
    this->bMitigateStuckFalling = false;
    this->bMitigateStuckPenetratingExtraMovementCapsule = false;
    this->bCanEverStepOutOfWater = true;
    this->bUseWaterSurfaceForStepUp = false;
    this->SwimDepth = 0.00f;
    this->WaterDepth = 0.00f;
    this->WaterLevel = 0.00f;
    this->FluidFriction = 0.35f;
    this->WaterTerminalVelocity = 4000.00f;
    this->FlowForceScale = 1.00f;
    this->bApplyMaxFlowForceLimit = false;
    this->MaxFlowForce = 75.00f;
    this->bDisableSurfaceAcceleration = false;
    this->AbleAbilityComponent = NULL;
    this->SkeletalMeshComponent = NULL;
}

