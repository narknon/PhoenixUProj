#include "SpringFollowSwarmActor.h"

void ASpringFollowSwarmActor::Reset() {
}

void ASpringFollowSwarmActor::Generate() {
}

ASpringFollowSwarmActor::ASpringFollowSwarmActor() {
    this->RandomizeK = 0.20f;
    this->SwarmRepulse = 1000.00f;
    this->SwarmDistancePower = 1.00f;
    this->LeaderRepulse = 0.00f;
    this->LeaderDistancePower = 1.00f;
    this->bSwarmAlignToVelocity = true;
    this->bLeaderAlignToVelocity = false;
}

