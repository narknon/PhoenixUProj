#include "EnemyEvadeData.h"

FEnemyEvadeData::FEnemyEvadeData() {
    this->EvadeType = EEnemyAIDodgeState::None;
    this->EvadeAbilityPtr = NULL;
    this->InteractionArchitectAssetPtr = NULL;
    this->EvadeChance = 0.00f;
    this->EvadeSuccessCooldown = 0.00f;
    this->EvadeFailedCooldown = 0.00f;
}

