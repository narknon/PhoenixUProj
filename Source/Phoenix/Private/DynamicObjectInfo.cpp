#include "DynamicObjectInfo.h"

UDynamicObjectInfo::UDynamicObjectInfo() {
    this->ClassToSpawn = NULL;
    this->MaxInstances = 10;
    this->ActiveInstanceCount = 0;
    this->MaxGeneratedSpawners = 5;
    this->bCreateDefaultSpawner = true;
    this->ObjectSpawnChance = 1.00f;
    this->MinPerSpawn = 1;
    this->MaxPerSpawn = 16;
    this->SpawnVariance = 0;
    this->InstanceSpawnChance = 1.00f;
    this->SpawnRadius = 1000.00f;
    this->bUseRandomYawRotation = true;
    this->bSpawnOnGround = true;
    this->bSharedActorCount = true;
    this->MinDelayBetweenSpawns = 0.10f;
    this->MaxDelayBetweenSpawns = 0.10f;
    this->bUseSpawningLimits = false;
    this->bReverseTimeCheck = false;
    this->SpawnStartDayOfYear = 1;
    this->SpawnStopDayOfYear = 365;
    this->SpawnDaysAllowed = 127;
    this->SpawnMonthsAllowed = 4095;
    this->SpawnSeasonsAllowed = 65535;
    this->SpawnSpecialEventEnum = 0;
    this->SpawnOffset = 0.00f;
    this->MinAltitude = -300000.00f;
    this->MaxAltitude = 300000.00f;
    this->MinFoliageDensity = 1.00f;
    this->bFoliageRequired = false;
    this->bAllowNoFoliage = true;
    this->MaxGroundAngle = 90.00f;
    this->MaxAngleIterations = 10;
    this->MaxRuntimeSlopeRetries = 5;
    this->bVisualiseSpawners = true;
    this->bVisualiseSlopeRejects = false;
}

