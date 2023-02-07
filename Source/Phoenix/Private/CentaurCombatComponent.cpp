#include "CentaurCombatComponent.h"

bool UCentaurCombatComponent::IsUsingStanceA() {
    return false;
}

UCentaurCombatComponent::UCentaurCombatComponent() {
    this->bUseStanceVariation = true;
    this->StanceVariationAPercentage = 0.50f;
}

