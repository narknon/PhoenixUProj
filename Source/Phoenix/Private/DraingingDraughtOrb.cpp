#include "DraingingDraughtOrb.h"

void ADraingingDraughtOrb::Attack() {
}

ADraingingDraughtOrb::ADraingingDraughtOrb() {
    this->m_CurActiveRotation = 0.00f;
    this->m_AttackingDistance = 30.00f;
    this->m_AttackingAcceleration = 15000.00f;
    this->m_AttackingSpeed = 5000.00f;
}

