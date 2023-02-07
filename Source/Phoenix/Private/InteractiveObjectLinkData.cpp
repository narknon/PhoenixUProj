#include "InteractiveObjectLinkData.h"

FInteractiveObjectLinkData::FInteractiveObjectLinkData() {
    this->m_startState = EInteractiveState::Normal;
    this->m_endState = EInteractiveState::Normal;
    this->m_action = EInteractiveAction::None;
}

