#include "RaiseDead_AttackExtraData.h"

void URaiseDead_AttackExtraData::SetSpawnEligible(bool bspawnEligible) {
}

URaiseDead_AttackExtraData::URaiseDead_AttackExtraData() {
    this->MinSpawn = 1;
    this->MaxSpawn = 3;
    this->MyMaxSpawn = 3;
    this->GlobalMaxSpawn = 10;
    this->MyLiftimeMaxSpawn = 6;
    this->bUseMyTeamName = false;
    this->SpawnRadius = 500.00f;
    this->halfAngle = 30.00f;
    this->SpawnType = ENPC_Spawn::None;
    this->SpawnEligibleWaitTime = 10.00f;
    this->bForceThisAttack = false;
    this->bStaggerAttack = false;
    this->MinStaggerTime = 0.00f;
    this->MaxStaggerTime = 1.00f;
    this->bLimitSpawns = false;
    this->bKillChildrenOnDeath = true;
}

