#include "BTService_Creature_AwareState.h"

UBTService_Creature_AwareState::UBTService_Creature_AwareState() {
    this->SelectedAwareState = ENPC_TargetAwareState::Attack;
    this->bObserveBlackboardValue = true;
}

