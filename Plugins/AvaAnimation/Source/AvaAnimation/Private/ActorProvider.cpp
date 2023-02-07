#include "ActorProvider.h"

class AActor;
class UObject;

AActor* UActorProvider::GetActor(const UObject* Caller) const {
    return NULL;
}

UActorProvider::UActorProvider() {
    this->PreviewSpawner = NULL;
}

