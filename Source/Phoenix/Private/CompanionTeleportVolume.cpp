#include "CompanionTeleportVolume.h"
#include "Components/BoxComponent.h"

class AActor;

void ACompanionTeleportVolume::SetTemporarilyActive(bool bActive, float Timeout) {
}

void ACompanionTeleportVolume::SetActive(bool bActive) {
}

void ACompanionTeleportVolume::OnEndOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void ACompanionTeleportVolume::OnBeginOverlap(AActor* SelfActor, AActor* OtherActor) {
}

ACompanionTeleportVolume::ACompanionTeleportVolume() {
    this->CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
    this->bIsAlwaysActive = false;
    this->bTriggerOnEnter = true;
}

