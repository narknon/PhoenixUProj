#include "AblBranchConditionOnInput.h"

UAblBranchConditionOnInput::UAblBranchConditionOnInput() {
    this->m_MustBeRecentlyPressed = false;
    this->m_RecentlyPressedTimeLimit = 0.10f;
}

