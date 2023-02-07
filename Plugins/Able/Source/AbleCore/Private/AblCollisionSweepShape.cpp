#include "AblCollisionSweepShape.h"

UAblCollisionSweepShape::UAblCollisionSweepShape() {
    this->m_CollisionChannel = ECC_WorldDynamic;
    this->m_OnlyReturnBlockingHit = false;
    this->m_UseAsyncQuery = false;
}

