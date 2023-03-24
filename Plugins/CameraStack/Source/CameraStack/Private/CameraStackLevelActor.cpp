#include "CameraStackLevelActor.h"

class AActor;

void ACameraStackLevelActor::SetRuntimeTarget(AActor* InActor) {
}

AActor* ACameraStackLevelActor::GetRuntimeTarget() const {
    return NULL;
}

ACameraStackLevelActor::ACameraStackLevelActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsInWorldSpace = false;
}

