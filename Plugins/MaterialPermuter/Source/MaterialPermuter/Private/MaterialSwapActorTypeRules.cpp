#include "MaterialSwapActorTypeRules.h"

FMaterialSwapActorTypeRules::FMaterialSwapActorTypeRules() {
    this->Players = EMaterialSwapRulesTypeMode::Default;
    this->Characters = EMaterialSwapRulesTypeMode::Default;
    this->Pawns = EMaterialSwapRulesTypeMode::Default;
    this->Moveable = EMaterialSwapRulesTypeMode::Default;
    this->Stationary = EMaterialSwapRulesTypeMode::Default;
}

