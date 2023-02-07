#include "CameraStackLevelActor.h"

class AActor;

void ACameraStackLevelActor::SetRuntimeTarget(AActor* InActor) {
}

AActor* ACameraStackLevelActor::GetRuntimeTarget() const {
    return NULL;
}

ACameraStackLevelActor::ACameraStackLevelActor() {
    this->bIsInWorldSpace = false;
}

