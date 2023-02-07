#include "GroundSwarmVoxelCollisionDebugParameters.h"

FGroundSwarmVoxelCollisionDebugParameters::FGroundSwarmVoxelCollisionDebugParameters() {
    this->bShowVoxels = false;
    this->bShowCollisions = false;
    this->TimeFactor = 0.00f;
    this->ShowPreCacheLandingsTime = 0.00f;
    this->StartCollisionInstance = 0;
    this->bLockCollisionInstance = false;
    this->StopTimeCollisionCount = 0;
    this->CollisionTimeFilter = 0.00f;
    this->bSlowTimeOnCollisions = false;
    this->ForceLinesReset = 0.00f;
}

