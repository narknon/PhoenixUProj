#include "SanctuaryHousekeepingPlaceholder.h"

class AActor;
class AForagable;
class UObject;

void ASanctuaryHousekeepingPlaceholder::OnForagableCollected(AForagable* Actor) {
}

void ASanctuaryHousekeepingPlaceholder::OnChildActorEndPlay(AActor* Actor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

void ASanctuaryHousekeepingPlaceholder::HandleBreakableDestroyed(const UObject* i_caller) {
}

ASanctuaryHousekeepingPlaceholder::ASanctuaryHousekeepingPlaceholder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UID = 0;
    this->StaticMeshOverride = NULL;
    this->bIsAliveOnFirstLoad = false;
    this->bIsSpawnedInAsOwnActor = false;
}

