#include "AuthoredImpact.h"

FAuthoredImpact::FAuthoredImpact() {
    this->ReactionStrength = EImpactReactionStrength::None;
    this->ImpactMaxYaw = 0.00f;
    this->ImpactMaxPitch = 0.00f;
    this->ImpactVariationYaw = 0.00f;
    this->ImpactVariationPitch = 0.00f;
    this->ImpactStrengthMin = 0.00f;
    this->ImpactStrengthMax = 0.00f;
    this->ImpactDuration = 0.00f;
    this->ImpactEaseInDuration = 0.00f;
    this->BlendBackDelay = 0.00f;
    this->BlendBackDuration = 0.00f;
    this->bUseGivenImpactStength = false;
}

