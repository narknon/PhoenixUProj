#include "MunitionType_Subsonic.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MunitionMovementComponent.h"



USphereComponent* AMunitionType_Subsonic::GetSphereComp() const {
    return NULL;
}

UMunitionMovementComponent* AMunitionType_Subsonic::GetProjectileMovement() const {
    return NULL;
}

USkeletalMeshComponent* AMunitionType_Subsonic::GetMeshComp() const {
    return NULL;
}

void AMunitionType_Subsonic::DestroyMunition() {
}

AMunitionType_Subsonic::AMunitionType_Subsonic(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_speed = 10000.00f;
    this->m_gravity = 0.00f;
    this->m_explodeOnContactWithActors = true;
    this->m_explodeOnContactWithTerrain = true;
    this->m_explodeWhenLifetimeExpires = true;
    this->m_deactivteParticlesOnDeath = true;
    this->m_delayedDeactivationTime = 0.00f;
    this->m_delayedDeathTime = 1.00f;
    this->m_physicsImpulse = 0.00f;
    this->m_AOE = NULL;
    this->m_hitActorFX = NULL;
    this->m_hitTerrainFX = NULL;
    this->m_hitBlockedFX = NULL;
    this->m_fizzleOutFX = NULL;
    this->m_hitActorNiagaraFX = NULL;
    this->m_hitTerrainNiagaraFX = NULL;
    this->m_hitBlockedNiagaraFX = NULL;
    this->m_fizzleOutNiagaraFX = NULL;
    this->m_destroyedTargetSfx = NULL;
    this->m_hitActorSfx = NULL;
    this->m_hitTerrainSfx = NULL;
    this->m_hitBlockedSfx = NULL;
    this->m_fizzleOutSfx = NULL;
    this->m_placeDecal = false;
    this->m_decalMaterial = NULL;
    this->m_decalLifeSpan = 10.00f;
    this->m_decalFadeTime = 2.00f;
    this->HomingMarkerOffsetCurve = NULL;
    this->HomingAccelerationCurve = NULL;
    this->m_sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    this->m_meshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->ProjectileMovementComponent = CreateDefaultSubobject<UMunitionMovementComponent>(TEXT("ProjectileMovementComponent"));
}

