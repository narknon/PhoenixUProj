#include "GlobalLightingBlendableAction.h"

FGlobalLightingBlendableAction::FGlobalLightingBlendableAction() {
    this->Owner = NULL;
    this->Blendable = NULL;
    this->Priority = 0.00f;
    this->weight = 0.00f;
    this->InputType = EGlobalLightingBlendableInputType::BaseValues;
}

