#include "SpellTool.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACharacter;
class AMunitionType_Base;
class AWandTool;
class UAblReactionComponent;
class UAblReactionData;
class UActorComponent;
class USceneComponent;
class USpellToolRecord;

void ASpellTool::TriggerReleased(bool bForce, bool bFromStop) {
}

void ASpellTool::StopActive() {
}

void ASpellTool::StartChannelingAction() {
}

bool ASpellTool::Start() {
    return false;
}

void ASpellTool::SpellFlourish() {
}

void ASpellTool::SetIgnoreActors(TArray<AActor*> i_Ignores) {
}

void ASpellTool::SetDestinationActor(AActor* InActor) {
}

void ASpellTool::SetAffectImmuneToSpells(bool bAffectImmune) {
}

void ASpellTool::ReassignBeamTarget(const AActor* CurrentActor, USceneComponent* NewComponent) {
}

void ASpellTool::ReactionStart(UAblReactionData* InReactionData, UAblReactionComponent* ReactionComponent) {
}

void ASpellTool::ReactionEnd(UAblReactionData* InReactionData, UAblReactionComponent* ReactionComponent) {
}

void ASpellTool::PreSpawnMunition() {
}

void ASpellTool::Prep() {
}

void ASpellTool::PlayHitActorFX(const FHitResult& HitResult) {
}

void ASpellTool::OwnerHasStartedCasting(FName WandCastName) {
}





void ASpellTool::OnMunitionOverlap(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData) {
}

void ASpellTool::OnMunitionImpactDamage(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData) {
}

void ASpellTool::OnMunitionImpact(AMunitionType_Base* MunitionInstance, const FMunitionImpactData& MunitionImpactData) {
}


void ASpellTool::OnMunitionDestroyed(AMunitionType_Base* InMunitionInstance) {
}





bool ASpellTool::IsToolUsedByPlayer() const {
    return false;
}

bool ASpellTool::IsStopped() const {
    return false;
}

bool ASpellTool::IsStarted_K2() const {
    return false;
}

bool ASpellTool::IsChanneling() const {
    return false;
}

bool ASpellTool::IsBeastCaptureSpell() const {
    return false;
}

bool ASpellTool::HasUpgradedMechanics() const {
    return false;
}

bool ASpellTool::HasUpgrade(ESpellUpgrades Upgrade) const {
    return false;
}

AWandTool* ASpellTool::GetWand() const {
    return NULL;
}

FName ASpellTool::GetSpellType() const {
    return NAME_None;
}

USpellToolRecord* ASpellTool::GetSpellToolRecord() const {
    return NULL;
}

ESpellCategory ASpellTool::GetSpellCategory() const {
    return ESpellCategory::None;
}

AActor* ASpellTool::GetSourceActor() const {
    return NULL;
}

float ASpellTool::GetProjectileSpeed() const {
    return 0.0f;
}

FVector ASpellTool::GetMuzzleLocation() const {
    return FVector{};
}

TSubclassOf<AMunitionType_Base> ASpellTool::GetMunitionActor() const {
    return NULL;
}

float ASpellTool::GetMaxRange() const {
    return 0.0f;
}

EImpactTypes ASpellTool::GetImpactType() const {
    return EImpactTypes::None;
}

UClass* ASpellTool::GetExecutionClassFromKeyWord(FName KeyWord) {
    return NULL;
}

float ASpellTool::GetDuration(bool bTargetIsACharacter) const {
    return 0.0f;
}

AActor* ASpellTool::GetCharacterActor() const {
    return NULL;
}

ACharacter* ASpellTool::GetCharacter() const {
    return NULL;
}

AActor* ASpellTool::GetActiveTarget() const {
    return NULL;
}

AMunitionType_Base* ASpellTool::GetActiveMunition() const {
    return NULL;
}

void ASpellTool::ForceStop() {
}

void ASpellTool::FireOnHitBySpell(AActor* InTargetActor, AActor* InInstigator, const FGameplayTagContainer& InMunitionTagContainer, const FHitResult& HitResult, const FVector& ImpactDirection) {
}

void ASpellTool::Failed_K2() {
}

void ASpellTool::EndToggleSpell(bool bForcedExternally) {
}

UActorComponent* ASpellTool::CreateImpactComponent(AActor* InTargetActor, const FMunitionImpactData& InMunitionImpactData) {
    return NULL;
}

float ASpellTool::CalculateCharacterDamage(AActor* InTarget, bool& OutWillKillTarget) {
    return 0.0f;
}

bool ASpellTool::BreaksShield(const AActor* Target, const FGameplayTagContainer& InTagContainer) {
    return false;
}

void ASpellTool::Abort() {
}

ASpellTool::ASpellTool() {
    this->bHeavyCast = true;
    this->LeftArmState = ELeftArmState::PlayHandOnlyMotion;
    this->RightArmState = ERightArmState::StopMotionOnly;
    this->PrepMuzzleMotionFX = NULL;
    this->bKillPrepFXWhenMuzzleFXStart = true;
    this->MuzzleMotionFX = NULL;
    this->EndMuzzleMotionFX = NULL;
    this->ProjectileFiredFX2EndsWithMunition = true;
    this->ProjectileMotionFX = NULL;
    this->ProjectileSfx = NULL;
    this->PlaceDecal = false;
    this->DecalMaterial = NULL;
    this->DecalFadeInDelay = 0.00f;
    this->DecalFadeInTime = 0.00f;
    this->DecalLifeSpan = 10.00f;
    this->DecalFadeTime = 2.00f;
    this->DecalRandomOrientation = true;
    this->Decal3D = NULL;
    this->Decal3DRandomOrientation = true;
    this->DestroyedPieceFXRadius = 0.00f;
    this->GameEventLocation = EGameEventLocation::None;
    this->GameEventIntensity = EGameEvent_Intensity::None;
    this->GameEventDuration = 0.00f;
    this->GameEventRange = -1.00f;
    this->GameEventFalloff = 0.00f;
    this->MunitionDataAsset = NULL;
    this->AttackState = EAttackState::AttackCombo1;
    this->SpellImpactComponent = NULL;
    this->bEnableCCDOnTarget = false;
    this->PreSpawnMunitionDelay = -1.00f;
    this->bActivateAllPerks = false;
    this->bAoe = false;
    this->bAOEAtTargetLocation = false;
    this->bAffectTeammates = true;
    this->bOnlyAffectsMovable = false;
    this->bCanAffectBroken = true;
    this->bCanAffectPlayer = true;
    this->bSetWandCastTargetTrackers = true;
    this->SpawnAllDeflectMunitionActors = false;
    this->bPlayersUseImprovedTargeting = false;
    this->SpellActiveTriggerEffect = NULL;
    this->PrepLEDEffect = NULL;
    this->StartLEDEffect = NULL;
    this->EndLEDEffect = NULL;
    this->OverrideSourceActor = NULL;
    this->OverrideTargetActor = NULL;
    this->OverrideTargetComponent = NULL;
    this->OverrideCharacter = NULL;
    this->LevelDataAsset = NULL;
    this->ImpactComponent = NULL;
    this->pSpellActiveTriggerEffect = NULL;
    this->bAffectsRightTrigger = true;
    this->bAffectsLeftTrigger = false;
    this->pPrepLEDEffect = NULL;
    this->pStartLEDEffect = NULL;
    this->pEndLEDEffect = NULL;
    this->ProjectileAkComponent = NULL;
}

