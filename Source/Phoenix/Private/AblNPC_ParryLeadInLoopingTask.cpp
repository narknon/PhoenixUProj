#include "AblNPC_ParryLeadInLoopingTask.h"

UAblNPC_ParryLeadInLoopingTask::UAblNPC_ParryLeadInLoopingTask() {
    this->bOverrideRunAtDataLeadInTime = false;
    this->ParryLeadIn = 1.00f;
    this->bOverrideDBParryToRelease = false;
    this->ParryToRelease = 5.00f;
    this->bOverrideDBCounterType = false;
    this->OverrideCounterType = EEnemy_ParryCounterType::Default;
    this->bOverrideDBResponseType = false;
    this->OverrideResponseType = EEnemy_ParryResponseType::Default;
    this->bOverrideDBCounterStepDirection = false;
    this->OverrideCounterStepDirection = EEnemy_ParryCounterStepDirection::Default;
    this->bOverrideDBCounterStyle = false;
    this->OverrideCounterStyle = EEnemy_ParryCounterStyle::Default;
    this->bOverrideDBDodgeStyle = false;
    this->OverrideDodgeStyle = EEnemy_ParryDodgeStyle::RollAway;
    this->bParryWindowPersistPastImpact = false;
    this->bParryWindowForceCloseOnTaskEnd = false;
}

