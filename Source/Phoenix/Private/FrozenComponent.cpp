#include "FrozenComponent.h"

class AActor;

void UFrozenComponent::SetupDelegate() {
}

bool UFrozenComponent::RemoveFrozenActor(AActor* OutFrozenActor) {
    return false;
}

void UFrozenComponent::OnBroken(AActor* Actor) {
}

void UFrozenComponent::ClearFrozenActors() {
}

void UFrozenComponent::AddToInstanceList(AActor* InInstigator, int32 InMaxObjectInstancesPerInstigator, int32 InMaxCharacterInstancesPerInstigator) {
}

void UFrozenComponent::AddFrozenActor(AActor* InFrozenActor) {
}

UFrozenComponent::UFrozenComponent() {
    this->bStartFrozen = false;
    this->InitialDuration = -1.00f;
}

