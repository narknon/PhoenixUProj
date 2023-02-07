#include "PortraitPaintingEntityComponent.h"

class AActor;
class UScheduledEntity;

void UPortraitPaintingEntityComponent::OnFleshDestroyed(AActor* Actor, UScheduledEntity* entity) {
}

void UPortraitPaintingEntityComponent::OnCharacterAddOnMeshesChanged(AActor* Actor) {
}

UPortraitPaintingEntityComponent::UPortraitPaintingEntityComponent() {
    this->MaterialBundle = NULL;
    this->MaterialSwap = NULL;
    this->bOverrodeMeshStates = false;
    this->bOverrodeMovementMode = false;
    this->bNudgedAudio = false;
    this->bNudgedCognitionStimuliSourceComponent = false;
    this->bAddedDoNotInvestigate = false;
    this->bAddedNoWeatherSwap = false;
}

