#include "AblNpcCollisionBranchCondition.h"

UAblNpcCollisionBranchCondition::UAblNpcCollisionBranchCondition() {
    this->DetectionType = EAblNpcCollisionDetectionType::MoveDirectionDotHitNormal;
    this->DotProductLowerBound = -1.00f;
    this->DotProductUpperBound = 1.00f;
    this->BranchOnImminentCollisionLength = 0.00f;
    this->MinSpeed = 0.00f;
}

