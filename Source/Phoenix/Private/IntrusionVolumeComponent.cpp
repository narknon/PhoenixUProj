#include "IntrusionVolumeComponent.h"

class AActor;
class ANPC_Character;

FEventDateTime UIntrusionVolumeComponent::WhenWillPlayerBeDisallowed() {
    return FEventDateTime{};
}

FEventDateTime UIntrusionVolumeComponent::WhenWillPlayerBeAllowed() {
    return FEventDateTime{};
}

void UIntrusionVolumeComponent::PlayIntrusionSceneRig(ANPC_Character* InNPC) {
}

void UIntrusionVolumeComponent::OnIntrusionPerceptionDone(ANPC_Character* InNPC) {
}

void UIntrusionVolumeComponent::OnCaught() {
}

void UIntrusionVolumeComponent::OnActorEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void UIntrusionVolumeComponent::OnActorBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

bool UIntrusionVolumeComponent::IsPlayerInIntrusionArea() {
    return false;
}

bool UIntrusionVolumeComponent::IsPlayerAllowed() {
    return false;
}

void UIntrusionVolumeComponent::EnableIntrusion(bool Enable) {
}

UIntrusionVolumeComponent::UIntrusionVolumeComponent() {
    this->IntrusionSceneRig = NULL;
}

