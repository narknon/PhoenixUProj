#include "SubsonicSpellMovementComponent.h"

USubsonicSpellMovementComponent::USubsonicSpellMovementComponent() {
    this->MinHomingDistance = 0.00f;
    this->MaxHomingDistance = 1000.00f;
    this->MinHomingRotationSpeed = 45.00f;
    this->MaxHomingRotationSpeed = 720.00f;
}

