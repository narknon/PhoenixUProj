#include "AttachCameraComponent.h"

void UAttachCameraComponent::SetupCopyToRootComponent(bool copyToRootComponent) {
}

void UAttachCameraComponent::ResetChildRotations() {
}

void UAttachCameraComponent::ResetChildLocations() {
}

void UAttachCameraComponent::ResetAllChildren() {
}

bool UAttachCameraComponent::GetCameraRotation(FRotator& Rotation) const {
    return false;
}

bool UAttachCameraComponent::GetCameraLocation(FVector& Eye) const {
    return false;
}

bool UAttachCameraComponent::GetCamera(FVector& Eye, FRotator& Orientation) const {
    return false;
}

UAttachCameraComponent::UAttachCameraComponent() {
    this->AttachType = EAttachCameraType::ACT_FULL;
    this->BillBoardType = EAttachCameraBillBoardType::ACBBT_ZX;
    this->bCopyToRootComponent = false;
    this->bEnable = true;
    this->bEnableInEditor = true;
}

