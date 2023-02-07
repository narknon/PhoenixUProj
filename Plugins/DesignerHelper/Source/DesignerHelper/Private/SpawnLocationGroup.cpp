#include "SpawnLocationGroup.h"

FSpawnLocationGroup::FSpawnLocationGroup() {
    this->ActorSelectionMode = ESpawnerActorSelectionMode::Undefined;
    this->MinActorCount = 0;
    this->MaxActorCount = 0;
    this->MinDelayBetweenSpawns = 0.00f;
    this->MaxDelayBetweenSpawns = 0.00f;
    this->bForceSpawnOnFloor = false;
    this->SpawnOnFloorTest = ESpawnOnFloorTestType::ShapeSweep;
    this->FloorSweepDistanceZ = 0.00f;
    this->bIsValid = false;
    this->bUsesDeterministicSpawning = false;
    this->RandomizerSeed = 0;
}

