#include "RagdollControlComponent.h"

class AActor;
class USkeletalMeshComponent;

void URagdollControlComponent::StartReaction() {
}

void URagdollControlComponent::StartImpactReaction(EImpactReactionStrength InReactionStrength, const FVector& InWorldLocation, const FVector& InWorldDirection, const float InWorldImpactStrength) {
}

void URagdollControlComponent::ShowImpactReaction(EImpactReactionStrength InReactionStrength, const FVector& InWorldLocation, const FVector& InWorldDirection, const float InWorldImpactStrength) {
}

void URagdollControlComponent::SetSkeletalMeshComponent(USkeletalMeshComponent* InSkeletalMeshComponent) {
}

void URagdollControlComponent::SetPoseDrivingMode(ERagdollPoseDrivingMode InPoseDrivingMode, float InBlendDuration) {
}

void URagdollControlComponent::SetOwnerResurrected() {
}

void URagdollControlComponent::SetOwnerIsDead() {
}

void URagdollControlComponent::SetInWater(bool bInWater) {
}

void URagdollControlComponent::SetCOMDrivingModes(ERagdollCOMLocationDrivingMode InLocationDrivingMode, ERagdollCOMRotationDrivingMode InRotationDrivingMode) {
}

void URagdollControlComponent::SetBodyConstraintContext(FName InContextName, bool bInEnable) {
}

void URagdollControlComponent::RemoveBakedRigidbody() {
}

bool URagdollControlComponent::IsFullRagdoll() const {
    return false;
}

bool URagdollControlComponent::IsBakedToRigidbody() const {
    return false;
}

bool URagdollControlComponent::HasValidSetup() const {
    return false;
}

void URagdollControlComponent::ForcePopOutOfRagdollImmediately() {
}

void URagdollControlComponent::DisallowBlendingOutOfRagdollUntilForced() {
}

void URagdollControlComponent::DisableCcd() {
}

void URagdollControlComponent::DeepFreezeWithActor(AActor* InActor, const FName InCollisionProfile) {
}

bool URagdollControlComponent::CanGetup() const {
    return false;
}

void URagdollControlComponent::BlendBack(bool bInStationaryCapsuleWhileBlending, float InBlendDurationOverride) {
}

void URagdollControlComponent::AttachBakedRigidbody() {
}

URagdollControlComponent::URagdollControlComponent() {
    this->Config = NULL;
    this->RagdollBehaviorClass = NULL;
    this->RagdollBehaviorConfig = NULL;
    this->SkeletalMeshComponent = NULL;
    this->RagdollBehaviorComponent = NULL;
}

