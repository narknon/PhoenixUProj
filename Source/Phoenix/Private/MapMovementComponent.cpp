#include "MapMovementComponent.h"

UMapMovementComponent::UMapMovementComponent() {
    this->MaxPitchRotSpeed = 70.00f;
    this->MaxYawRotSpeed = 110.00f;
    this->MaxZoomSpeed = 50.00f;
    this->MinCameraRadius = 1000.00f;
    this->MaxCameraRadius = 18000.00f;
    this->MinCameraPitch = 0.00f;
    this->MaxCameraPitch = 89.00f;
    this->CurrentCameraParameters = NULL;
    this->CameraPitch = 0.00f;
    this->CurrentCameraYaw = 0.00f;
    this->TargetCameraYaw = 0.00f;
}

