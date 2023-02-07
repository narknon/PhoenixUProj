#include "MultiFX2_SpawnActor.h"

UMultiFX2_SpawnActor::UMultiFX2_SpawnActor() {
    this->SpawnActorClass = NULL;
    this->bAttached = false;
    this->LifeSpan = -1.00f;
    this->bDestroyActorOnDeactivate = true;
}

