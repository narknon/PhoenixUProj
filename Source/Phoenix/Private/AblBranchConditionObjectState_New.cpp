#include "AblBranchConditionObjectState_New.h"

UAblBranchConditionObjectState_New::UAblBranchConditionObjectState_New() {
    this->bCheckDeathState = true;
    this->ObjectStateBranchCondition = EObjectStateBranchCondition::IsDead;
    this->bCheckDatabaseId = false;
    this->bCheckSubtypeId = false;
    this->bInWater = false;
    this->bNotInWater = false;
    this->bInvert = false;
}

