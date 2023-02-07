#include "CameraFixupComponent.h"

class AActor;

void UCameraFixupComponent::LightRigBlueprintShowDebug(AActor* LightRigActor) {
}

FVector UCameraFixupComponent::GetTarget(bool& bOutHasValidTarget) {
    return FVector{};
}

UCameraFixupComponent::UCameraFixupComponent() {
    this->LastCameraFixupOperations = NULL;
}

