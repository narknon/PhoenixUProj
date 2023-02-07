#include "PhysicsVirtualForcePD.h"

FPhysicsVirtualForcePD::FPhysicsVirtualForcePD() {
    this->GravityCompensation = 0.00f;
    this->Depth = 0;
    this->Application = EPhysicsVirtualForceApplication::PartialBodyOnly;
}

