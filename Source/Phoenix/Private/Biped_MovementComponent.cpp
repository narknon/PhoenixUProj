#include "Biped_MovementComponent.h"

UBiped_MovementComponent::UBiped_MovementComponent() {
    this->ClothCollisionPhysicsAsset = NULL;
    this->bEnableStickyLedges = true;
    this->MaxSpeedForStickyLedges = 100.00f;
    this->bAllowLanding = true;
    this->DefaultWalkableFloorAngle = 60.00f;
    this->FallingWalkableFloorAngle = 45.00f;
    this->MaxFloorAngleForMovement = 45.00f;
}

