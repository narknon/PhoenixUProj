#include "StreamingPlaceholderFixedUID.h"

class AActor;

AActor* AStreamingPlaceholderFixedUID::GetSpawnedActor() {
    return NULL;
}

AStreamingPlaceholderFixedUID::AStreamingPlaceholderFixedUID(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UID = 0;
    this->SpawnedActor = NULL;
}

