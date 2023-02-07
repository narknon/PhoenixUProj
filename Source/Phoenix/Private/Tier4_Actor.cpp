#include "Tier4_Actor.h"
#include "Components/CapsuleComponent.h"

class AActor;
class AStation;
class UStaticMeshComponent;

bool ATier4_Actor::TeleportToStation(const AStation* InStation, const int32 InConnectionIndex) {
    return false;
}

void ATier4_Actor::SetManagedStackVisibilityMesh(UStaticMeshComponent* InVisibilityMesh) {
}

void ATier4_Actor::OnCharacterLoadComplete(AActor* inTheActor) {
}

void ATier4_Actor::OnBeginActorOverlap(AActor* SelfActor, AActor* OtherActor) {
}

ATier4_Actor::ATier4_Actor() {
    this->AnimSharingSetup = NULL;
    this->Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("T4Collision"));
    this->VisibilityMesh = NULL;
}

