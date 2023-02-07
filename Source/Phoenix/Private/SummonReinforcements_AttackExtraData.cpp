#include "SummonReinforcements_AttackExtraData.h"

USummonReinforcements_AttackExtraData::USummonReinforcements_AttackExtraData() {
    this->SpawnType = ENPC_Spawn::None;
    this->InitialWaitTime = 5.00f;
    this->ReinCooldownWaitTime = 20.00f;
    this->ReinMinTeamCount = 3;
    this->MinReinforcementCount = 1;
    this->MaxReinforcementCount = 3;
    this->GlobalMaxReinCount = 10;
    this->SpawnRadius = 2000.00f;
    this->MinDelayTime = 1.00f;
    this->MaxDelayTime = 2.00f;
    this->bStaggerAttack = false;
    this->MinStaggerTime = 0.00f;
    this->MaxStaggerTime = 1.00f;
    this->bDoDebugDraw = false;
    this->bForceThisAttack = false;
}

