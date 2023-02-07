#include "CinematicBatchHUD.h"

class APlayerCameraManager;
class UAnimationComponent;
class USceneRig;
class USceneRigPlayer;

void UCinematicBatchHUD::SetFixedFrameRate() {
}

float UCinematicBatchHUD::GetCinematicBatchHUDSRLength(USceneRigPlayer* SceneRigPlayer, USceneRig* NewSceneRig, bool bInFrames) {
    return 0.0f;
}

UAnimationComponent* UCinematicBatchHUD::GetAnimationComponent(APlayerCameraManager* CameraManager) {
    return NULL;
}

float UCinematicBatchHUD::GetActiveSRCurrentFrame(USceneRigPlayer* SceneRigPlayer) {
    return 0.0f;
}

float UCinematicBatchHUD::GetActiveShotTotalFrames(UAnimationComponent* AnimationComponent) {
    return 0.0f;
}

FString UCinematicBatchHUD::GetActiveShotName(UAnimationComponent* AnimationComponent) {
    return TEXT("");
}

float UCinematicBatchHUD::GetActiveShotFrame(UAnimationComponent* AnimationComponent) {
    return 0.0f;
}

UCinematicBatchHUD::UCinematicBatchHUD() : UUserWidget(FObjectInitializer::Get()) {
    this->SceneRig = NULL;
    this->CameraAnimationComponent = NULL;
}

