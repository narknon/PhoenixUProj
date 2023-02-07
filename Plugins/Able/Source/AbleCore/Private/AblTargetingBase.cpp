#include "AblTargetingBase.h"

UAblTargetingBase::UAblTargetingBase() {
    this->m_AutoCalculateRange = true;
    this->m_Range = 0.00f;
    this->m_CalculateAs2DRange = true;
    this->m_CollisionChannel = ECC_Pawn;
    this->m_UseAsync = false;
}

