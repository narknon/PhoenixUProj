#include "Enemy_WeaponComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AEnemyAIWeapon;
class UEnemyAIAttackData;
class UInteractionArchitectAsset;

void UEnemy_WeaponComponent::ThrowWeapon() {
}

bool UEnemy_WeaponComponent::StoreWeapon(AEnemyAIWeapon* InWeaponPtr) {
    return false;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::SpawnWeapon(TSubclassOf<AEnemyAIWeapon> SpawnWeaponClass) {
    return NULL;
}

void UEnemy_WeaponComponent::SetWeaponToRecover(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::SetWeaponToAcquire(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::SetWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::SetSpawnEnable(bool Flag) {
}

void UEnemy_WeaponComponent::SetShieldToAcquire(AEnemyAIWeapon* InShieldPtr) {
}

void UEnemy_WeaponComponent::SetShieldSpellDeflectionIfEquipped(bool bShouldDeflect) {
}

void UEnemy_WeaponComponent::SetShield(AEnemyAIWeapon* InShieldPtr) {
}

void UEnemy_WeaponComponent::SetRecoverWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::SetRecoverSecondaryWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::RespawnWeapon() {
}

void UEnemy_WeaponComponent::RemoveStoredWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::ReleaseWeaponType(AEnemyAIWeapon* InWeaponPtr, EEnemy_WeaponReleaseType InReleaseType) {
}

void UEnemy_WeaponComponent::ReleaseWeapon(AEnemyAIWeapon* InWeaponPtr, bool bForceDestroy, bool bSetDropVel, bool bIsThrown, bool bForceDrop) {
}

void UEnemy_WeaponComponent::ReleaseShield(AEnemyAIWeapon* InShieldPtr, bool bSetDropVel) {
}

bool UEnemy_WeaponComponent::IsWeaponStored(AEnemyAIWeapon* InWeaponPtr) const {
    return false;
}

bool UEnemy_WeaponComponent::IsRequiredWeaponStored(const UEnemyAIAttackData* AttackPtr) const {
    return false;
}

bool UEnemy_WeaponComponent::IsRequiredWeaponActive(const UEnemyAIAttackData* AttackPtr) const {
    return false;
}

void UEnemy_WeaponComponent::HideActiveWeapon(bool bHide) {
}

bool UEnemy_WeaponComponent::HasWeaponToRecover() const {
    return false;
}

bool UEnemy_WeaponComponent::HasWeaponToAcquire() const {
    return false;
}

bool UEnemy_WeaponComponent::HasWeapon() const {
    return false;
}

bool UEnemy_WeaponComponent::HasStoredWeapon() const {
    return false;
}

bool UEnemy_WeaponComponent::HasShield() const {
    return false;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetWeaponToRecover() {
    return NULL;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetWeaponToAcquire() {
    return NULL;
}

float UEnemy_WeaponComponent::GetWeaponRequiredPercent() const {
    return 0.0f;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetWeapon() const {
    return NULL;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetTransientWeapon() const {
    return NULL;
}

TSubclassOf<AEnemyAIWeapon> UEnemy_WeaponComponent::GetStoreWeaponClass() const {
    return NULL;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetStoredWeapon(const TArray<TSubclassOf<AEnemyAIWeapon>>& WeaponClassList, bool bGetFirstMatch) const {
    return NULL;
}

TSubclassOf<AEnemyAIWeapon> UEnemy_WeaponComponent::GetSpawnWeaponClass() const {
    return NULL;
}

TSubclassOf<AEnemyAIWeapon> UEnemy_WeaponComponent::GetShieldWeaponClass() const {
    return NULL;
}

TSubclassOf<AEnemyAIWeapon> UEnemy_WeaponComponent::GetRespawnWeaponClass() const {
    return NULL;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetRecoverWeapon() const {
    return NULL;
}

AEnemyAIWeapon* UEnemy_WeaponComponent::GetRecoverSecondaryWeapon() const {
    return NULL;
}

FGameplayTagContainer UEnemy_WeaponComponent::GetEnemyWeaponTagContainer() const {
    return FGameplayTagContainer{};
}

UInteractionArchitectAsset* UEnemy_WeaponComponent::GetEnemyWeaponDataAsset() const {
    return NULL;
}

void UEnemy_WeaponComponent::FireWeaponAOE1(AEnemyAIWeapon* InWeaponPtr) {
}

bool UEnemy_WeaponComponent::FindAvailableStoredWeaponSocket(AEnemyAIWeapon* InWeaponPtr, FName& OutSocketName, FVector& OutSocketTranslationOffset, FRotator& OutSocketRotationOffset) const {
    return false;
}

void UEnemy_WeaponComponent::EnableWeaponCollision() {
}

void UEnemy_WeaponComponent::EnableShieldCollision() {
}

void UEnemy_WeaponComponent::EnableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr) {
}

AActor* UEnemy_WeaponComponent::DisarmWeaponToRecover(float ScaleForce) {
    return NULL;
}

AActor* UEnemy_WeaponComponent::DisarmWeapon(float ScaleForce) {
    return NULL;
}

AActor* UEnemy_WeaponComponent::DisarmShield(float ScaleForce) {
    return NULL;
}

void UEnemy_WeaponComponent::DisableWeaponCollision() {
}

void UEnemy_WeaponComponent::DisableShieldCollision() {
}

void UEnemy_WeaponComponent::DisableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::DeathSpawnWeapon() {
}

bool UEnemy_WeaponComponent::CanStoreWeapon(AEnemyAIWeapon* InWeaponPtr) const {
    return false;
}

bool UEnemy_WeaponComponent::CanPerceiveThisWeapon(AEnemyAIWeapon* InWeaponPtr) const {
    return false;
}

bool UEnemy_WeaponComponent::CanAnyStoredWeaponBeThrown() const {
    return false;
}

void UEnemy_WeaponComponent::AllWeaponsLifetimeToZero() const {
}

void UEnemy_WeaponComponent::ActivateRequiredWeapon() {
}

void UEnemy_WeaponComponent::AcquireWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemy_WeaponComponent::AcquireShield(AEnemyAIWeapon* InShieldPtr) {
}

UEnemy_WeaponComponent::UEnemy_WeaponComponent() {
    this->bCanStoreActiveWeapon = true;
    this->WeaponSocketTable = NULL;
    this->bSpawnEnable = true;
    this->DeathSpawnMax = 6;
    this->DeathSpawnMin = 4;
    this->DisarmSpawnMin = 2;
    this->DisarmSpawnMax = 4;
    this->bVulnerableWhileDisarmed = false;
    this->AttackComp = NULL;
    this->NPCComp = NULL;
    this->EnemyComp = NULL;
}

