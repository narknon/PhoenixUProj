#include "GroundSwarmBurrowingParameters.h"

FGroundSwarmBurrowingParameters::FGroundSwarmBurrowingParameters() {
    this->BurrowingMinDelay = 0.00f;
    this->BurrowingMaxDelay = 0.00f;
    this->BurrowingForce = 0.00f;
    this->BurrowingMaxSpeed = 0.00f;
    this->SwarmForceFactor = 0.00f;
    this->SurfaceVelocityDampening = 0.00f;
    this->BurrowingDeathTimeout = 0.00f;
    this->DeathLeapTimeout = 0.00f;
    this->DeathLeapImpulse = 0.00f;
    this->DeathLeapThresholdAngleDegrees = 0.00f;
    this->FreefallingDeathDuration = 0.00f;
    this->bAlignToVelocity = false;
}

