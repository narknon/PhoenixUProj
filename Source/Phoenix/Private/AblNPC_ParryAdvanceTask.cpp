#include "AblNPC_ParryAdvanceTask.h"

UAblNPC_ParryAdvanceTask::UAblNPC_ParryAdvanceTask() {
    this->Type = EEnemy_ParryWindowType::Single;
    this->bKeepWindowOpen = false;
    this->bTriggerFiredEvent = false;
    this->FiredEventType = EEnemy_ParryType::None;
    this->bOverrideDBParryLeadIn = false;
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
}

