#include "MaterialPropertyOverrideData.h"

FMaterialPropertyOverrideData::FMaterialPropertyOverrideData() {
    this->bOverrideObjectPropertyType = false;
    this->ObjectPropertyType = EObjectPropertyType::Animate;
    this->bOverrideWaterproof = false;
    this->bWaterproof = false;
    this->bOverrideImmuneToFireDamage = false;
    this->bImmuneToFireDamage = false;
    this->bOverrideDamagableWhenCharred = false;
    this->bDamagableWhenCharred = false;
    this->bOverrideDestroyWhenCharred = false;
    this->bDestroyWhenCharred = false;
    this->bOverrideFireDamagePerSecond = false;
    this->FireDamagePerSecond = 0.00f;
    this->bOverrideBurnRate = false;
    this->BurnRate = 0.00f;
    this->bOverrideCharacterDurationScale = false;
    this->CharacterDurationScale = 0.00f;
    this->bOverrideBurnRingWidth = false;
    this->BurnRingWidth = 0.00f;
    this->bOverrideFireJumpDistance = false;
    this->FireJumpDistance = 0.00f;
    this->bOverrideCharredPercent = false;
    this->CharredPercent = 0.00f;
    this->bOverridOverlayBurn = false;
    this->bOverlayBurn = false;
    this->bOverrideBurnMaterial = false;
    this->BurnMaterial = NULL;
    this->bOverrideCharredMaterial = false;
    this->CharredMaterial = NULL;
    this->bOverrideCharredDamageMultiplier = false;
    this->CharredDamageMultiplier = 0.00f;
    this->bOverrideFireParticleSpawnRateScale = false;
    this->FireParticleSpawnRateScale = 0.00f;
    this->bOverrideFireStartSfx = false;
    this->FireStartSfx = NULL;
    this->bOverrideFireLoopSfx = false;
    this->FireLoopSfx = NULL;
    this->bOverrideFireEndSfx = false;
    this->FireEndSfx = NULL;
    this->bOverrideFreezable = false;
    this->bFreezable = false;
    this->bOverrideDamagableWhenFrozen = false;
    this->bDamagableWhenFrozen = false;
    this->bOverrideIcePhysicalMaterial = false;
    this->IcePhysicalMaterial = NULL;
    this->bOverrideFrozenDamageMultiplier = false;
    this->FrozenDamageMultiplier = 0.00f;
}

