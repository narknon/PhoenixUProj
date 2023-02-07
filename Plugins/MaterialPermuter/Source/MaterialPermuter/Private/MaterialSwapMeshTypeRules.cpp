#include "MaterialSwapMeshTypeRules.h"

FMaterialSwapMeshTypeRules::FMaterialSwapMeshTypeRules() {
    this->Static = EMaterialSwapRulesTypeMode::Default;
    this->Skeletal = EMaterialSwapRulesTypeMode::Default;
    this->Instanced = EMaterialSwapRulesTypeMode::Default;
    this->Spline = EMaterialSwapRulesTypeMode::Default;
    this->Moveable = EMaterialSwapRulesTypeMode::Default;
    this->Stationary = EMaterialSwapRulesTypeMode::Default;
    this->ReceivesDecals = EMaterialSwapRulesTypeMode::Default;
    this->ReceivesWeatherDecals = EMaterialSwapRulesTypeMode::Default;
    this->RenderCustomDepth = EMaterialSwapRulesTypeMode::Default;
}

