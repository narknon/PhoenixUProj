#include "NPC_MobilityTurnAssistStateData.h"

FNPC_MobilityTurnAssistStateData::FNPC_MobilityTurnAssistStateData() {
    this->MoveTurnTo = ENPC_TurnAssistState::None;
    this->MoveStartTurnTo = ENPC_TurnAssistState::None;
    this->MoveStopTurnTo = ENPC_TurnAssistState::None;
    this->MoveStartMode = ENPC_MobilityTurnAssistStartMode::None;
    this->MoveStartDelayedStartTime = 0.00f;
}

