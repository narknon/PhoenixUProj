#include "RepairData.h"

FRepairData::FRepairData() {
    this->DestructibleGeometryCollection = NULL;
    this->BaseMesh = NULL;
    this->DeathNoiseSize = ENoiseSize::NoNoise;
    this->bFadeOutEntireGC = false;
    this->ChunkFadeOutDelay = 0.00f;
    this->ChunkFadeVisiblePct = 0.00f;
    this->ChunkFadeVisibleMax = 0;
    this->ChunkFadeVisibleMin = 0;
    this->DestroyFromCenterMultiplier = 0.00f;
    this->DestroyObjectRadius = 0.00f;
    this->DestroyObjectStrain = 0.00f;
    this->DestroyLinearForce = 0.00f;
    this->DestroyLinearForceMultiplier = 0.00f;
    this->DestroyAngularForceMultiplier = 0.00f;
    this->DestroyRadialForce = 0.00f;
    this->DestroyObjectFieldSystemClass = NULL;
    this->ChunkPhysicalMaterial = NULL;
    this->ChunkTrailParticleSystem = NULL;
    this->ChunkTrailNiagaraVfx = NULL;
    this->ChunkFadeParticleSystem = NULL;
    this->ChunkFadeNiagaraVfx = NULL;
    this->ChunkImpactParticleSystem = NULL;
    this->ChunkImpactNiagaraVfx = NULL;
    this->ChunkImpactDelay = 0.00f;
    this->ChunkImpactMinimumImpulse = 0.00f;
    this->ChunkImpactMinimumVolume = 0.00f;
    this->RepairSfx = NULL;
    this->ReparoDataPtr = NULL;
    this->bRepairable = false;
    this->bRepairChildren = false;
    this->bRepairInPlaceOnly = false;
    this->bRepairUsingActorTransform = false;
    this->bUseMainComponentTransform = false;
    this->Hide = false;
    this->DisableCollision = false;
    this->DisablePhysics = false;
    this->bEnableCollisionDuringRepair = false;
    this->bNavigationBlockedIfDestroyed = false;
    this->bCommonBreakable = false;
    this->bSpawnAnchorField = false;
    this->bDestroyAnchorFieldOnDestroyed = false;
    this->bDisableGC = false;
    this->bChunkCharacterStepUpOn = false;
    this->bLargeDestructible = false;
    this->bAutoTargetableBroken = false;
}

