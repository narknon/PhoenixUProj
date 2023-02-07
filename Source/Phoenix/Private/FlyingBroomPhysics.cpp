#include "FlyingBroomPhysics.h"

class UFlyingBroomMovementComponent;
class UFlyingBroomPhysicsScratch;

void UFlyingBroomPhysics::PhysicsUpdate(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, float DeltaTime) {
}

void UFlyingBroomPhysics::PhysicsRemoved(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch) {
}

void UFlyingBroomPhysics::PhysicsPostIteration(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, const FVector& Adjusted, float timeTick) {
}

FVector UFlyingBroomPhysics::PhysicsIteration(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, float timeTick) {
    return FVector{};
}

void UFlyingBroomPhysics::PhysicsAdded(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch) {
}

UFlyingBroomPhysicsScratch* UFlyingBroomPhysics::CreateScratch(UFlyingBroomMovementComponent* InOwner) {
    return NULL;
}

void UFlyingBroomPhysics::AnimationUpdate(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch) {
}

UFlyingBroomPhysics::UFlyingBroomPhysics() {
    this->bDebugDraw = false;
    this->bDisablePhysics = false;
}

