#include "ActorSpawnFromDOVCallback.h"

class AActor;

void UActorSpawnFromDOVCallback::ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName) {
}

UActorSpawnFromDOVCallback::UActorSpawnFromDOVCallback() {
    this->Caller = NULL;
    this->Provider = NULL;
}

