#include "Enemy_MobilityAbilityData.h"

FEnemy_MobilityAbilityData::FEnemy_MobilityAbilityData() {
    this->MoveAbilityPtr = NULL;
    this->AnimSpeedMin = 0.00f;
    this->AnimSpeedMax = 0.00f;
    this->TurnAssistCurve = NULL;
    this->TurnAssistTimeMultiplier = NULL;
}

