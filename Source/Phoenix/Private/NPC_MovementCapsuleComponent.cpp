#include "NPC_MovementCapsuleComponent.h"

UNPC_MovementCapsuleComponent::UNPC_MovementCapsuleComponent() {
    this->bUseBoneLocationTracking = false;
    this->CapsuleLocationInterpToSpeed = 6.00f;
    this->StartTrackingLocationTolerance = 30.00f;
    this->EndTrackingLocationTolerance = 10.00f;
    this->bTrackBoneZ = false;
    this->bUseInFloorSweep = false;
    this->bDisabledAtSpawn = false;
    this->bDisabledAlways = false;
    this->ActivateCollisionEnabledType = ECollisionEnabled::QueryAndPhysics;
}

