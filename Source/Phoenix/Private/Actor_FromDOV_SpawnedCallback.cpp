#include "Actor_FromDOV_SpawnedCallback.h"

class AActor;

void UActor_FromDOV_SpawnedCallback::ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName) {
}

UActor_FromDOV_SpawnedCallback::UActor_FromDOV_SpawnedCallback() {
    this->Caller = NULL;
    this->Provider = NULL;
}

