#include "AblNpcStartReactionTask.h"

UAblNpcStartReactionTask::UAblNpcStartReactionTask() {
    this->ReactionAbility = NULL;
    this->bStartReactionOnlyOnce = true;
    this->bMustPassAllConditions = true;
    this->bUseCurrentReactionData = false;
}

