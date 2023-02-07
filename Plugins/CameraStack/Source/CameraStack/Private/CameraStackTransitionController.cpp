#include "CameraStackTransitionController.h"

class AActor;
class APlayerController;

void ACameraStackTransitionController::TransitionToCameraAndTargetLocation(AActor* InCameraActor, FVector InTargetLocation, float InTransitionDuration, float InDelay) {
}

void ACameraStackTransitionController::TransitionToCameraAndTargetActor(AActor* InCameraActor, AActor* InTargetLocationActor, float InTransitionDuration, float InDelay) {
}

void ACameraStackTransitionController::TransitionToCamera(AActor* InCameraActor, float InTransitionDuration, float InDelay) {
}

APlayerController* ACameraStackTransitionController::GetPlayerController_Implementation() const {
    return NULL;
}

ACameraStackTransitionController::ACameraStackTransitionController() {
    this->StackSettings = NULL;
    this->CameraActorClass = NULL;
    this->bConstrainAspectRatio = false;
    this->bRelativeToArmRotation = false;
    this->CameraStackActor = NULL;
}

