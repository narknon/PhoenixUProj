#include "EnemyGameEventData.h"

FEnemyGameEventData::FEnemyGameEventData() {
    this->TargetAbilityPtr = NULL;
    this->TargetTurnState = ENPC_TurnAssistState::None;
    this->TargetIAAssetPtr = NULL;
    this->ObserverAbilityPtr = NULL;
    this->ObserverTurnState = ENPC_TurnAssistState::None;
    this->ObserverIAAssetPtr = NULL;
}

