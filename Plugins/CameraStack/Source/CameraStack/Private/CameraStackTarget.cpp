#include "CameraStackTarget.h"

class AActor;

bool UCameraStackTarget::IsWorldCamera() const {
    return false;
}

FVector UCameraStackTarget::GetTargetVelocity() const {
    return FVector{};
}

AActor* UCameraStackTarget::GetTargetActor() const {
    return NULL;
}

UCameraStackTarget::UCameraStackTarget() {
}

