#include "DynamicObjectGroupInfo.h"

FDynamicObjectGroupInfo::FDynamicObjectGroupInfo() {
    this->bIsPersistent = false;
    this->bSpawnRagdollIfDead = false;
    this->bSpawnAllDead = false;
    this->bSpawnBlind = false;
    this->bSpawnInjured = false;
    this->MinActorCount = 0;
    this->MaxActorCount = 0;
    this->MinDelayBetweenSpawns = 0.00f;
    this->MaxDelayBetweenSpawns = 0.00f;
    this->SpawnProbability = 0.00f;
    this->bApplyDelayOnFirstSpawn = false;
    this->bApplyDelayWhenCulling = false;
    this->SpawnOnlyOneOfTheGroup = false;
    this->bForceSpawnOnFloor = false;
    this->bSpawnOnNavMesh = false;
    this->CollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::Undefined;
    this->bUseScatterSpawn = false;
    this->FloorSweepDistanceZ = 0.00f;
    this->RadiusForNavCheck = 0.00f;
    this->SpawnTimeout = 0.00f;
    this->GatherDataRetryMax = 0;
    this->GatherDataTimout = 0.00f;
    this->bAllowSyncGatherOnTimout = false;
    this->SpawnTypeOverride = ENPC_Spawn::None;
    this->SpawnStateOverride = EEnemy_CharacterState::Wander;
    this->bAllowLookOverride = false;
    this->bAllowVoiceOverride = false;
    this->HealthBarType = EUIHealthBarType::HBT_Normal;
    this->PerformTaskTrigger = NULL;
    this->StartPerformTaskWhenSpawned = false;
    this->StartPerformTaskWhenResurrected = false;
    this->LoopPerformTask = false;
    this->ForceSEMode = false;
    this->SpawnedActorCount = 0;
}

