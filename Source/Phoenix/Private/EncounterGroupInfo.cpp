#include "EncounterGroupInfo.h"

FEncounterGroupInfo::FEncounterGroupInfo() {
    this->bIsPersistent = false;
    this->SpawnProbability = 0.00f;
    this->bForceSpawnOnFloor = false;
    this->bUseScatterSpawn = false;
    this->bSpawnOnNavMesh = false;
    this->RadiusForNavCheck = 0.00f;
}

