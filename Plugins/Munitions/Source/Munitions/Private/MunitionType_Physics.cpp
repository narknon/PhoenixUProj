#include "MunitionType_Physics.h"

AMunitionType_Physics::AMunitionType_Physics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_speed = 10000.00f;
    this->m_explodeOnContactWithActors = true;
    this->m_explodeOnContactWithTerrain = true;
    this->m_explodeWhenLifetimeExpires = true;
    this->m_AOE = NULL;
    this->m_hitActorFX = NULL;
    this->m_hitTerrainFX = NULL;
    this->m_hitBlockedFX = NULL;
    this->m_hitDeflectedFX = NULL;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_hitBlockedSfx = NULL;
    this->m_hitDeflectedSfx = NULL;
    this->m_destroyedTargetSfx = NULL;
    this->m_placeDecal = false;
    this->m_decalMaterial = NULL;
    this->m_decalLifeSpan = 0.00f;
}

