#include "AblTaskCondition_ReactionData.h"

UAblTaskCondition_ReactionData::UAblTaskCondition_ReactionData() {
    this->bCompareImpactDirectionWithActorForward = false;
    this->ImpactDotForwardMin = -1.00f;
    this->ImpactDotForwardMax = 1.00f;
}

