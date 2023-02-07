#include "CombativePlantComponent.h"

class AActor;
class AInventoryObject;

void UCombativePlantComponent::PickedUp(AInventoryObject* InInventoryObject, int32 InCount) {
}

void UCombativePlantComponent::OnRecall() {
}

void UCombativePlantComponent::GenerateFocus(AActor* InActor, float InDamage, const FHitResult& InHit) {
}

void UCombativePlantComponent::EmitPerceptionEvent() {
}

void UCombativePlantComponent::DisablePickup() {
}

bool UCombativePlantComponent::AddObjectToInventory(const AActor* InInventoryHolder) {
    return false;
}

UCombativePlantComponent::UCombativePlantComponent() {
    this->bCanBePickedUp = true;
    this->RecallAudioEffect = NULL;
    this->RecallVisualEffect = NULL;
    this->RespondToPlayerAbility = NULL;
    this->SwitchTime = 5.00f;
    this->bPlayerIsInstigator = true;
    this->bShouldEmitPerceptionEvents = true;
    this->PerceptionEventTimePeriod = 2.00f;
    this->CognitionStimuliSource = NULL;
}

