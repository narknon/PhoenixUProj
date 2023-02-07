#include "StreamingPlaceholderFixedUID.h"

class AActor;

AActor* AStreamingPlaceholderFixedUID::GetSpawnedActor() {
    return NULL;
}

AStreamingPlaceholderFixedUID::AStreamingPlaceholderFixedUID() {
    this->UID = 0;
    this->SpawnedActor = NULL;
}

