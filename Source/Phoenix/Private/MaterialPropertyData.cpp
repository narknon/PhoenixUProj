#include "MaterialPropertyData.h"

UMaterialPropertyData::UMaterialPropertyData() {
    this->ObjectPropertyType = EObjectPropertyType::Inanimate;
    this->bWaterproof = false;
    this->bImmuneToFireDamage = false;
    this->bDamagableWhenCharred = true;
    this->bDestroyWhenCharred = false;
    this->bOnlyBurnWhenCriticalHealth = false;
    this->bOverlayBurn = true;
    this->bFreezable = true;
    this->bDamagableWhenFrozen = false;
    this->PieceHitSfx = NULL;
    this->FireDamagePerSecond = 3.00f;
    this->BurnRate = 0.00f;
    this->CharacterDurationScale = 1.00f;
    this->BurnRingWidth = 10.00f;
    this->FireJumpDistance = 60.00f;
    this->CharredPercent = 0.90f;
    this->BurnMaterial = NULL;
    this->CharredMaterial = NULL;
    this->CharredDamageMultiplier = 1.00f;
    this->FireParticleSpawnRateScale = 1.00f;
    this->IcePhysicalMaterial = NULL;
    this->FrozenDamageMultiplier = 1.00f;
    this->FastSfx = NULL;
    this->bDestroyWhenCharredDelay = 0.00f;
}

