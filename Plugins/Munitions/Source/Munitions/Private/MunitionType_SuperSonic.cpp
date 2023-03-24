#include "MunitionType_SuperSonic.h"

AMunitionType_SuperSonic::AMunitionType_SuperSonic(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_hitActorFX = NULL;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainFX = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_placeDecal = false;
    this->m_decalMaterial = NULL;
    this->m_decalSize = 0.00f;
    this->m_decalLifeSpan = 0.00f;
}

