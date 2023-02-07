#include "ShadowSprintMovementComponent.h"

void UShadowSprintMovementComponent::SetVerticalImpulse(const float Val) {
}

UShadowSprintMovementComponent::UShadowSprintMovementComponent() {
    this->MaxSimulationIterations = 8;
    this->MaxSimulationTimeStep = 0.05f;
    this->ShadowSprintData = NULL;
    this->BroomTrailEmitter = NULL;
    this->BroomTrailEmitterSystemComponent = NULL;
    this->bClearAccumulatedForces = true;
    this->bOnGround = false;
    this->CurrentPitch = 0.00f;
}

