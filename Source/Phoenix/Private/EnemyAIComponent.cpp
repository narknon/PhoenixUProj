#include "EnemyAIComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AEnemyAIWeapon;
class ANPC_Character;
class APathNode;
class ASpellCasterTool;
class ASpellTool;
class UAblReactionComponent;
class UAblReactionData;
class UCurveFloat;
class UEnemyAIAttackData;
class UEnemyAISpawnData;
class UEnemy_AnimInstance;
class UEnemy_InstanceQBUpdateData;
class UEnemy_QBUpdateData;
class UInteractionArchitectAsset;
class USpellToolRecord;

bool UEnemyAIComponent::WasAttackParried(AActor* InVictimPtr) const {
    return false;
}

bool UEnemyAIComponent::WaitForCreatureStance(ECreatureStance InWaitForStance, bool bWaitForStationary, float DeltaTime) {
    return false;
}

bool UEnemyAIComponent::WaitForAbility(EEnemy_Ability InWaitForState, float DeltaTime) {
    return false;
}

void UEnemyAIComponent::UpdateHealthRTPCCallback(AActor* InActor, float Delta, bool bIndicateHUD) {
}

bool UEnemyAIComponent::UpdateFollowSpline(float DeltaTime) {
    return false;
}

void UEnemyAIComponent::UpdateFacingToLoc(FVector Loc, UCurveFloat* CurvePtr, float InterpSpeed, float DeltaTime) {
}

void UEnemyAIComponent::UpdateAttackLocation() {
}

void UEnemyAIComponent::UnhideActiveWeapon() {
}

void UEnemyAIComponent::TrackMeleePoints(const FVector& InMeleeLoc) {
}

void UEnemyAIComponent::ThrowWeapon() {
}

void UEnemyAIComponent::TeamChanged() {
}

bool UEnemyAIComponent::StoreWeapon(AEnemyAIWeapon* InWeaponPtr) {
    return false;
}

void UEnemyAIComponent::StopWandLinkCowerDelayed() {
}

void UEnemyAIComponent::StopProtegoSpell() {
}

void UEnemyAIComponent::StopGameChanger() {
}

void UEnemyAIComponent::StopCastSpell(USpellToolRecord* SpellToolRecord) {
}

void UEnemyAIComponent::StartProtegoSpell() {
}

void UEnemyAIComponent::StartGameChanger() {
}

void UEnemyAIComponent::StartFollowSpline() {
}

bool UEnemyAIComponent::StartAttack() {
    return false;
}

void UEnemyAIComponent::StartApparateInEvent() {
}

void UEnemyAIComponent::SplineSpawnDoneEvent(AActor* InApparateActor) {
}

void UEnemyAIComponent::SplineSpawnArrivedEvent(AActor* InApparateActor, FVector InLoc) {
}

AEnemyAIWeapon* UEnemyAIComponent::SpawnWeapon(TSubclassOf<AEnemyAIWeapon> SpawnWeaponClass) {
    return NULL;
}

void UEnemyAIComponent::SpawnLoot() {
}

AActor* UEnemyAIComponent::SpawnChild_BP(const FString& ObjectToSpawn, ENPC_Spawn InSpawnType, const FString& TeamName, FTransform SpawnTransform) {
    return NULL;
}

void UEnemyAIComponent::SpawnAnimagusForm() {
}

void UEnemyAIComponent::SetWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemyAIComponent::SetWanderMode() {
}

void UEnemyAIComponent::SetUnblockableTags(FGameplayTagContainer& InOutTagContainer, UEnemyAIAttackData* attackDataPtr, bool bForceUnblockable) {
}

void UEnemyAIComponent::SetToDie(AActor* InstigatorPtr, UInteractionArchitectAsset* InMunitionDataAssetPtr) {
}

void UEnemyAIComponent::SetTASEnabled(bool inEnabled) {
}

void UEnemyAIComponent::SetStationaryMode() {
}

void UEnemyAIComponent::SetSpellCaster(ASpellCasterTool* InSpellCaster) {
}

void UEnemyAIComponent::SetShowShieldWhenHit(bool bShowWhenHit) {
}

void UEnemyAIComponent::SetShowOnOffShieldEffects(bool bShowShieldEffects) {
}

void UEnemyAIComponent::SetShieldToAcquire(AEnemyAIWeapon* InShieldPtr) {
}

void UEnemyAIComponent::SetShieldSpellDeflectionIfEquipped(bool bShouldDeflect) {
}

void UEnemyAIComponent::SetShield(AEnemyAIWeapon* InShieldPtr) {
}

void UEnemyAIComponent::SetScaredMode() {
}

void UEnemyAIComponent::SetResurrectedEvent() {
}

void UEnemyAIComponent::SetPlayProtegoDeflection(bool bPlay) {
}

void UEnemyAIComponent::SetPathMode(APathNode* pPathNode) {
}

void UEnemyAIComponent::SetParentToActors(const TArray<AActor*>& InActorList, AActor* InParent) {
}

void UEnemyAIComponent::SetNoAttackSelectCooldown(bool bNo) {
}

void UEnemyAIComponent::SetNoAttackExecuteCooldown(bool bNo) {
}

void UEnemyAIComponent::SetNewAlertUIData(FNPC_ShowUI NewShowUI) {
}

void UEnemyAIComponent::SetInAttackWindow(bool bin) {
}

void UEnemyAIComponent::SetIgnoreAttackCorridors(bool bIgnore) {
}

void UEnemyAIComponent::SetGameChangerState(NPC_GameChangerState InState) {
}

void UEnemyAIComponent::SetGameChangerObjectName(const FString& inObjectName) {
}

void UEnemyAIComponent::SetGameChangerForm(ANPC_Character* inGameChangerForm) {
}

void UEnemyAIComponent::SetForceIntoAttackTAS(bool bForce) {
}

void UEnemyAIComponent::SetDestroyed() {
}

void UEnemyAIComponent::SetDeadMode() {
}

void UEnemyAIComponent::SetDeadEvent(AActor* Instigator) {
}

void UEnemyAIComponent::SetDamagedEvent(float InAmount, AActor* Instigator) {
}

void UEnemyAIComponent::SetCustomAttackData(UEnemyAIAttackData* InCustAttackPtr, AActor* InCustTarget) {
}

void UEnemyAIComponent::SetCantMoveDuringAttack(bool disableMove) {
}

void UEnemyAIComponent::SetCanAttack(bool canAttack) {
}

void UEnemyAIComponent::SetAttackWithoutRestrictions(bool bInWithoutRestrictions) {
}

void UEnemyAIComponent::SetAttackMode(AActor* pTarget) {
}

void UEnemyAIComponent::SetAttackLocation(FVector InLocation) {
}

void UEnemyAIComponent::SetAttackingState(EEnemy_AttackingState InState) {
}

void UEnemyAIComponent::SetAttackExitAsSoonAsFired(bool bExit) {
}

void UEnemyAIComponent::SetAttackCollisionType(AttackCollisionType InCollisionType) {
}

void UEnemyAIComponent::SetAnimagusWolfPerceivedTarget() {
}

void UEnemyAIComponent::SetAlwaysMyTurn(bool bInAlwaysMyTurn) {
}

void UEnemyAIComponent::SetAlwaysInRange(bool bAlways) {
}

void UEnemyAIComponent::SetAlwaysAccurate(bool bAlways) {
}

void UEnemyAIComponent::SetAllowProtegoToInterruptAttack(bool bAllowProtegoInterrupt) {
}

void UEnemyAIComponent::SetAlertMode(AActor* pTarget) {
}

float UEnemyAIComponent::SendMunitionImpact(const FHitResult& HitResult, AActor* pVictim, AActor* pOriginator, UInteractionArchitectAsset* pMunitionDataAsset, FName InMunitionImpactType, const FGameplayTagContainer& InMunitionTagContainer, bool bForceUnblockable) {
    return 0.0f;
}

void UEnemyAIComponent::RotateToLoc(FVector Loc) {
}

void UEnemyAIComponent::RotateToAttack() {
}

void UEnemyAIComponent::RespawnWeapon() {
}

void UEnemyAIComponent::ResetDisengagedState() {
}

void UEnemyAIComponent::ResetAttack(EEnemy_AttackResetSource InResetSource) {
}

void UEnemyAIComponent::ReleaseWeapon(AEnemyAIWeapon* InWeaponPtr, bool bForceDestroy, bool bSetDropVel, bool bIsThrown, bool bForceDrop) {
}

void UEnemyAIComponent::ReleaseSpellCaster(ASpellCasterTool* InSpellCasterPtr) {
}

void UEnemyAIComponent::ReleaseShield(AEnemyAIWeapon* InShieldPtr, bool bSetDropVel) {
}

void UEnemyAIComponent::ReactionStart(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent) {
}

void UEnemyAIComponent::PublishAttackStateToBlackboard() {
}

void UEnemyAIComponent::PreparePotentialSpawnLocations() {
}

void UEnemyAIComponent::PreloadAnimagusForm(TSoftClassPtr<AActor> AnimalForm) {
}

bool UEnemyAIComponent::PreAttack(EEnemy_AttackSource InSource) {
    return false;
}

void UEnemyAIComponent::PathNodeArrival() {
}

bool UEnemyAIComponent::OverlapMeleeCapsule(AActor* InVictim, FHitResult InHitResult, ENPC_HitDirection InForceDirection, FEnemy_MeleeAttackOverlapData& OutOverlapData) {
    return false;
}

void UEnemyAIComponent::OnReplicatedFormDeath() {
}

void UEnemyAIComponent::OnObjectLoaded(const FString& ObjectToLoad) {
}

void UEnemyAIComponent::OnJumpSplineDone() {
}

void UEnemyAIComponent::OnAttackDBLoaded(AActor* LoadActor, TEnumAsByte<EActor_LoadDBProcessingType> LoadType) {
}

void UEnemyAIComponent::OnAnimagusFormTransformed() {
}

void UEnemyAIComponent::OnAnimagusFormTimeout() {
}

void UEnemyAIComponent::OnAnimagusFormDeath() {
}

void UEnemyAIComponent::OnAnimagusFormAvadaKedavra() {
}

void UEnemyAIComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void UEnemyAIComponent::OnActorDamaged(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit) {
}

bool UEnemyAIComponent::MoveToAttackRunTo(float DeltaTime) {
    return false;
}

bool UEnemyAIComponent::MoveToAttackLocation(FVector DestinationLoc, UCurveFloat* CurveFloatPtr, float InterpSpeed, float DeltaTime) {
    return false;
}

void UEnemyAIComponent::LogBehaviorTree(FName TaskName) {
}

bool UEnemyAIComponent::IsUsingNavLink() const {
    return false;
}

bool UEnemyAIComponent::IsRequiredWeaponStored(const UEnemyAIAttackData* AttackPtr) const {
    return false;
}

bool UEnemyAIComponent::IsFacingToLoc(FVector Loc, float MinAngle) const {
    return false;
}

bool UEnemyAIComponent::IsCharacterDisengaged() {
    return false;
}

bool UEnemyAIComponent::IsAttacking() const {
    return false;
}

bool UEnemyAIComponent::InRangeToLoc(FVector TestLoc, FVector Loc, float MinRange, float MaxRange, float Tolerance, bool bAllowIfTooClose, float& OutDistFromRange) const {
    return false;
}

void UEnemyAIComponent::InitWaitForCreatureStance(ECreatureStance InWaitForStance, bool bWaitForStationary, float Timeout) {
}

void UEnemyAIComponent::InitWaitForAbility(float Timeout) {
}

bool UEnemyAIComponent::InitMoveToAttackRunTo(float Timeout) {
    return false;
}

bool UEnemyAIComponent::InitMoveToAttackLocation(FVector DestinationLoc, float Timeout) {
    return false;
}

void UEnemyAIComponent::InitFollowSpline() {
}

void UEnemyAIComponent::HideProtegoSpell(bool bInHide) {
}

void UEnemyAIComponent::HideActiveWeapon() {
}

bool UEnemyAIComponent::HasWeapon() const {
    return false;
}

bool UEnemyAIComponent::HasStoredWeapon() const {
    return false;
}

void UEnemyAIComponent::HandleSpellSuccess(AActor* Target, const ASpellTool* Spell, FName SpellType) {
}

bool UEnemyAIComponent::HandleOnActorHit(AActor* pOtherActor, const FHitResult& HitResult) {
    return false;
}

void UEnemyAIComponent::HandleOnActorEndHit(AActor* pOtherActor) {
}

void UEnemyAIComponent::HandleAttackDone() {
}

void UEnemyAIComponent::HandleAbilityAnimEvent(EEnemy_AbilityEvent inAnimEvent) {
}

bool UEnemyAIComponent::HandleAbilityActorHit(AActor* InOtherActor, const FHitResult& HitResult) {
    return false;
}

AEnemyAIWeapon* UEnemyAIComponent::GetWeaponToAcquire() {
    return NULL;
}

float UEnemyAIComponent::GetWeaponRequiredPercent() const {
    return 0.0f;
}

AEnemyAIWeapon* UEnemyAIComponent::GetWeapon() const {
    return NULL;
}

bool UEnemyAIComponent::GetUnblockable(AActor* InVictimPtr, bool bForceUnblockable) const {
    return false;
}

AEnemyAIWeapon* UEnemyAIComponent::GetTransientWeapon() const {
    return NULL;
}

ASpellCasterTool* UEnemyAIComponent::GetSpellCaster() const {
    return NULL;
}

FVector UEnemyAIComponent::GetSpawnLoc() const {
    return FVector{};
}

UEnemyAISpawnData* UEnemyAIComponent::GetSpawnData() const {
    return NULL;
}

FString UEnemyAIComponent::GetSizeCategoryString() const {
    return TEXT("");
}

EEEnemyAISizeCategory UEnemyAIComponent::GetSizeCategory() const {
    return EEEnemyAISizeCategory::None;
}

UEnemy_QBUpdateData* UEnemyAIComponent::GetQBUpdateData(EEnemy_AttackLocSource InSource) {
    return NULL;
}

EEnemy_ProtegoLevel UEnemyAIComponent::GetProtegoSpellLevel() {
    return EEnemy_ProtegoLevel::None;
}

APathNode* UEnemyAIComponent::GetPathNode() const {
    return NULL;
}

UEnemy_InstanceQBUpdateData* UEnemyAIComponent::GetOrCreateQBUpdateInstanceData(ENPC_QBUpdate InUpdate) {
    return NULL;
}

FNPC_PerceptionInfo UEnemyAIComponent::GetNPCPerceptionInfo() const {
    return FNPC_PerceptionInfo{};
}

bool UEnemyAIComponent::GetMoveToAttackRunToSuccess() const {
    return false;
}

FVector UEnemyAIComponent::GetLastKnownTargetLoc() const {
    return FVector{};
}

bool UEnemyAIComponent::GetIsStealthAttackCurrentlyDisabled() const {
    return false;
}

bool UEnemyAIComponent::GetInAttackWindow() const {
    return false;
}

NPC_GameChangerState UEnemyAIComponent::GetGameChangerState() const {
    return NPC_GameChangerState::GameChanger_None;
}

FString UEnemyAIComponent::GetGameChangerObjectName() {
    return TEXT("");
}

ANPC_Character* UEnemyAIComponent::GetGameChangerForm() {
    return NULL;
}

FGameplayTagContainer UEnemyAIComponent::GetEnemyWeaponTagContainer() const {
    return FGameplayTagContainer{};
}

UInteractionArchitectAsset* UEnemyAIComponent::GetEnemyWeaponDataAsset() const {
    return NULL;
}

UEnemy_AnimInstance* UEnemyAIComponent::GetEnemyAnimInstance() {
    return NULL;
}

float UEnemyAIComponent::GetDamage(AActor* InVictimPtr, AEnemyAIWeapon* InWeaponPtr) const {
    return 0.0f;
}

float UEnemyAIComponent::GetCriticalHealthPercept() const {
    return 0.0f;
}

bool UEnemyAIComponent::GetCanAttack() const {
    return false;
}

bool UEnemyAIComponent::GetAttackWaitingForDesynchronization() {
    return false;
}

bool UEnemyAIComponent::GetAttackUpdateStateSuccess() const {
    return false;
}

EEnemy_AttackUpdateState UEnemyAIComponent::GetAttackUpdateState() const {
    return EEnemy_AttackUpdateState::None;
}

EEnemyAIAttackState UEnemyAIComponent::GetAttackStateRange() {
    return EEnemyAIAttackState::None;
}

EEnemyAIAttackState UEnemyAIComponent::GetAttackState() const {
    return EEnemyAIAttackState::None;
}

FVector UEnemyAIComponent::GetAttackLocation() const {
    return FVector{};
}

AttackCollisionType UEnemyAIComponent::GetAttackCollisionType() const {
    return AttackCollisionType::LeftHandWeapon;
}

float UEnemyAIComponent::GetAlertSense() {
    return 0.0f;
}

FEnemy_AlertData UEnemyAIComponent::GetAlert() const {
    return FEnemy_AlertData{};
}

AEnemyAIWeapon* UEnemyAIComponent::GetActiveSpawnMeteorData() {
    return NULL;
}

void UEnemyAIComponent::ForceQBDataForceUpdate() {
}

void UEnemyAIComponent::ForceNextAttack(UEnemyAIAttackData* InAttackPtr) {
}

void UEnemyAIComponent::ForceExecuteDelayedAttack(UEnemyAIAttackData* InAttackPtr, float InDelay) {
}

void UEnemyAIComponent::ForceExecuteAttack(UEnemyAIAttackData* InAttackPtr) {
}

void UEnemyAIComponent::ForceDisengagedState() {
}

void UEnemyAIComponent::ForceChooseAttack(UEnemyAIAttackData* InAttackPtr) {
}

void UEnemyAIComponent::ForceAttackState() {
}

void UEnemyAIComponent::ForceAttack(UEnemyAIAttackData* InAttackPtr, bool bBypassPerception) {
}

void UEnemyAIComponent::FireWeaponAOE1(AEnemyAIWeapon* InWeaponPtr) {
}

bool UEnemyAIComponent::FindAvailableStoredWeaponSocket(AEnemyAIWeapon* InWeaponPtr, FName& OutSocketName) const {
    return false;
}

void UEnemyAIComponent::EnemyRemoveFromManager(AActor* InActorPtr) {
}

void UEnemyAIComponent::EnemyAddToManager(AActor* InActorPtr) {
}

void UEnemyAIComponent::EndAttack() {
}

void UEnemyAIComponent::EnableWeaponCollision() {
}

void UEnemyAIComponent::EnableTrackMeleePoints(bool bEnable) {
}

void UEnemyAIComponent::EnableShieldCollision() {
}

void UEnemyAIComponent::EnableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemyAIComponent::EnableImmediateAttack(bool ShouldEnable) {
}

AActor* UEnemyAIComponent::DisarmWeapon(float ScaleForce) {
    return NULL;
}

AActor* UEnemyAIComponent::DisarmShield(float ScaleForce) {
    return NULL;
}

void UEnemyAIComponent::DisableWeaponCollision() {
}

void UEnemyAIComponent::DisableShieldCollision() {
}

void UEnemyAIComponent::DisableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemyAIComponent::DestroySpawnedChildren() {
}

void UEnemyAIComponent::DestroyAnimagusForm() {
}

void UEnemyAIComponent::ComboEnd(int32 ComboCount) {
}

bool UEnemyAIComponent::ChooseCounterAttackSplit(const FGameplayTagContainer& InTagContainer) {
    return false;
}

bool UEnemyAIComponent::ChooseAttackUpdate() {
    return false;
}

UEnemyAIAttackData* UEnemyAIComponent::ChooseAttack() {
    return NULL;
}

void UEnemyAIComponent::CastSpellAtRandom(USpellToolRecord* SpellToolRecord, FName InSocketName) {
}

void UEnemyAIComponent::CastSpellAtLocation(const FVector& TargetLocation, USpellToolRecord* SpellToolRecord, const FName& InSocketName) {
}

void UEnemyAIComponent::CastSpellAtActor(AActor* InTargetPtr, USpellToolRecord* SpellToolRecord, FName InSocketName, const bool bAlwaysHitTargetActor) {
}

void UEnemyAIComponent::CastSpell(USpellToolRecord* SpellToolRecord, FName InSocketName) {
}

void UEnemyAIComponent::CastProtegoSpell(USpellToolRecord* SpellToolRecord, FName InSocketName) {
}

bool UEnemyAIComponent::CanStoreWeapon(AEnemyAIWeapon* InWeaponPtr) const {
    return false;
}

bool UEnemyAIComponent::CanAnyStoredWeaponBeThrown() const {
    return false;
}

void UEnemyAIComponent::BroadcastOnDeath(AActor* pActor) {
}

void UEnemyAIComponent::BroadcastOnAlertSenseChanged(float alertSense) {
}

void UEnemyAIComponent::BroadcastAlertState() {
}

void UEnemyAIComponent::BroadcastAlertSense() {
}

bool UEnemyAIComponent::AttackUpdateStateUpdate(EEnemy_AttackUpdateState AttackUpdateState, float DeltaTime) {
    return false;
}

void UEnemyAIComponent::AttackTreeUpdate() {
}

void UEnemyAIComponent::AttackExecuteBTInject() {
}

void UEnemyAIComponent::AttackedEvent(AActor* Instigator) {
}

void UEnemyAIComponent::AttackChooseBTInject() {
}

void UEnemyAIComponent::ApplyDesynchronization() {
}

void UEnemyAIComponent::ApparateDoneEvent(AActor* InApparateActor) {
}

void UEnemyAIComponent::ApparateArrivedEvent(AActor* InApparateActor, FVector InLoc) {
}

void UEnemyAIComponent::AllWeaponsLifetimeToZero() const {
}

void UEnemyAIComponent::AllowSingleAttack() {
}

void UEnemyAIComponent::AllowHideBlindWeapon(bool bInAllow) {
}

bool UEnemyAIComponent::AdvancePath() {
    return false;
}

void UEnemyAIComponent::AdjustAttackWeightsByID(const FString& InRegistryID) {
}

void UEnemyAIComponent::AddQBUpdateData(EEnemy_AttackLocSource InSource) {
}

void UEnemyAIComponent::ActivateRequiredWeapon() {
}

void UEnemyAIComponent::AcquireWeapon(AEnemyAIWeapon* InWeaponPtr) {
}

void UEnemyAIComponent::AcquireSpellCaster(ASpellCasterTool* InSpellCasterPtr) {
}

void UEnemyAIComponent::AcquireShield(AEnemyAIWeapon* InShieldPtr) {
}

void UEnemyAIComponent::AbortAUS(bool bBranchToIdle) {
}

void UEnemyAIComponent::AbortAttack() {
}

UEnemyAIComponent::UEnemyAIComponent() {
    this->m_damageDestructables = true;
    this->MoveMaxAngle = 60.00f;
    this->MaxAngleFromCamera = 70.00f;
    this->TooCloseToTargetDist = 300.00f;
    this->bImmuneToCCIncapacition = false;
    this->ProximityAttackDist = 250.00f;
    this->ProximityMoveDist = 250.00f;
    this->ProximityAttackDistCooldown = 4.00f;
    this->ProximityAttackMinTimeSinceLastAttack = 4.00f;
    this->CounterAttackWindow = 1.00f;
    this->CounterAttackCooldown = 5.00f;
    this->bAttackDisable = false;
    this->bAttackWithoutRestrictions = false;
    this->bAlwaysMyTurn = false;
    this->bNoAttackExecuteCooldown = false;
    this->bNoAttackSelectCooldown = false;
    this->bAlwaysInRange = false;
    this->bAlwaysAccurate = false;
    this->bAllAttacksRequireTickets = false;
    this->bStationaryAttackAllowedOutOfRange = true;
    this->bAttackExitAsSoonAsFired = false;
    this->bIgnoreCorridors = false;
    this->AttackSplitBehaviorTree = NULL;
    this->AttackCounterBehaviorTree = NULL;
    this->RetaliatePauseTicketRecoverTime = 0.10f;
    this->TeammateLOSCorridorHalfWidth = 30.00f;
    this->TeammateLOSUpdateInterval = 0.10f;
    this->TeammateLOSRequireForNPCAttack = false;
    this->bAbruptDestinationChangeCheck = true;
    this->AbruptDestinationChangeAngle = 90.00f;
    this->CombatLocSearchAngleWidth = 10.00f;
    this->CombatFootprintSize = 250.00f;
    this->PathCheckPtr = NULL;
    this->SizeCategory = EEEnemyAISizeCategory::Medium;
    this->RotationRate = 50.00f;
    this->bEnableEnergyDrain = false;
    this->bEnableBreaks = false;
    this->BreakChance = 1.00f;
    this->BreakIntervalBetween = 12.00f;
    this->bEnableBreakIntervalDecay = true;
    this->BreakIntervalBetweenDeviation = 5.00f;
    this->BreakDuration = 3.00f;
    this->BreakDurationDeviation = 1.00f;
    this->BecomeAlertAbility = NULL;
    this->AlertFaceAbility = NULL;
    this->AlertWaitAbility = NULL;
    this->LoseAlertAbility = NULL;
    this->BecomeAwareAbility = NULL;
    this->LoseAwareAbility = NULL;
    this->TurnInPlaceAbility = NULL;
    this->IdleBreakAbility = NULL;
    this->ShuffleAbility = NULL;
    this->TauntAbility = NULL;
    this->ApparateOutAbility = NULL;
    this->ApparateWaitAbility = NULL;
    this->ApparateInAbility = NULL;
    this->WeaponEquipAbility = NULL;
    this->WeaponStoreAbility = NULL;
    this->WeaponPickupAbility = NULL;
    this->WeaponLostAbility = NULL;
    this->WeaponRecoveredAbility = NULL;
    this->JumpDownAbility = NULL;
    this->JumpStraightAbility = NULL;
    this->JumpSoftLandAbility = NULL;
    this->JumpLandPT = NULL;
    this->DeathTauntAbility = NULL;
    this->FlourishAbility = NULL;
    this->FlyingAbility = NULL;
    this->StartDrainedAbility = NULL;
    this->DrainedAbility = NULL;
    this->StopDrainedAbility = NULL;
    this->InvestigateStartAbility = NULL;
    this->InvestigateMoveAbility = NULL;
    this->InvestigateIdleAbility = NULL;
    this->InvestigateStopAbility = NULL;
    this->ReflectionIdleAbility = NULL;
    this->ForceTargetAwareState = ENPC_TargetAwareState::None;
    this->ForceTargetAwareStateTimer = -1.00f;
    this->bTASForceIntoAttack = false;
    this->bTASEnable = true;
    this->bPlayBecomeAware = false;
    this->PlayBecomeAwareChance = 1.00f;
    this->TeammatesPlayBecomeAwareChance = 0.25f;
    this->bPlayLoseAware = false;
    this->bSetDesiredDirectionInAlertFace = false;
    this->bAllowAwareTurnAround = true;
    this->bRequireStationaryForIdleChance = false;
    this->bUseCreatureMoveToStopPrediction = false;
    this->bUseCreatureMoveToStopBranching = false;
    this->bUpdateMobilityInBecomeOrLoseAware = false;
    this->MobilityForAlarmedInvestigate = ENPC_Mobility::Dynamic;
    this->ShuffleSupportedDirections = 0;
    this->ShuffleDistance = 200;
    this->bAllowShuffleWhenTooClose = false;
    this->bAllowShuffleWithoutWeapon = false;
    this->EvadeBeingTargetedThreshold = -1.00f;
    this->ChanceToEvade = 0;
    this->bFavorEvade = false;
    this->HealAmountPerEvent = 20.00f;
    this->ProtegoDefenseLevel = EEnemy_ProtegoLevel::None;
    this->ChanceToProtego = 0;
    this->ChanceToProtegoLightAttack = 0;
    this->ChanceToProtegoMediumAttack = 0;
    this->ChanceToProtegoHeavyAttack = 0;
    this->ProtegoDeflectedAttack = 0;
    this->BlockAttack = 0;
    this->DeflectBackAttack = 0;
    this->DeflectToTarget = 0;
    this->ProtegoDeflectionTimeOut = 3.00f;
    this->DeflectedAttackTimeOut = 3.00f;
    this->bPowerupEligible = false;
    this->PowerupTimeout = -1.00f;
    this->GameEvenetInteractionArchitectAssetPtr = NULL;
    this->bBuffAllowHealth = false;
    this->bBuffAllowWeapon = false;
    this->DisarmRespawnTime = 8.00f;
    this->ProtegoAttackPtr = NULL;
    this->ProtegoAbilityPtr = NULL;
    this->ProtegoStartupAbilityPtr = NULL;
    this->bProtegoAdditive = false;
    this->ProtegoInteractionArchitectAssetPtr = NULL;
    this->ProtegoHoldTimeout = 2.00f;
    this->bProtegoPlayDeflection = true;
    this->bProtegoShowShieldPulseWhenHit = false;
    this->bProtegoShowOnOffShieldEffects = false;
    this->bAllowProtegoToInterrupAttack = false;
    this->bAllowProtegoToInterrupReactions = false;
    this->ProtegoDeflectionChance = 100;
    this->bOnlyUseDOTReactionForCrucio = false;
    this->LumosPtr = NULL;
    this->LumosAbilityPtr = NULL;
    this->bLumosAdditive = false;
    this->bCanApparateIfUnreachableLoc = true;
    this->bCanApparateToMove = true;
    this->bCanApparateToRecoverWeapon = false;
    this->bApparateUsingFixedTime = true;
    this->ApparateSpeed = 1000.00f;
    this->ApparateFixedTime = 0.50f;
    this->LeaderTargetSenseAsset = NULL;
    this->CompanionTargetSenseAsset = NULL;
    this->CompanionPerceptionMinTimeSincePlayerAttacked = 60.00f;
    this->bAllowTooCloseCounterAttack = false;
    this->bAllowCreateAggroHideTrigger = true;
    this->bAllowApparateMoveWithInvalidMoveLoc = false;
    this->TeleportMoveRangeOffset = 800.00f;
    this->TeleportMoveStuckRangeOffset = 800.00f;
    this->DamageBuffMultiplier = 1.50f;
    this->m_onGround = false;
    this->m_lastOnGround = false;
    this->bSpawnSpellCaster = false;
    this->bSpawnProtegoCaster = false;
    this->SpellCasterClass = NULL;
    this->HiddenTeleportAttackComp = NULL;
    this->KeepAwayFromTargetDist = 0.00f;
    this->bUseFootMatching = false;
    this->bApparateAfterReactions = false;
    this->AggroCorruption = NULL;
    this->AggroCorruptionInstance = NULL;
    this->GameChangerForm = NULL;
    this->CustTargetPtr = NULL;
    this->AttackComp = NULL;
    this->WeaponComp = NULL;
    this->CurrentClimbAbility = NULL;
    this->CurrentJumpToClimbAbility = NULL;
    this->CurrentLadder = NULL;
    this->CurrentSlide = NULL;
    this->CurrentVaultAbility = NULL;
    this->AnimagusPreloadClass = NULL;
    this->bEnableAnimagusFormPreloading = false;
}

