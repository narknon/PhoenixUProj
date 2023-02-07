#include "ReplicateSelf_AttackExtraData.h"

UReplicateSelf_AttackExtraData::UReplicateSelf_AttackExtraData() {
    this->SpawnType = ENPC_Spawn::None;
    this->MinSpawn = 5;
    this->MaxSpawn = 5;
    this->GlobalMaxSpawn = 10;
    this->SpawnRadius = 100.00f;
    this->halfAngle = 30.00f;
    this->SpawnSpeedMultiplier = 1.00f;
    this->BuffTeamWaitTime = 5.00f;
    this->bForceThisAttack = false;
    this->bFadeReplicaOnDeath = true;
    this->FadeDelay = 0.00f;
    this->FadeDuration = 1.00f;
    this->ReplicaHealthOverride = -1.00f;
    this->bStaggerAttack = false;
    this->MinStaggerTime = 0.00f;
    this->MaxStaggerTime = 1.00f;
    this->bKillChildrenOnDeath = true;
}

