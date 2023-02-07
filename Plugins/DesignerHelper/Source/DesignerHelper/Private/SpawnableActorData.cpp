#include "SpawnableActorData.h"

FSpawnableActorData::FSpawnableActorData() {
    this->ActorClass = NULL;
    this->bSpawnOnNavMesh = false;
    this->bForceSpawnOnFloor = false;
    this->SpawnOnFloorTest = ESpawnOnFloorTestType::ShapeSweep;
    this->FloorSweepDistanceZ = 0.00f;
    this->NavSearchRadius = 0.00f;
}

