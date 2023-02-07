#include "FlyingBroomMovementComponent.h"

UFlyingBroomMovementComponent::UFlyingBroomMovementComponent() {
    this->MaxSimulationIterations = 8;
    this->MaxSimulationTimeStep = 0.05f;
    this->FlyingBroomPhysics = NULL;
    this->FlyingBroomStats = NULL;
    this->bClearAccumulatedForces = true;
    this->FlyingBroomPhysicsScratch = NULL;
}

