#include "AblCollisionShape.h"

UAblCollisionShape::UAblCollisionShape() {
    this->m_CollisionChannel = ECC_WorldDynamic;
    this->m_UseAsyncQuery = false;
}

