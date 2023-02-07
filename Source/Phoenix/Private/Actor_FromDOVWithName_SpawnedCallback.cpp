#include "Actor_FromDOVWithName_SpawnedCallback.h"

class AActor;

void UActor_FromDOVWithName_SpawnedCallback::ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName) {
}

UActor_FromDOVWithName_SpawnedCallback::UActor_FromDOVWithName_SpawnedCallback() {
    this->Caller = NULL;
    this->Provider = NULL;
}

