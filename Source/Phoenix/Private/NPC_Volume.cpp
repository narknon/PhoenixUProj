#include "NPC_Volume.h"

class AActor;

void ANPC_Volume::SetActive(bool bInActive) {
}

void ANPC_Volume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void ANPC_Volume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

bool ANPC_Volume::GetActive() {
    return false;
}

ANPC_Volume::ANPC_Volume() {
    this->CollisionComponent = NULL;
}

