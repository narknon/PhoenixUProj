#include "NPC_SelectionState.h"

FNPC_SelectionState::FNPC_SelectionState() {
    this->StateType = ENPC_SelectionStates::None;
    this->StateEnabled = false;
    this->StateValue = 0.00f;
}

