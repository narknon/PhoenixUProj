#include "MunitionImpactData.h"

FMunitionImpactData::FMunitionImpactData() {
    this->m_pMunitionActor = NULL;
    this->m_pMunitionOwner = NULL;
    this->m_pInstigator = NULL;
    this->DamageTypeClass = NULL;
    this->m_damage = 0.00f;
    this->m_maxDamage = 0.00f;
    this->CharacterDamage = 0.00f;
}

