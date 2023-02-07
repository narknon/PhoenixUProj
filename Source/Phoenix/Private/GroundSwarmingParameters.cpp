#include "GroundSwarmingParameters.h"

FGroundSwarmingParameters::FGroundSwarmingParameters() {
    this->GravityFactor = 0.00f;
    this->Follow = 0.00f;
    this->Separation = 0.00f;
    this->SeparationDistance = 0.00f;
    this->Alignment = 0.00f;
    this->Cohesion = 0.00f;
    this->FollowLag = 0.00f;
    this->MaxSpeed = 0.00f;
    this->CurlNoiseScale = 0.00f;
    this->MemberSfxLoop = NULL;
    this->MaxMembersWithSFXLoop = 0;
    this->bAlignToVelocity = false;
}

