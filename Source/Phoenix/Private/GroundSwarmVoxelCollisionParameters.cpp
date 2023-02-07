#include "GroundSwarmVoxelCollisionParameters.h"

FGroundSwarmVoxelCollisionParameters::FGroundSwarmVoxelCollisionParameters() {
    this->InitialGroundScanHeight = 0.00f;
    this->PreCacheMaxCollisionsFrame = 0;
    this->Radius = 0.00f;
    this->SurfaceOffset = 0.00f;
    this->MaxTimeStep = 0.00f;
    this->Elasticity = 0.00f;
    this->ElasticityVariancePercent = 0.00f;
    this->StickyThreshold = 0.00f;
    this->BounceNoiseAmountDegrees = 0.00f;
    this->FreefallTimeout = 0.00f;
    this->DeadRecycleDelayMin = 0.00f;
    this->DeadRecycleDelayMax = 0.00f;
    this->RespawnVelocityVariance = 0.00f;
}

