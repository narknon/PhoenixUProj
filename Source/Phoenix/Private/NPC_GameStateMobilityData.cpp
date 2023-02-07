#include "NPC_GameStateMobilityData.h"

FNPC_GameStateMobilityData::FNPC_GameStateMobilityData() {
    this->State = ENPC_GameState::None;
    this->Mobility = ENPC_Mobility::None;
    this->bOverrideSpeed = false;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
}

