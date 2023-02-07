#include "AblLeavingNavMeshTaskCondition.h"

UAblLeavingNavMeshTaskCondition::UAblLeavingNavMeshTaskCondition() {
    this->MinSpeed = 0.00f;
    this->Distance = 50.00f;
    this->DotProductCheck = 0.90f;
    this->bCheckForCollision = false;
}

