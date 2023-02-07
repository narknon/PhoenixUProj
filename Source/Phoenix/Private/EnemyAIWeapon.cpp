#include "EnemyAIWeapon.h"
#include "Templates/SubclassOf.h"

class AActor;
class AMunitionType_Base;
class AMunitionType_Physics;
class APawn;
class UInteractionArchitectAsset;
class UPrimitiveComponent;
class USceneComponent;


void AEnemyAIWeapon::TrackPoints(const FVector& InThrowLoc, const FVector& InWieldLoc) {
}

void AEnemyAIWeapon::SetState(const TEnumAsByte<EEnemyAIWeaponState::Type>& InState) {
}

void AEnemyAIWeapon::RangedNotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) {
}



bool AEnemyAIWeapon::OverlapAttackCapsule_New(USceneComponent* OverlappedComponent, AActor* OtherActor, USceneComponent* OtherComponent, FHitResult SweepResult, FHitResult& OutHitResult) {
    return false;
}

bool AEnemyAIWeapon::OverlapAttackCapsule(AActor* InVictim, FHitResult InHitResult, FEnemy_WeaponAttackOverlapData& OutOverlapData) {
    return false;
}

void AEnemyAIWeapon::OnMunitionImpact(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData) {
}

void AEnemyAIWeapon::OnMunitionDestroyed(AMunitionType_Base* InMunitionInstance) {
}

void AEnemyAIWeapon::HandlePhysicsMunitionHit(EPhysicsMunitionHitType PhysicsMunitionHitType, FHitResult HitResult) {
}

FVector AEnemyAIWeapon::GetWieldImpactNormal(const FVector& InNormal, const AActor* InHitActor) {
    return FVector{};
}

FVector AEnemyAIWeapon::GetThrowImpactNormal(const FVector& InNormal, const AActor* InHitActor) {
    return FVector{};
}

TEnumAsByte<EEnemyAIWeaponState::Type> AEnemyAIWeapon::GetState() const {
    return EEnemyAIWeaponState::None;
}

AMunitionType_Physics* AEnemyAIWeapon::GetMunition() {
    return NULL;
}

AActor* AEnemyAIWeapon::GetAttackInstigator() const {
    return NULL;
}

void AEnemyAIWeapon::ForceStoreWeapon() {
}

void AEnemyAIWeapon::FireWeaponAOEMunitionNew(TSubclassOf<AMunitionType_Base> InMunitionActor, AActor* TargetActor, FVector InLocation, UInteractionArchitectAsset* InMunitionDataAsset, FName InMunitionImpactType, FGameplayTagContainer InMunitionTagContainer, float AOEDamage) {
}

void AEnemyAIWeapon::FireWeaponAOEMunition(TSubclassOf<AMunitionType_Base> InMunitionActor, AActor* TargetActor, FVector InLocation, UInteractionArchitectAsset* InMunitionDataAsset, FName InMunitionImpactType, FGameplayTagContainer InMunitionTagContainer, float AOEDamage) {
}

AMunitionType_Base* AEnemyAIWeapon::FireAtTarget(AActor* TargetPtr, APawn* WeaponOwnerPtr, float AccuracyOffset, float InDamage, float OverrideSpeed) {
    return NULL;
}


void AEnemyAIWeapon::EnableTrackPoints(bool bEnable) {
}

void AEnemyAIWeapon::EnablePhysicsSimEvent_Implementation(bool bEnable) {
}

AActor* AEnemyAIWeapon::DoDisarmOnOwner(FVector HitDirection, AActor* InInstigator) {
    return NULL;
}


void AEnemyAIWeapon::BroadcastWeaponEvent(EEnemyAIWeapon_Event InEvent) {
}

void AEnemyAIWeapon::BroadcastWeapon_AnimEvent(FName InName) {
}

AEnemyAIWeapon::AEnemyAIWeapon() {
    this->AggroCorruptionSettings = NULL;
    this->AggroCorruptionInstance = NULL;
    this->EquipApplyTagTime = 0.00f;
    this->ThrowSpeed = 2500.00f;
    this->bIgnoreGravityWhenThrown = false;
    this->throwOffsetForward = 160.00f;
    this->throwTargetHeightOffset = 0.00f;
    this->ProtegoBlockSpeed = 850.00f;
    this->ProtegoBounceBackSpeed = 5000.00f;
    this->ProtegoDeflectSpeed = 2000.00f;
    this->bProtegoConstrainDirToUp = 1.00f;
    this->impactFxMinRepeatTime = 0.70f;
    this->bTerrainDestroysMunition = true;
    this->bAllowWeaponDeflection = true;
    this->bDestroyWeaponOnSuccessfulPhysicsMunitionHit = false;
    this->bForceLifetimeCountdownAfterRangedHit = false;
    this->EquipMode = EEnemyWeaponEquip::None;
    this->bCanSwitchOut = false;
    this->StoredWeaponTypeEnum = EEnemyWeaponTypeEnum::ESW_Default;
    this->EquipPriority = 100;
    this->EquipWeight = 1;
    this->weaponDamage = 0.00f;
    this->AttachRule = EWeaponAttachmentTransformRules::SnapToTargetNotIncludingScale;
    this->bPowerupEligible = false;
    this->PowerupDamagePercent = 1.50f;
    this->PowerupTimeout = -1.00f;
    this->bAllowSpellDeflection = false;
    this->bIsAShield = false;
    this->SpawnWithPhysics = true;
    this->bCanBeStored = true;
    this->bCanBeThrown = true;
    this->bCanBeDisarmed = true;
    this->bCanBeRecovered = false;
    this->bJustHideForRecovery = false;
    this->PostThrownLifetime = 5.00f;
    this->PostDropLifetime = 5.00f;
    this->PostProtegoLifetime = 5.00f;
    this->LifetimeEndEvent = 2.00f;
    this->bOnWall = false;
    this->MunitionActor = NULL;
    this->MunitionDataAsset = NULL;
    this->AOE1MunitionActor = NULL;
    this->AOE1MunitionDataAsset = NULL;
    this->AOE1TargetActor = NULL;
    this->bAllowOverideAttackSocket = true;
    this->bIsABlindManWeapon = false;
}

