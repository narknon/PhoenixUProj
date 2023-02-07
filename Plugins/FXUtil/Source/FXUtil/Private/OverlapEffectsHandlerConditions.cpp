#include "OverlapEffectsHandlerConditions.h"

FOverlapEffectsHandlerConditions::FOverlapEffectsHandlerConditions() {
    this->InstigatorCondition = NULL;
    this->VictimCondition = NULL;
    this->Logic = EOverlapEffectsHandlerConditionLogic::And;
}

