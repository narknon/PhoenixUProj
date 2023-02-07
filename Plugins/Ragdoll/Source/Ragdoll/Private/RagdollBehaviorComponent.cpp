#include "RagdollBehaviorComponent.h"

class AActor;
class USkeletalMeshComponent;

void URagdollBehaviorComponent::SetSkeletalMeshComponent(USkeletalMeshComponent* InSkeletalMeshComponent) {
}

void URagdollBehaviorComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

bool URagdollBehaviorComponent::IsSensoryStateStatisfied(FName targetSensoryState) {
    return false;
}

bool URagdollBehaviorComponent::IsPoseStateStatisfied(FName targetPose) {
    return false;
}

bool URagdollBehaviorComponent::IsGetupAllowed() {
    return false;
}

bool URagdollBehaviorComponent::HasValidSetup() const {
    return false;
}

void URagdollBehaviorComponent::DoAudioBehaviorChangeEvent(FAudioLayerBehaviorState& rLayerState) {
}

URagdollBehaviorComponent::URagdollBehaviorComponent() {
    this->Config = NULL;
    this->SkeletalMeshComponent = NULL;
    this->RagdollControlComponent = NULL;
    this->CurBehavior = NULL;
    this->PriorBehavior = NULL;
    this->CurRecoveryAssistBehavior = NULL;
    this->PriorRecoveryAssistBehavior = NULL;
}

