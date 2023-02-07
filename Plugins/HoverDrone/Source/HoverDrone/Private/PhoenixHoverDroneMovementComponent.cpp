#include "PhoenixHoverDroneMovementComponent.h"

UPhoenixHoverDroneMovementComponent::UPhoenixHoverDroneMovementComponent() {
    this->RotAcceleration = 150.00f;
    this->RotDeceleration = 150.00f;
    this->MaxPitchRotSpeed = 70.00f;
    this->MaxYawRotSpeed = 110.00f;
    this->TurboRotAcceleration = 30.00f;
    this->TurboRotDeceleration = 75.00f;
    this->TurboMaxPitchRotSpeed = 35.00f;
    this->TurboMaxYawRotSpeed = 30.00f;
    this->TurboDeceleration = 3000.00f;
}

