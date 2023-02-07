#include "Enemy_ParryWindowSetupData.h"

FEnemy_ParryWindowSetupData::FEnemy_ParryWindowSetupData() {
    this->bShowUI = false;
    this->bPersistPastImpact = false;
    this->bDilateLeadIn = false;
    this->bDilateRelease = false;
    this->bTargetIsPlayer = false;
    this->bTargetIsOnMount = false;
    this->TargetPtr = NULL;
    this->LeadIn = 0.00f;
    this->ToRelease = 0.00f;
    this->bUnblockable = false;
    this->Perfect = 0.00f;
    this->AbortDistance = 0.00f;
    this->CounterType = EEnemy_ParryCounterType::Default;
    this->ResponseType = EEnemy_ParryResponseType::Default;
    this->CounterStepDirection = EEnemy_ParryCounterStepDirection::Default;
    this->CounterStyle = EEnemy_ParryCounterStyle::Default;
    this->DodgeStyle = EEnemy_ParryDodgeStyle::RollAway;
    this->bManuallyLaunchedProjectile = false;
}

