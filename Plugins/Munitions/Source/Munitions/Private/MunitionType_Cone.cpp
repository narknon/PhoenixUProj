#include "MunitionType_Cone.h"

AMunitionType_Cone::AMunitionType_Cone() {
    this->m_Range = 1000.00f;
    this->m_endRadius = 100.00f;
    this->m_damageType = NULL;
    this->m_stopAtCollision = true;
    this->m_explosionFX = NULL;
    this->m_hitActorFX = NULL;
    this->m_hitTerrainFX = NULL;
    this->m_hitBlockedFX = NULL;
    this->m_explosionSfx = NULL;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_hitBlockedSfx = NULL;
}

