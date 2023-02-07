#include "Enemy_Character.h"
#include "CognitionStimuliSourceComponent.h"
#include "ToolSetComponent.h"
#include "EnemyStateComponent.h"
#include "Enemy_AttackComponent.h"
#include "Enemy_WeaponComponent.h"

class AActor;


void AEnemy_Character::UnhideAndEnableEnemyCharacter(AActor* EnemyCharacter) {
}

void AEnemy_Character::Throw(AActor* Target, AActor* SourceActor) {
}

bool AEnemy_Character::StartFire_Implementation(float Amount, FVector Location) {
    return false;
}

void AEnemy_Character::SetAsLeader(bool bSet) {
}

void AEnemy_Character::SetAsGroupAggressor(bool bSet, FName InNewTeamName) {
}

void AEnemy_Character::SetAsFightClubOpponent(bool bSet, FName InNewTeamName, FName InAudioSubtypeID) {
}

void AEnemy_Character::SetAsDuelOpponent(bool bSet, FName InAudioSubtypeID) {
}

void AEnemy_Character::SetAsCompanion(bool bSet) {
}

void AEnemy_Character::SetAsAggressor(bool bSet, FName InNewTeamName) {
}

void AEnemy_Character::OnTakeAKneeTimedOut() {
}

void AEnemy_Character::OnFireExtinguished_Implementation() {
}

void AEnemy_Character::OnCompletelyCharred_Implementation() {
}

void AEnemy_Character::MunitionCreated_Implementation() {
}

void AEnemy_Character::Landed(const FHitResult& Hit) {
}

bool AEnemy_Character::IsLeader() const {
    return false;
}

bool AEnemy_Character::IsDuelOpponent() const {
    return false;
}

bool AEnemy_Character::IsCompanion() const {
    return false;
}

bool AEnemy_Character::IsCombatOpponent() const {
    return false;
}

bool AEnemy_Character::IsAggressor() const {
    return false;
}

void AEnemy_Character::HideAndDisableEnemyCharacter(AActor* EnemyCharacter) {
}

void AEnemy_Character::HandleNearDeathKneelStart(AActor* ActorKneeling) {
}

void AEnemy_Character::HandleNearDeathKneelEnd() {
}

void AEnemy_Character::HandleMeleeHit(AActor* Victim, const FVector& NormalImpulse, const FHitResult& Hit) {
}

void AEnemy_Character::HandleHealthThresholdReached(FHealthThreshold InHealthThreshold, int32 InLevel, int32 InMaxLevel) {
}

void AEnemy_Character::ExitSpline() {
}

bool AEnemy_Character::ChangeTeamWithCombat(const FName TeamName, const bool bEnableCombat) {
    return false;
}

void AEnemy_Character::AttackWindowStop_Implementation() {
}

void AEnemy_Character::AttackWindowStart_Implementation() {
}

AEnemy_Character::AEnemy_Character() {
    this->bRegisterPerceptionAfterSpawn = true;
    this->Level = 1;
    this->FinisherHealthPercentage = 0.30f;
    this->PlayerStupifyHits = 0;
    this->ToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("ToolSetComponent"));
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSourceComponent"));
    this->EnemyAIComponent = NULL;
    this->EnemyStateComponent = CreateDefaultSubobject<UEnemyStateComponent>(TEXT("EnemyState"));
    this->BehaviorCompAttackUpdate = NULL;
    this->AttackComponent = CreateDefaultSubobject<UEnemy_AttackComponent>(TEXT("AttackComponent"));
    this->WeaponComponent = CreateDefaultSubobject<UEnemy_WeaponComponent>(TEXT("WeaponComponent"));
    this->VfxObjectArchitectAsset = NULL;
    this->SpawningDOV = NULL;
}

