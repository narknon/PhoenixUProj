#include "Enemy_ApparateActor.h"

class AActor;

bool AEnemy_ApparateActor::HasArrived() const {
    return false;
}

void AEnemy_ApparateActor::BroadcastDone(AActor* pActor) {
}

void AEnemy_ApparateActor::BroadcastArrived(AActor* pActor, FVector Loc) {
}

AEnemy_ApparateActor::AEnemy_ApparateActor() {
    this->bArrived = false;
}

