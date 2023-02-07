#include "AblBranchEvent.h"

UAblBranchEvent::UAblBranchEvent() {
    this->m_BranchAbility = NULL;
    this->m_DynamicBranchAbility = false;
    this->m_MustPassAllConditions = false;
    this->m_CopyTargetsOnBranch = false;
}

