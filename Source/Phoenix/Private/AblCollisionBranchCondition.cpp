#include "AblCollisionBranchCondition.h"

UAblCollisionBranchCondition::UAblCollisionBranchCondition() {
    this->DetectionType = EAblCollisionBranchDetectionType::MoveDirectionDotHitNormal;
    this->DotProductLowerBound = -1.00f;
    this->DotProductUpperBound = 1.00f;
    this->BranchOnImminentCollisionLength = 0.00f;
    this->MinSpeed = 0.00f;
    this->bCheckForInheritance = false;
}

