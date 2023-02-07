#include "NPC_Component.h"
#include "Templates/SubclassOf.h"

class AAIController;
class AActor;
class ACharacter;
class ANPC_Character;
class ANPC_Spline;
class UAblAbility;
class UAblReactionComponent;
class UAblReactionData;
class UAnimInstance;
class UBlackboardComponent;
class UCurveFloat;
class UNPC_AbilityTaskScratchPad;
class UNPC_AnimInstance;
class UNavigationQueryFilter;
class USkeletalMeshComponent;

bool UNPC_Component::WasActionASuccess(EEnemyAIAction InAction) const {
    return false;
}

bool UNPC_Component::UpdateTetheredLoc(FVector& OutLoc, bool& OutDone) {
    return false;
}

void UNPC_Component::UnchainAction(EEnemyAIAction ChainFromAction) {
}

bool UNPC_Component::TreeWaitUpdate(float DeltaTime) {
    return false;
}

FVector UNPC_Component::TetheredWanderLocation() {
    return FVector{};
}

void UNPC_Component::StopSpeedScaleAdjust() {
}

void UNPC_Component::StopMove() {
}

void UNPC_Component::StopActionOnUpdate(EEnemyAIAction InAction) {
}

void UNPC_Component::StopAction(EEnemyAIAction InAction, bool bSuccess, bool bTimeout) {
}

void UNPC_Component::StartupAbility() {
}

void UNPC_Component::StartSpeedScaleAdjust(float InScale, float DurationSeconds) {
}

void UNPC_Component::StartDynamicBranch(EEnemy_Ability InAbility, EEnemy_Ability InNextAbility, bool bImmediate) {
}

void UNPC_Component::StartCustomPause(bool bCleanupWhenCustomAbilityFinished) {
}

bool UNPC_Component::StartAction(EEnemyAIAction InAction, float Timeout) {
    return false;
}

bool UNPC_Component::SidekickUpdateStateUpdate(ENPC_SidekickUpdateState InUpdateState, float DeltaTime) {
    return false;
}

void UNPC_Component::SetWanderStartLocation(FVector Location) {
}

void UNPC_Component::SetTargetSightedEnable(bool bEnable) {
}

void UNPC_Component::SetTargetLocationTurnInPlace(FVector InTargetLoc_TurnInPlace) {
}

void UNPC_Component::SetTarget(AActor* pTarget) {
}

void UNPC_Component::SetStealthContext() {
}

void UNPC_Component::SetSpeedScale(float InScale) {
}

void UNPC_Component::SetSpeedChooserScale(float InScale) {
}

void UNPC_Component::SetSpeed(float InSpeed) {
}

void UNPC_Component::SetSpawnAnimOffset(float InOffset) {
}

void UNPC_Component::SetScale(float Scale) {
}

void UNPC_Component::SetOverrideMobility(ENPC_Mobility InMobility) {
}

void UNPC_Component::SetOnStairs() {
}

void UNPC_Component::SetOnSlope() {
}

void UNPC_Component::SetOnFire() {
}

void UNPC_Component::SetMoveGoal(FVector InGoal, bool bNavReachable) {
}

void UNPC_Component::SetJumpSplineData(const FNPC_JumpSplineData& InData) {
}

void UNPC_Component::SetJumpSpline(ANPC_Spline* InSplinePtr) {
}

void UNPC_Component::SetInvincibility(bool InIsInvincible) {
}

void UNPC_Component::SetForcedPerceptionTarget(AActor* InTargetPtr, ENPC_TargetAwareState InTAS, float InTime) {
}

void UNPC_Component::SetFleeTargetPos(FVector InPos) {
}

void UNPC_Component::SetFireExtinguished() {
}

void UNPC_Component::SetFinisherTagFilter(FGameplayTag InTag) {
}

void UNPC_Component::SetCustomPauseExitConditions(bool bCleanupWhenAlert, bool CleanupWhenAttack, AActor* TargetToAllow) {
}

void UNPC_Component::SetCrouching() {
}

void UNPC_Component::SetCrouchContextFlag(ENPC_CrouchContext CrouchContext) {
}

void UNPC_Component::SetCharred() {
}

void UNPC_Component::SetCharacterRootMotionScale(float RootMotionScale) {
}

void UNPC_Component::SetBlackboardKey(EEnemy_BBKey InKey, bool bSet) {
}

void UNPC_Component::SetBlackboardFloat(const FName& InBBName, float InValue) {
}

void UNPC_Component::SetBlackboardBool(const FName& InBBName, bool InValue) {
}

void UNPC_Component::SetBlackboard(UBlackboardComponent* pBlackboardComp) {
}

void UNPC_Component::SetAttackCustomFlag(bool FlagIsSet) {
}

void UNPC_Component::SetAnimState(EEnemyAIAnimState InAnimState) {
}

void UNPC_Component::SetAnimSpawnState(ENPC_SpawnState InSpawnState) {
}

void UNPC_Component::SetAnimMainState(EEnemy_AnimMainState InAnimState) {
}

void UNPC_Component::SetActionParams(FNPC_ActionParams InParams) {
}

void UNPC_Component::SetAction(EEnemyAIAction InAction, bool bSet) {
}

void UNPC_Component::SetAbilityScratchpadVelocity(FVector InVelocity) {
}

void UNPC_Component::SetAbilityActive(EEnemy_Ability InState, bool bActive) {
}

int32 UNPC_Component::PickRandomPath(const AAIController* AIOwner, TArray<FVector> Targets, float TopPercent, TEnumAsByte<EPathExistanceQueryType::Type> PathQueryType, TSubclassOf<UNavigationQueryFilter> FilterClass, bool AllowPartialPaths, FVector& outTarget) {
    return 0;
}

bool UNPC_Component::PathExists(const AAIController* AIOwner, FVector Target, TEnumAsByte<EPathExistanceQueryType::Type> PathQueryType, TSubclassOf<UNavigationQueryFilter> FilterClass, bool AllowPartialPaths) {
    return false;
}

void UNPC_Component::ParryEvent(EEnemy_ParryButtonPressed InButtonPressed) {
}



void UNPC_Component::OnReactionReceived(const FQueueReactionParams& ReactionParams, UAblReactionComponent* ReactionComponent) {
}

void UNPC_Component::OnReactionQueued(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent) {
}

void UNPC_Component::OnReactionEnd(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent) {
}

void UNPC_Component::OnMovementModeChange(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode) {
}

void UNPC_Component::OnLoadComplete(AActor* LoadedActor) {
}

void UNPC_Component::OnExitAliveVolume(AActor* InActor) {
}

void UNPC_Component::OnEnterKillVolume(AActor* InActor) {
}

void UNPC_Component::OnDestroyed(AActor* Actor) {
}

void UNPC_Component::NPCRemoveFromManager(AActor* InActorPtr) {
}

void UNPC_Component::NPCAddToManager(AActor* InActorPtr) {
}

bool UNPC_Component::NeedsStayInVolumeConstrain(const FVector& InLoc) const {
    return false;
}

bool UNPC_Component::MoveToOnFire(float DeltaTime) {
    return false;
}

bool UNPC_Component::MoveToLocation(FVector Loc, UCurveFloat* CurveFloatPtr, float InterpSpeed, float DeltaTime, bool bStopOnOverlap) {
    return false;
}

TEnumAsByte<EPathFollowingRequestResult::Type> UNPC_Component::MoveTo(const FVector Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath) {
    return EPathFollowingRequestResult::Failed;
}

void UNPC_Component::Kill() {
}

void UNPC_Component::K2_SetTargetableByPlayer(bool bTargetableByPlayer) {
}

void UNPC_Component::JumpSplineStart() {
}

bool UNPC_Component::IsVulnerable() const {
    return false;
}

bool UNPC_Component::IsTargetSightedEnabled() const {
    return false;
}

bool UNPC_Component::IsSwimming() const {
    return false;
}

bool UNPC_Component::IsStationary() const {
    return false;
}

bool UNPC_Component::IsSpawnFinished() {
    return false;
}

bool UNPC_Component::IsReactionActive() const {
    return false;
}

bool UNPC_Component::IsOnStairs() const {
    return false;
}

bool UNPC_Component::IsOnSlope() const {
    return false;
}

bool UNPC_Component::IsOnFire() const {
    return false;
}

bool UNPC_Component::IsNearDeathKneeling() const {
    return false;
}

bool UNPC_Component::IsMoveDone() const {
    return false;
}

bool UNPC_Component::IsJumpSplineDone() const {
    return false;
}

bool UNPC_Component::IsInvincible() const {
    return false;
}

bool UNPC_Component::IsInStealth() const {
    return false;
}

bool UNPC_Component::IsInStation() const {
    return false;
}

bool UNPC_Component::IsInjured() const {
    return false;
}

bool UNPC_Component::IsFlying() const {
    return false;
}

bool UNPC_Component::IsDead() const {
    return false;
}

bool UNPC_Component::IsCrouching() const {
    return false;
}

bool UNPC_Component::IsCompanion() const {
    return false;
}

bool UNPC_Component::IsCharred() const {
    return false;
}

bool UNPC_Component::IsBlind() const {
    return false;
}

bool UNPC_Component::IsActionDone(EEnemyAIAction InAction) const {
    return false;
}

bool UNPC_Component::IsActionActive(EEnemyAIAction InAction) const {
    return false;
}

bool UNPC_Component::IsAbilityVulnerable(EEnemy_Ability InAbility) const {
    return false;
}

bool UNPC_Component::IsAbilitySupported(EEnemy_Ability InAbility) const {
    return false;
}

bool UNPC_Component::IsAbilityActive(EEnemy_Ability InState) const {
    return false;
}

FGameplayTagContainer UNPC_Component::InsertIATagsToSpawnData(ENPC_Spawn InSpawnType, FGameplayTagContainer InTagContainer) {
    return FGameplayTagContainer{};
}

void UNPC_Component::InitTreeWait(const FGameplayTag& TreeTag, const TArray<EEnemy_Ability>& InAbilityList, float Timeout, EEnemy_InitTreeTimeoutAction TimeoutAction) {
}

void UNPC_Component::InitTetheredLoc(float InTetherDist, const FVector& InStartVec, bool bUseStartVec, float InMaxAngle, int32 InDivisions, bool bInApplyTether, ENPC_Tether InTetherType, float randomDistFloor, float randomDistCeiling) {
}

bool UNPC_Component::InitMoveToOnFire() {
    return false;
}

bool UNPC_Component::InitMoveToLocation(FVector DestinationLoc, float Timeout, ENPC_Mobility InMobility, bool bOverrideMobility) {
    return false;
}

bool UNPC_Component::InitMoveToFleePos(FVector InPos, float Timeout) {
    return false;
}

void UNPC_Component::InitMoveData(ENPC_MoveDataState InState, AActor* TargetPtr, float Timeout) {
}

bool UNPC_Component::HasSightedTarget() const {
    return false;
}

bool UNPC_Component::HasFinisherWithRunningRequirementsMet(AActor* Attacker) const {
    return false;
}

float UNPC_Component::GetYaw() const {
    return 0.0f;
}

FVector UNPC_Component::GetWanderStartLocation() const {
    return FVector{};
}

bool UNPC_Component::GetTreeWaitResult() const {
    return false;
}

FVector UNPC_Component::GetTetheredLoc(float InDist, const FVector& InStartVec, bool bUseStartVec, float InMaxAngle, int32 InDivisions, bool bInApplyTether, ENPC_Tether InTetherType, float randomDistFloor, float randomDistCeiling) {
    return FVector{};
}

EEnemy_TargetType UNPC_Component::GetTargetType() const {
    return EEnemy_TargetType::None;
}

float UNPC_Component::GetTargetLookatApha() const {
    return 0.0f;
}

AActor* UNPC_Component::GetTarget() const {
    return NULL;
}

float UNPC_Component::GetSpeedScale() {
    return 0.0f;
}

float UNPC_Component::GetSpeedChooserScale() {
    return 0.0f;
}

ENPC_SidekickUpdateState UNPC_Component::GetSidekickUpdateState() const {
    return ENPC_SidekickUpdateState::None;
}

float UNPC_Component::GetScale() const {
    return 0.0f;
}

TSubclassOf<UAblAbility> UNPC_Component::GetPlayerCriticalFinisherAbility(FGameplayTagContainer& MunitionsTags) {
    return NULL;
}

TSubclassOf<UAblAbility> UNPC_Component::GetPlayerCriticalDamageAbility(FGameplayTagContainer& MunitionsTags) {
    return NULL;
}

bool UNPC_Component::GetPerceptionSuspended() const {
    return false;
}

bool UNPC_Component::GetPerceptionEnabled() const {
    return false;
}

ENPC_Mobility UNPC_Component::GetOverrideMobility() const {
    return ENPC_Mobility::None;
}

bool UNPC_Component::GetOnGround() const {
    return false;
}

UNPC_AnimInstance* UNPC_Component::GetNPCAnimInstance() {
    return NULL;
}

FVector UNPC_Component::GetMyLoc() const {
    return FVector{};
}

FVector UNPC_Component::GetMyGroundLoc() const {
    return FVector{};
}

bool UNPC_Component::GetMoveToLocationSuccess() const {
    return false;
}

TEnumAsByte<EPathFollowingRequestResult::Type> UNPC_Component::GetMoveToLocationResult() {
    return EPathFollowingRequestResult::Failed;
}

float UNPC_Component::GetMoveTolerance() const {
    return 0.0f;
}

bool UNPC_Component::GetMoveToDone() const {
    return false;
}

bool UNPC_Component::GetMoveDataSuccess() const {
    return false;
}

ENPC_Mobility UNPC_Component::GetMobility() const {
    return ENPC_Mobility::None;
}

USkeletalMeshComponent* UNPC_Component::GetMeshComponent() const {
    return NULL;
}

ENPC_TargetAwareState UNPC_Component::GetKilledTAS() const {
    return ENPC_TargetAwareState::None;
}

AActor* UNPC_Component::GetForcedPerceptionTarget() {
    return NULL;
}

FVector UNPC_Component::GetFleeTargetPos() {
    return FVector{};
}

FVector UNPC_Component::GetFleeDistLocation() {
    return FVector{};
}

EEnemyAIAction UNPC_Component::GetChainedAction(EEnemyAIAction InAction) const {
    return EEnemyAIAction::None;
}

float UNPC_Component::GetCapsuleRadius() const {
    return 0.0f;
}

float UNPC_Component::GetCapsuleHalfHeight() const {
    return 0.0f;
}

FVector UNPC_Component::GetAUXRecoverLoc() const {
    return FVector{};
}

EEnemyAIAnimState UNPC_Component::GetAnimState() {
    return EEnemyAIAnimState::Idle;
}

ENPC_SpawnState UNPC_Component::GetAnimSpawnState() {
    return ENPC_SpawnState::None;
}

EEnemy_AnimMainState UNPC_Component::GetAnimMainState() {
    return EEnemy_AnimMainState::None;
}

UAnimInstance* UNPC_Component::GetAnimInstance() const {
    return NULL;
}

EEnemy_Ability UNPC_Component::GetActiveAbility() const {
    return EEnemy_Ability::Idle;
}

bool UNPC_Component::GetAction(EEnemyAIAction InAction) const {
    return false;
}

UNPC_AbilityTaskScratchPad* UNPC_Component::GetAbilityScratchpad() const {
    return NULL;
}

void UNPC_Component::ForcePerceptionUpdate() {
}

void UNPC_Component::FinishReactionParrySuccessTimeDilation() {
}

FVector UNPC_Component::FindValidLocation(FVector InPos) {
    return FVector{};
}

bool UNPC_Component::ExecuteAbility(TSubclassOf<UAblAbility> InAbilityPtr, ENPC_AbilityChannel InChannel) {
    return false;
}

void UNPC_Component::EnterTree(const FGameplayTag& TreeTag, bool InAbortMove) {
}

void UNPC_Component::EndCustomPause() {
}

void UNPC_Component::EnablePerception(bool Enable) {
}

void UNPC_Component::EnableAbilityChannel(ENPC_AbilityChannel InChannel, bool bInEnable) {
}

bool UNPC_Component::CriticalFinisherAllowTimeDilation() {
    return false;
}

FNPC_NavPath UNPC_Component::CreateNavPath(AAIController* InControllerPtr, const FVector& InStartLoc, const FVector& InEndLoc, float InToleranceRadius) {
    return FNPC_NavPath{};
}

void UNPC_Component::ClearStealthContext() {
}

void UNPC_Component::ClearCrouchContextFlag(ENPC_CrouchContext CrouchContext) {
}

void UNPC_Component::ChainAction(EEnemyAIAction ChainFromAction, EEnemyAIAction ChainToAction) {
}

float UNPC_Component::CalcFleeMoveToLocationTime(FVector InDestination) {
    return 0.0f;
}

void UNPC_Component::BroadcastNPC_AnimEvent(FName InName) {
}

AActor* UNPC_Component::AttemptToFindUniqueOwnerForFollower(TSubclassOf<ANPC_Character> OwnerClass, ANPC_Character* InFollower, float FindDistance) {
    return NULL;
}

AActor* UNPC_Component::AttemptToFindPackOwnerForFollower(ANPC_Character* InFollower, float FindDistance) {
    return NULL;
}

void UNPC_Component::ActionUpdate(EEnemyAIAction InAction, float DeltaTime) {
}

void UNPC_Component::AbortAction(EEnemyAIAction InAction) {
}

UNPC_Component::UNPC_Component() {
    this->DefaultMunitionInteractionArchitectAsset = NULL;
    this->bEnableAnimationTickOptimization = true;
    this->bEnableShutdownOptimization = true;
    this->FootprintSize = 350.00f;
    this->bDestroyOnDeath = false;
    this->bSidekick = false;
    this->bAllowBackLight = false;
    this->SpawnType = ENPC_Spawn::None;
    this->bPerceptionCanInterruptSpawn = false;
    this->SpawnInteractionArchitectAsset = NULL;
    this->SpawnCollisionRadius = 500.00f;
    this->SpawnCollisionImpulse = 5000.00f;
    this->SpawnCollisionScaledForce = 500.00f;
    this->DefaultChannel = ENPC_AbilityChannel::FullBody;
    this->IdleAbility = NULL;
    this->WanderIdleAbility = NULL;
    this->SpawnStartAbility = NULL;
    this->MoveAbility = NULL;
    this->MoveStopAbility = NULL;
    this->MoveStartAbility = NULL;
    this->MovePivotAbility = NULL;
    this->SecondaryAttackAbility = NULL;
    this->HealAttackAbility = NULL;
    this->ReparoAttackAbility = NULL;
    this->JumpSplineAbility = NULL;
    this->CustomSpellAbility = NULL;
    this->NeutralEmotionAbility = NULL;
    this->FollowSplineAbility = NULL;
    this->FollowSplineIdleAbility = NULL;
    this->WoundedKneelAbility = NULL;
    this->DazedAbility = NULL;
    this->DeadAbility = NULL;
    this->DisillusionmentAbilityEnter = NULL;
    this->DisillusionmentAbilityExit = NULL;
    this->bIdleTimeoutFailsafe = false;
    this->HealSpellToolRecord = NULL;
    this->ReparoSpellToolRecord = NULL;
    this->CustomSpellToolRecord = NULL;
    this->DisillusionmentSpellToolRecord = NULL;
    this->bRegisterAsTargetSource = false;
    this->PerceptionChoice = NULL;
    this->bRandomizeScaleOnSpawn = false;
    this->MinScale = 1.00f;
    this->MaxScale = 1.00f;
    this->OppositeDirectionFleeValidDistance = 2000.00f;
    this->bEnterOnFireState = false;
    this->bUseOnFireStateBehavior = false;
    this->bBroadcastAudioHeartbeat = false;
    this->AudioHeartbeatDist = 3500.00f;
    this->bDoDirectionAvoidance = false;
    this->RepulsorRadiusMultiplier = 1.00f;
    this->RepulsorRadiusCushionMultiplier = 0.20f;
    this->RepulsorDetectionRadiusMultiplier = 10.00f;
    this->ResolveBlockedAllowableAngle = 180.00f;
    this->bUseDirectionFilter = true;
    this->DirectionFilterRate = 1.00f;
    this->DirectionFilterRateMin = 0.10f;
    this->DirectionFilterRateMax = 0.30f;
    this->DirectionAvoidanceInterval = 0.00f;
    this->AvoidanceSlowdownScale = 0.80f;
    this->MovePivotMinAngle = 35.00f;
    this->OverrideNavRadius = -1.00f;
    this->NavFitRadius = 40.00f;
    this->NavFitVerticalRadius = 600.00f;
    this->NavFitMoveTolerance = 10.00f;
    this->NavReachableDownRadius = 200.00f;
    this->NavReachableUpRadius = 200.00f;
    this->NavReachableRadius = 100.00f;
    this->WaterResponse = ENPC_WaterResponse::SwimToShore;
    this->LOSRadius = 20.00f;
    this->AlertUIRate = 5.00f;
    this->TASSenseHoldTime = 2.00f;
    this->bUseNavigator = true;
    this->AbilityScratchPad = NULL;
    this->bGlobalVulnerability = true;
    this->bUseExpliciteProtegoStart = false;
    this->bProtegoStaysUpWhileAttacking = true;
    this->ProtegoCooldownTime = 5.00f;
    this->ProtegoBrokeTime = 10.00f;
    this->ProtegoWaitTime = 2.00f;
    this->ProtegoOnOffEffectAdjustment = 0.00f;
    this->VulnerableAbilities = 0;
    this->bHeadTrackToAttackTarget = true;
    this->ReactionParrySuccessTimeDilation = 0.50f;
    this->ReactionParrySuccessTimeDilationDuration = 1.00f;
    this->RagdollControlComp = NULL;
    this->UpdateNPCControllerPtr = NULL;
    this->m_pBlackboardComp = NULL;
    this->DynamicBranchComp = NULL;
    this->NPCReactionComponent = NULL;
    this->CapsuleComp = NULL;
    this->MeshComponent = NULL;
    this->AmbulatoryMoveComp = NULL;
    this->CCComponent = NULL;
    this->AAComponent = NULL;
    this->AbilityComponent = NULL;
    this->BehaviorTreeComponent = NULL;
    this->DefaultState = EEnemyAIState::None;
    this->bSetLockedStateForScheduledEntityMode = false;
    this->EmoDefaultAbility = NULL;
    this->bCriticalFinisherAllowTimeDilation = false;
    this->bFinisherDisabled = false;
}

