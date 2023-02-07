#include "Enemy_SplineSpawnActor.h"

class AActor;

void AEnemy_SplineSpawnActor::StartLandingVFX(FVector StartLocation) {
}

void AEnemy_SplineSpawnActor::StartArrivedVFX() {
}

void AEnemy_SplineSpawnActor::Start() {
}

bool AEnemy_SplineSpawnActor::HasArrived() const {
    return false;
}

void AEnemy_SplineSpawnActor::BroadcastDone(AActor* pActor) {
}

void AEnemy_SplineSpawnActor::BroadcastArrived(AActor* pActor, FVector Loc) {
}

void AEnemy_SplineSpawnActor::ApplyStopFX_Implementation() {
}

void AEnemy_SplineSpawnActor::ApplyStartFX_Implementation() {
}

AEnemy_SplineSpawnActor::AEnemy_SplineSpawnActor() {
    this->bAutoStart = false;
    this->DestroyDelayTime = 3.00f;
}

