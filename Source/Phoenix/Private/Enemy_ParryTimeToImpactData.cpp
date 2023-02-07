#include "Enemy_ParryTimeToImpactData.h"

FEnemy_ParryTimeToImpactData::FEnemy_ParryTimeToImpactData() {
    this->TimeToImpact = 0.00f;
    this->WindowID = 0;
    this->bUnblockable = false;
    this->bPerfect = false;
    this->CounterType = EEnemy_ParryCounterType::Default;
    this->ResponseType = EEnemy_ParryResponseType::Default;
    this->CounterStepDirection = EEnemy_ParryCounterStepDirection::Default;
    this->CounterStyle = EEnemy_ParryCounterStyle::Default;
    this->DodgeStyle = EEnemy_ParryDodgeStyle::RollAway;
    this->ButtonPressed = EEnemy_ParryButtonPressed::None;
}

