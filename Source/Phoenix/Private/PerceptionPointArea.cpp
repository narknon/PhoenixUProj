#include "PerceptionPointArea.h"

class AActor;

void APerceptionPointArea::SetActive(bool bInActive) {
}

void APerceptionPointArea::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void APerceptionPointArea::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

bool APerceptionPointArea::GetActive() {
    return false;
}

APerceptionPointArea::APerceptionPointArea(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CollisionComponent = NULL;
}

