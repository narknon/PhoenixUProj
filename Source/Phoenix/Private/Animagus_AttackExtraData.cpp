#include "Animagus_AttackExtraData.h"

UAnimagus_AttackExtraData::UAnimagus_AttackExtraData() {
    this->SpawnType = ENPC_Spawn::None;
    this->AnimagusMorphTime = 0.00f;
    this->AnimagusMorphTimeLevelMultiplier = 0.00f;
    this->AnimagusWaitTime = 300.00f;
    this->AnimalHealthOverride = -1.00f;
    this->bForceThisAttack = false;
    this->bAllowSingleAttack = false;
    this->bKillChildrenOnDeath = true;
}

