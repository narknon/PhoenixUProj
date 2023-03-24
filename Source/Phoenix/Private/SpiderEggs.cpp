#include "SpiderEggs.h"
#include "AkComponent.h"
#include "CognitionStimuliSourceComponent.h"
#include "Components/ArrowComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"
#include "EnemyStateComponent.h"
#include "LootDropComponent.h"

class AActor;
class UPrimitiveComponent;



void ASpiderEggs::OnOverlapEnd_StealthActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASpiderEggs::OnOverlapEnd_ProximitySphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASpiderEggs::OnOverlapEnd_ActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ASpiderEggs::OnOverlapBegin_StealthActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ASpiderEggs::OnOverlapBegin_ProximitySphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ASpiderEggs::OnOverlapBegin_ActivationSphere(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


void ASpiderEggs::_UpdateObjectState() {
}

void ASpiderEggs::_StopPulse() {
}

void ASpiderEggs::_StopMotion() {
}

void ASpiderEggs::_StopForceBurstDelay() {
}


void ASpiderEggs::_StopFire() {
}

void ASpiderEggs::_StopExplodeDelay() {
}

void ASpiderEggs::_StopBreathing() {
}

void ASpiderEggs::_StopAlertDelay() {
}

void ASpiderEggs::_StartTimerDelays() {
}

void ASpiderEggs::_StartPulse() {
}

void ASpiderEggs::_StartMotion() {
}

void ASpiderEggs::_StartForceBurstDelay() {
}



void ASpiderEggs::_StartBurst() {
}

void ASpiderEggs::_StartBreathing() {
}

void ASpiderEggs::_SpawnLoot() {
}

void ASpiderEggs::_SpawnEnemies() {
}

void ASpiderEggs::_SetupParamsForSpawnType_Implementation() {
}

void ASpiderEggs::_ResumePulse() {
}

void ASpiderEggs::_ResumeMotion() {
}

void ASpiderEggs::_ResumeBreathing() {
}

bool ASpiderEggs::_RemoveActorInRadius(AActor* InActor, bool RemoveAll) {
    return false;
}

void ASpiderEggs::_PropagateFire() {
}

void ASpiderEggs::_PrintDebug(const FString& Name, const float Value) {
}

void ASpiderEggs::_PlayExplodeEffects() {
}

void ASpiderEggs::_PlayDamagedEffects(const float InDamage) {
}

void ASpiderEggs::_PausePulse() {
}

void ASpiderEggs::_PauseMotion() {
}

void ASpiderEggs::_PauseBreathing() {
}

void ASpiderEggs::_LightFire() {
}

bool ASpiderEggs::_IsPausedBySpell() {
    return false;
}

void ASpiderEggs::_HideEggSacMesh() {
}

void ASpiderEggs::_HideBaseMesh() {
}

void ASpiderEggs::_HeavyBlowExplode() {
}

bool ASpiderEggs::_HasActorsInRadius() {
    return false;
}

void ASpiderEggs::_ForceBurstStart() {
}

void ASpiderEggs::_ForceBurst() {
}

void ASpiderEggs::_FireTick() {
}

void ASpiderEggs::_Fire() {
}

FTransform ASpiderEggs::_FindValidEnemySpawn() {
    return FTransform{};
}

void ASpiderEggs::_Explode() {
}

void ASpiderEggs::_DoDamageOnExplode() {
}

void ASpiderEggs::_DoDamageFire() {
}



void ASpiderEggs::_AlertNearby() {
}

bool ASpiderEggs::_AddActorInRadius(AActor* InActor) {
    return false;
}

void ASpiderEggs::_ActivateObject() {
}

ASpiderEggs::ASpiderEggs(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SM_SpiderEggs_A_Broken = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cSM_SpiderEggs_A_Broken"));
    this->SK_SpiderEggs_01 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("cSK_SpiderEggs_01"));
    this->ActivationRadiusSphere = CreateDefaultSubobject<USphereComponent>(TEXT("cActivationRadiusSphere"));
    this->ProximitySphere = CreateDefaultSubobject<USphereComponent>(TEXT("cProximitySphere"));
    this->StealthActivationSphere = CreateDefaultSubobject<USphereComponent>(TEXT("cStealthActivationSphere"));
    this->LitFlames = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("cLitFlames"));
    this->VFX_P_Spider_Pro_Impact_Ground_2 = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("cVFX_P_Spider_Pro_Impact_Ground_2"));
    this->Ak_BP_SpiderEggs = CreateDefaultSubobject<UAkComponent>(TEXT("cAk_BP_SpiderEggs"));
    this->Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cBase"));
    this->SpawnAngle = CreateDefaultSubobject<UArrowComponent>(TEXT("cSpawnAngle"));
    this->SacFire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("cSacFire"));
    this->IncendioFire = CreateDefaultSubobject<UNiagaraComponent>(TEXT("cIncendioFire"));
    this->LootDrop = CreateDefaultSubobject<ULootDropComponent>(TEXT("cLootDrop"));
    this->EnemyState = CreateDefaultSubobject<UEnemyStateComponent>(TEXT("cEnemyState"));
    this->CognitionStimuliSource = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("cCognitionStimuliSource"));
    this->bIsActive = false;
    this->bIsBreathing = false;
    this->bIsPulsing = false;
    this->bIsOnfire = false;
    this->bWasKilledByFire = false;
    this->bIsFrozen = false;
    this->bIsArrested = false;
    this->bWasKilled = false;
    this->bHeavyBlow = false;
    this->bFireJustStarted = false;
    this->bAlertProcessed = false;
    this->mBreathStartTime = 0.00f;
    this->mActivationRadius = 700.00f;
    this->mStealthActivationRadius = 350.00f;
    this->mBurstTime = 5.60f;
    this->mBurstDelay = 2.00f;
    this->mNearEggAlertRadius = 450.00f;
    this->mNearEggAlertTime = 450.00f;
    this->mNearEggAlertDelay = 450.00f;
    this->mProximityRadius = 500.00f;
    this->mForceBurstTime = 500.00f;
    this->mForceBurstDelay = 450.00f;
    this->mExplodeDamage = 20.00f;
    this->mExplodeRadius = 400.00f;
    this->mDamageDelay = 0.75f;
    this->bAllowDebug = false;
    this->bHideBase = false;
    this->bIsBurst = false;
    this->bSpawnSpidersOnExplode = true;
    this->bSpawnWhenHit = false;
    this->bIgnoreTriggerSphere = false;
    this->mSpidersToSpawn = ESpiderTypeEnum::ST_Woodlouse;
    this->mSpawnAngleSpread = 60.00f;
    this->mSpawnLandDistance = 100.00f;
    this->bSpawnLootOnExplode = false;
    this->mLootChance = 0.50f;
    this->mDamageAmount = 200.00f;
    this->mFireLifetime = 30.00f;
    this->mFireDamage = 20.00f;
    this->mBreathingAnimSpeed = 0.50f;
    this->mPulsingAnimSpeed = 2.00f;
    this->mAsyncLoadRadius = 3000.00f;
    this->mExplodeIgnoreInterface = NULL;
    this->mExplodeMunition = NULL;
    this->bCanRemoveStayInVolumes = false;
    this->StayInRadius = 1000.00f;
    this->StayInVolumeTeleportTimeout = -1.00f;
    this->bStayInVolumeOffNavTeleport = false;
    this->mAkEvent_Explode = NULL;
    this->mNiagara_HeavyFireBurstEffect = NULL;
    this->mNiagara_FirePopEffect = NULL;
    this->mNiagara_FrozenBurstEffect = NULL;
    this->mNiagara_DamagedEffect = NULL;
}

