#include "NPC_MovementComponent.h"

UNPC_MovementComponent::UNPC_MovementComponent() {
    this->bUseConfinedRotationMode = true;
    this->bIncludeRootCapsuleInMultiCapsuleSweeps = true;
}

