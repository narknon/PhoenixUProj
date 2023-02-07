#include "DisillusionmentComponent.h"

class AActor;
class ACharacter;

void UDisillusionmentComponent::RemoveDisillusionmentFromActor(const AActor* Actor, bool bEvenIfCloak) {
}

void UDisillusionmentComponent::PerceptionDoneHandler(AActor* Actor, bool bSuccess, bool bReturnControl) {
}

void UDisillusionmentComponent::OwnerMovementModeChanged(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode) {
}

void UDisillusionmentComponent::OnActorEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void UDisillusionmentComponent::OnActorBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

bool UDisillusionmentComponent::IsActorDisillusionedByCloak(const AActor* Actor) {
    return false;
}

bool UDisillusionmentComponent::IsActorDisillusioned(const AActor* Actor) {
    return false;
}

float UDisillusionmentComponent::GetVisibilityPercentage() {
    return 0.0f;
}

UDisillusionmentComponent::UDisillusionmentComponent() {
    this->SightDetectionSphereActor = NULL;
    this->MinSightAngleDegrees = 0.00f;
    this->MaterialSwap = NULL;
}

