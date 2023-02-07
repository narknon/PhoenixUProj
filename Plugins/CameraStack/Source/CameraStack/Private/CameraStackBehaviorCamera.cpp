#include "CameraStackBehaviorCamera.h"

class AActor;
class USceneComponent;

void UCameraStackBehaviorCamera::SetSourceCameraComponent(USceneComponent* InSourceCamera, const bool bInIsValidOverDuration) {
}

void UCameraStackBehaviorCamera::SetSourceCamera(AActor* InSourceCamera, const bool bInIsValidOverDuration) {
}

UCameraStackBehaviorCamera::UCameraStackBehaviorCamera() {
    this->bMaintainArmRotation = false;
    this->bMaintainArmOrigin = false;
}

