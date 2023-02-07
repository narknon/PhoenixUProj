#include "StencilPrimitiveTypeRules.h"

FStencilPrimitiveTypeRules::FStencilPrimitiveTypeRules() {
    this->Static = EStencilRulesTypeMode::Default;
    this->Skeletal = EStencilRulesTypeMode::Default;
    this->Instanced = EStencilRulesTypeMode::Default;
    this->Spline = EStencilRulesTypeMode::Default;
    this->Moveable = EStencilRulesTypeMode::Default;
    this->Stationary = EStencilRulesTypeMode::Default;
    this->ReceivesDecals = EStencilRulesTypeMode::Default;
    this->ReceivesWeatherDecals = EStencilRulesTypeMode::Default;
    this->RenderCustomDepth = EStencilRulesTypeMode::Default;
}

