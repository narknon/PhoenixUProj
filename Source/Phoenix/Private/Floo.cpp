#include "Floo.h"

class AActor;
class UBTService_AvaAITree;

void AFloo::ShowAvatar(bool bTF) {
}

void AFloo::SetFlooSourceAnim() {
}

void AFloo::SetAvailable(bool availableIn) {
}

void AFloo::ReturnToGameCamera() {
}

void AFloo::PlayerSelectedFloo(AActor* ActorUsingFloo) {
}

void AFloo::PlayerExitingFloo(AActor* ActorUsingFloo) {
}

void AFloo::PlayerExitedFloo(AActor* ActorUsingFloo) {
}

void AFloo::PlayerEnteringFloo(AActor* ActorUsingFloo) {
}

void AFloo::PlayerEnteredFloo(AActor* ActorUsingFloo) {
}

void AFloo::PlayerDroppedFlooPowder(AActor* ActorUsingFloo) {
}

void AFloo::PlayerCanceledFloo(AActor* ActorUsingFloo) {
}

void AFloo::OnSaveGameLoad() {
}

bool AFloo::IsForcedDestination() {
    return false;
}

void AFloo::Interact_Implementation(UBTService_AvaAITree* AvaService) {
}











FString AFloo::GetFlooName() {
    return TEXT("");
}

bool AFloo::GetAvailable() {
    return false;
}

void AFloo::ActivateExitCamera() {
}

void AFloo::ActivateEnterCamera() {
}

AFloo::AFloo() {
    this->EnterCrouched = false;
    this->EnterDistance = 100.00f;
}

