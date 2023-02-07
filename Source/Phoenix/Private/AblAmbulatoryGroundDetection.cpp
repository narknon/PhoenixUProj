#include "AblAmbulatoryGroundDetection.h"

UAblAmbulatoryGroundDetection::UAblAmbulatoryGroundDetection() {
    this->OnGroundDistance = 20.00f;
    this->bGroundMustBeWalkable = false;
    this->bGroundMustNotBePawn = false;
    this->bInverse = false;
}

