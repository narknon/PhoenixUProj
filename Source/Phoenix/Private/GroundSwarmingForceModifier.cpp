#include "GroundSwarmingForceModifier.h"

FGroundSwarmingForceModifier::FGroundSwarmingForceModifier() {
    this->Type = EGroundSwarmingForceModifierType::Follow;
    this->InnerRadius = 0.00f;
    this->InnerMultiplier = 0.00f;
    this->OuterRadius = 0.00f;
    this->OuterMultiplier = 0.00f;
    this->bUseXYDistance = false;
    this->bEnabled = false;
}

