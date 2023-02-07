#include "MunitionType_AOE.h"

AMunitionType_AOE::AMunitionType_AOE() {
    this->MinDamage = 0.00f;
    this->m_radiusStart = 100.00f;
    this->m_radiusEnd = 1000.00f;
    this->bUseCustomGrowthDuration = false;
    this->CustomGrowthDuration = 0.50f;
    this->m_hitVictimInterval = 10.00f;
    this->m_damageType = NULL;
    this->m_explosionFX = NULL;
    this->PlayExplosionOnGround = false;
    this->m_explosionSfx = NULL;
    this->PhysicsImpulse = 0.00f;
    this->m_stopAtCollision = true;
    this->bUnblockable = false;
    this->bBreakBlockFX = true;
    this->m_hitActorFX = NULL;
    this->m_hitTerrainFX = NULL;
    this->m_hitBlockedFX = NULL;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_hitBlockedSfx = NULL;
}

