#include "MunitionType_SubsonicSpell.h"
#include "Components/SphereComponent.h"
#include "Actor_SubsonicProximity.h"
#include "SubsonicSpellMovementComponent.h"

class AActor;
class UObject;
class UPrimitiveComponent;

void AMunitionType_SubsonicSpell::SetOnlyHitActor(AActor* OnlyHit, FName CollisionProfile) {
}

void AMunitionType_SubsonicSpell::PlayTerrainImpact(UObject* ImpactObject, const FVector& ImpactLocation, const FVector& ImpactNormal, const FVector& ImpactVelocity) {
}




USphereComponent* AMunitionType_SubsonicSpell::GetSphereComp() const {
    return NULL;
}

float AMunitionType_SubsonicSpell::GetSpeed() {
    return 0.0f;
}

USubsonicSpellMovementComponent* AMunitionType_SubsonicSpell::GetProjectileMovement() const {
    return NULL;
}

void AMunitionType_SubsonicSpell::DisableFizzle(bool bDisable) {
}

void AMunitionType_SubsonicSpell::DestroyMunition() {
}

void AMunitionType_SubsonicSpell::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


AMunitionType_SubsonicSpell::AMunitionType_SubsonicSpell(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->m_explodeOnContactWithActors = true;
    this->m_explodeOnContactWithTerrain = true;
    this->CheckForCover = false;
    this->m_spawnStaticMeshInsteadOfTerrainFx = false;
    this->StaticMeshInsteadOfTerrainFx = NULL;
    this->m_explodeWhenLifetimeExpires = true;
    this->m_deactivateParticlesOnDeath = true;
    this->m_hideMeshOnDeath = true;
    this->m_hitOnOverlap = false;
    this->DelayVelocityTime = 0.00f;
    this->m_delayedDeactivationTime = 0.00f;
    this->m_delayedParticleDeactivationTime = 0.00f;
    this->m_delayedFizzleParticleDeactivationTime = 0.00f;
    this->m_delayedDeathTime = 1.00f;
    this->ProtegoSpeedMultiplier = 1.00f;
    this->ProtegoPerfectSpeedMultiplier = 1.00f;
    this->bProtegoPerfectLoseBounce = false;
    this->SpawnAOECondition = 15;
    this->m_AOE = NULL;
    this->bCanOppugnoAfterProtego = false;
    this->OppugnoPhysicsObjectClass = NULL;
    this->bAOEUsesSpellTool = false;
    this->AOERadius = 100.00f;
    this->bAOEHitsVictimAgain = false;
    this->bCanBeDeflected = true;
    this->bOnlySpawnOnImpact = false;
    this->bTrackDistanceTraveled = false;
    this->bTrackAngleToPlayer = false;
    this->ProjectileMotionAkComponent = NULL;
    this->PerceptionNoiseEventLoudness = 1.00f;
    this->PerceptionNoiseEventMaxRange = 0.00f;
    this->SubsonicProximityActorClass = AActor_SubsonicProximity::StaticClass();
    this->SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    this->ProjectileMovementComponent = CreateDefaultSubobject<USubsonicSpellMovementComponent>(TEXT("ProjectileMovementComponent"));
    this->SpellTool = NULL;
    this->bEnableAsyncLoadAndTrigger = false;
    this->SpawnClassRef = NULL;
    this->SubsonicProximityActor = NULL;
}

