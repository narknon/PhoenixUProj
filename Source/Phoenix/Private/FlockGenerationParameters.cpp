#include "FlockGenerationParameters.h"

FFlockGenerationParameters::FFlockGenerationParameters() {
    this->Members = 0;
    this->MemberMesh = NULL;
    this->MemberSkeletalMesh = NULL;
    this->bSkeletalMesh = false;
    this->MemberParticleSystem = NULL;
    this->PercentageWithParticleSystems = 0;
    this->bAllowSkeletalMesh = false;
}

