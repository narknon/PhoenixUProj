#include "ActorMeshSetupProcessCapsuleShadows.h"

UActorMeshSetupProcessCapsuleShadows::UActorMeshSetupProcessCapsuleShadows() {
    this->bCastCapsuleDirectShadow = false;
    this->bCastCapsuleIndirectShadow = false;
    this->CapsuleIndirectShadowMinVisibility = 0.10f;
    this->bCanUsePhysicsCapsulesToShadow = false;
    this->bForcePhysicsCapsulesToShadow = false;
    this->bOverride_bCastCapsuleDirectShadow = false;
    this->bOverride_bCastCapsuleIndirectShadow = false;
    this->bOverride_CapsuleIndirectShadowMinVisibility = false;
}

