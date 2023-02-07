#include "Spider_SpawnAttack_ExecuteTask.h"

USpider_SpawnAttack_ExecuteTask::USpider_SpawnAttack_ExecuteTask() {
    this->bDeathSpawn = false;
    this->bDeathSpawnCount = 10;
    this->bDeathSpawnDeviation = 3;
    this->SpawnInterval = 0.25f;
    this->SpawnAngleFromRange = 90.00f;
    this->SpawnAngleDeviation = 10.00f;
    this->SpawnDist = 50.00f;
    this->SpawnLandDist = 100.00f;
    this->SpawnLandDistVariance = 20.00f;
    this->SpawnSpidersPtr = NULL;
}

