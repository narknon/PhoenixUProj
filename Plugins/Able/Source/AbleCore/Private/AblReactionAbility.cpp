#include "AblReactionAbility.h"

class UAblAbilityContext;
class UAblReactionData;

UAblReactionData* UAblReactionAbility::GetReactionData(const UAblAbilityContext* Context) const {
    return NULL;
}

UAblReactionAbility::UAblReactionAbility() {
    this->ChannelType = EAblNpcReactChannelType::Fullbody;
    this->PlayerInstigatorTicketTimeIncrease = 0.00f;
    this->bAddDeadTagIfDead = false;
    this->bWarmUpRagdollPhysics = true;
    this->bBranchToRagdollInWater = true;
}

