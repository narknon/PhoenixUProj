#include "PhoenixCameraStackManager.h"

void APhoenixCameraStackManager::StartFadeToZeroOpacity() {
}

void APhoenixCameraStackManager::OnCurtainRaised() {
}

void APhoenixCameraStackManager::FinishFadeToZeroOpacity() {
}

void APhoenixCameraStackManager::EnableForceFadeAll() {
}

void APhoenixCameraStackManager::DisableForceFadeAll() {
}

APhoenixCameraStackManager::APhoenixCameraStackManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableObjectFading = true;
    this->ObjectFadeDuration = 0.40f;
    this->MinObjectFadeOpacity = 0.17f;
    this->ObjectFadingProbeSize = 12.00f;
    this->MinFadeCameraDistanceToAvatar = 50.00f;
    this->AvatarCapsuleRefRadius = 42.00f;
}

