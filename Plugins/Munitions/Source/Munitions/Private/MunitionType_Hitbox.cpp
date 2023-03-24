#include "MunitionType_Hitbox.h"

AMunitionType_Hitbox::AMunitionType_Hitbox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhysicsImpulse = 0.00f;
    this->m_hitVictimInterval = 10.00f;
    this->bUseMunitionOwnerAtImpactSource = false;
    this->bUseTraceAsDamageImpactDirection = false;
    this->m_damageType = NULL;
    this->bUnblockable = false;
    this->CollisionChannel = ECC_WorldDynamic;
    this->bOnlyDetectBlockingHits = false;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_hitBlockedSfx = NULL;
}

