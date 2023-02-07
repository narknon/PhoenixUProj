#include "NPC_SpawnData.h"

FNPC_SpawnData::FNPC_SpawnData() {
    this->Type = ENPC_Spawn::None;
    this->bHideOnSpawnStart = false;
    this->bUnhideOnSpawnStartDelay = 0.00f;
    this->bApplyForceOnSpawn = false;
    this->bTurnToTargetOnSpawn = false;
    this->SpawnBehaviorTree = NULL;
}

