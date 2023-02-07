#include "Enemy_Idle.h"

FEnemy_Idle::FEnemy_Idle() {
    this->ContextMatch = EEnemy_ContextMatch::Any;
    this->SupportedContexts = 0;
    this->SupportedWeapons = 0;
    this->MinAngle = 0.00f;
    this->MaxAngle = 0.00f;
    this->AASupportedDirections = 0;
    this->Chance = 0.00f;
}

