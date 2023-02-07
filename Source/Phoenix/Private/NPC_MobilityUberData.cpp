#include "NPC_MobilityUberData.h"

FNPC_MobilityUberData::FNPC_MobilityUberData() {
    this->Mode = ENPC_Mobility::None;
    this->MobilityChoice = NULL;
    this->GameContext = ENPC_GameContext::None;
    this->StairsSlopeState = ENPC_StairsSlopeContext::None;
    this->FireContext = ENPC_FireContext::None;
    this->GameState = ENPC_GameState::None;
    this->GameSubState = ENPC_GameSubState::None;
    this->GameAttackState = ENPC_GameAttackState::None;
    this->Priority = 0;
    this->bOverrideSpeed = false;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->SpeedChoice = NULL;
}

