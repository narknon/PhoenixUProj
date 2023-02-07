#include "NPC_Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CognitionComponent.h"
#include "SocialAgentPathFollowerComponent.h"
#include "NPC_BTComponent.h"
#include "NPC_ReactionComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class ANPC_Character;
class APerceptionPointArea;
class APerformTasksForAI;
class UAISense;
class UAblAbility;
class UActorComponent;
class UCapsuleComponent;
class UEnemy_TargetSenseAsset;
class UObject;

bool ANPC_Character::WillAttackPlayer() const {
    return false;
}

void ANPC_Character::Unfreeze() {
}

void ANPC_Character::TargetSighted(UAISense* Sense, const AActor* Target) {
}

void ANPC_Character::TargetLost(UAISense* Sense, const AActor* OldTarget) {
}

void ANPC_Character::TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget) {
}

void ANPC_Character::StopDeathCam() {
}

void ANPC_Character::StopBulletTime() {
}

void ANPC_Character::StartSuspendEnemies(bool bSuspended, EStandardManagedPriority Priority, const UObject* Provider) {
}

void ANPC_Character::StartSettingSuspendAiState(bool bSuspended, EStandardManagedPriority Priority, const UObject* Provider) {
}

void ANPC_Character::StartFadeOut() {
}

void ANPC_Character::StartFadeIn() {
}

void ANPC_Character::StartDissolve() {
}

void ANPC_Character::StartDeathCam() {
}

void ANPC_Character::StartCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bUseCustomPause, bool bClearPauseWhenFinished, bool bPreventReactions, bool bShouldReenableReactions) {
}

void ANPC_Character::StartChildSpawnFX_Implementation(FTransform inSpawnLoc) {
}

void ANPC_Character::StartBulletTime() {
}

bool ANPC_Character::ShouldShowName() const {
    return false;
}

bool ANPC_Character::ShouldShowHealthBar() const {
    return false;
}

bool ANPC_Character::ShouldShowBadge() const {
    return false;
}

void ANPC_Character::SetupBehaviorTreeForced() {
}

void ANPC_Character::SetUnawareState(EEnemy_CharacterState InState) {
}

void ANPC_Character::SetTargetAimSense() {
}

void ANPC_Character::SetStayInVolumeParams(float inStayInRadius, float inStayInVolumeTeleportTimeout, bool inStayInVolumeOffNavTeleport) {
}

void ANPC_Character::SetShowPerceptionIndicator(bool bInShow) {
}

void ANPC_Character::SetShowName(bool bInShow) {
}

void ANPC_Character::SetShowHealthBar(bool bInShow) {
}

void ANPC_Character::SetShowDamage(bool bInShow) {
}

void ANPC_Character::SetShowCallout(bool bInShow) {
}

void ANPC_Character::SetShowBadge(bool bInShow) {
}

void ANPC_Character::SetNewDefaultPerformTask(APerformTasksForAI* NewDefaultTrigger, bool bForceStart, bool bLoopWhenFinished) {
}

void ANPC_Character::SetForcedPlayerPerception(bool InCanPerceive, bool bKeepAlwaysOn) {
}

void ANPC_Character::SetDamageToPlayerMult(float InScale) {
}

void ANPC_Character::SetDamageFromPlayerMult(float InScale) {
}

void ANPC_Character::SetDamageFromNPCMult(float InScale) {
}

void ANPC_Character::SetCanPerceivePlayer(bool bShouldExclude) {
}

void ANPC_Character::SetAlwaysPerceiveAsTarget(bool InFlag) {
}

void ANPC_Character::SetAllowTargetAimSense(bool InAllow) {
}

void ANPC_Character::RestoreStayInVolumeParamDefaults() {
}

void ANPC_Character::RemoveStayInVolume(APerceptionPointArea* InArea) {
}

void ANPC_Character::RemoveQBUpdateSupported(ENPC_QBUpdate InQBUpdate) {
}

void ANPC_Character::RemoveAllStayInVolumes() {
}

void ANPC_Character::ReleaseIntroductionCharacter(AActor* InActor) {
}

void ANPC_Character::Release(const UObject* i_caller) {
}

void ANPC_Character::RagdollImpact() {
}

void ANPC_Character::ProtectIntroductionCharacter(AActor* InActor) {
}



void ANPC_Character::OnPTTaskComplete(int32 InTaskIndex) {
}

void ANPC_Character::OnPTComplete(const APerformTasksForAI* InPTPtr) {
}

void ANPC_Character::OnChildSpawnFX_Implementation(FTransform inSpawnLoc) {
}

void ANPC_Character::OnCharacterDBLoadCompleted(AActor* LoadActor, TEnumAsByte<EActor_LoadDBProcessingType> LoadType) {
}

bool ANPC_Character::NPCWillAttackPlayer(AActor* InActorPtr) {
    return false;
}

FNPC_TargetPerceptionParams ANPC_Character::NPCGetTargetPerceptionParams(AActor* InActorPtr) {
    return FNPC_TargetPerceptionParams{};
}

ANPC_Character* ANPC_Character::NPCEnableTimedAttackPerception(AActor* InActorPtr, FName InTeamName, float InTime, AActor* InTarget) {
    return NULL;
}

ANPC_Character* ANPC_Character::NPCEnableNotifyPerception(AActor* InActorPtr) {
    return NULL;
}

ANPC_Character* ANPC_Character::NPCEnableCrimeScenePerception(AActor* InActorPtr) {
    return NULL;
}

ANPC_Character* ANPC_Character::NPCEnableAttackPerception(AActor* InActorPtr, FName InTeamName) {
    return NULL;
}

void ANPC_Character::NPCDisableNotifyPerception(AActor* InActorPtr) {
}

void ANPC_Character::NPCDisableCrimeScenePerception(AActor* InActorPtr) {
}

void ANPC_Character::NPCDisableAttackPerception(AActor* InActorPtr) {
}


void ANPC_Character::MunitionToInstigator(const UObject* i_caller, const FMunitionToInstigatorData& InMunInstData) {
}

void ANPC_Character::Kill() {
}

bool ANPC_Character::IsScheduledEntity() {
    return false;
}

bool ANPC_Character::IsRootComponent(UActorComponent* InComponent) {
    return false;
}

bool ANPC_Character::IsReleased() const {
    return false;
}

bool ANPC_Character::IsQBUpdateSupported(ENPC_QBUpdate InQBUpdate) const {
    return false;
}

bool ANPC_Character::IsPerceptionUpdateSupported(ENPC_PerceptionUpdate InPerceptionUpdate) const {
    return false;
}

bool ANPC_Character::IsInCreatureAnimationTransition() const {
    return false;
}

bool ANPC_Character::IsInCreatureAnimationStanceTransition() const {
    return false;
}

bool ANPC_Character::IsInCreatureAnimationGaitTransition() const {
    return false;
}

bool ANPC_Character::IsFrozen() const {
    return false;
}

bool ANPC_Character::IsAlive() const {
    return false;
}

bool ANPC_Character::IsAiSuspended() const {
    return false;
}

bool ANPC_Character::HasTaskTag(FGameplayTag InTaskTag) {
    return false;
}

void ANPC_Character::HandleRagdollImpact(const UObject* i_caller) {
}

FNPC_TargetPerceptionParams ANPC_Character::GetTargetPerceptionParams() const {
    return FNPC_TargetPerceptionParams{};
}

bool ANPC_Character::GetShowUIPerceptinCone() const {
    return false;
}

FNPC_ShowUI ANPC_Character::GetShowUI() {
    return FNPC_ShowUI{};
}

bool ANPC_Character::GetShowPerceptionIndicator() const {
    return false;
}

bool ANPC_Character::GetShowName() const {
    return false;
}

bool ANPC_Character::GetShowHealthBar() const {
    return false;
}

bool ANPC_Character::GetShowDamage() const {
    return false;
}

bool ANPC_Character::GetShowCallout() const {
    return false;
}

bool ANPC_Character::GetShowBadge() const {
    return false;
}

ENPC_Type ANPC_Character::GetNPCType() const {
    return ENPC_Type::None;
}

FOdcPathSpec ANPC_Character::GetNPCPathSpec(ENPC_PathSpec InPathSpec) const {
    return FOdcPathSpec{};
}

UCapsuleComponent* ANPC_Character::GetNpcCapsuleComponent_Implementation() {
    return NULL;
}

FVector ANPC_Character::GetImpactLocation() const {
    return FVector{};
}

FVector ANPC_Character::GetImpactDirection() const {
    return FVector{};
}

FEnemy_CharacterParams ANPC_Character::GetCharacterParams() const {
    return FEnemy_CharacterParams{};
}

bool ANPC_Character::GetAlwaysPerceiveAsTarget() const {
    return false;
}

void ANPC_Character::Freeze() {
}

void ANPC_Character::ForceScheduledEntityState() {
}

void ANPC_Character::ForceProtego(bool inProtegoOnOff) {
}

void ANPC_Character::FinishSuspendEnemies(EStandardManagedPriority Priority, const UObject* Provider) {
}

void ANPC_Character::FinishSettingSuspendAiState(EStandardManagedPriority Priority, const UObject* Provider) {
}

void ANPC_Character::EndCustomAbility() {
}

void ANPC_Character::EnablePerception(const UObject* i_caller) {
}

void ANPC_Character::EnableMinimapPerceptionCone(ANPC_Character* NPCCharacter) {
}

void ANPC_Character::EnableCallout(const UObject* i_caller) {
}

void ANPC_Character::EnableBeacon(const UObject* i_caller) {
}

void ANPC_Character::DisablePerception(const UObject* i_caller) {
}

void ANPC_Character::DisableMinimapPerceptionCone(ANPC_Character* NPCCharacter) {
}

void ANPC_Character::DisableCallout(const UObject* i_caller) {
}

void ANPC_Character::DisableBeacon(const UObject* i_caller) {
}

void ANPC_Character::DestroyOnDeath() {
}

void ANPC_Character::DeathFxComplete() {
}



void ANPC_Character::ClearForceScheduledEntityState() {
}

void ANPC_Character::CharacterDiedEvent_Implementation() {
}

bool ANPC_Character::CanBePickpocketed() const {
    return false;
}

void ANPC_Character::BroadcastNPC_AnimEvent(FName InName) {
}

void ANPC_Character::AssignNPCLevelWRTPlayerLevel(const int32 ExpLevel, bool bIndicateHUD) {
}

void ANPC_Character::ApplyTargetSenseAsset(UEnemy_TargetSenseAsset* InTargetSenseAsset) {
}

void ANPC_Character::ApplySpawnFX_Implementation() {
}

void ANPC_Character::ApplyReplicaFX_Implementation() {
}

void ANPC_Character::ApplyNPCPathSpecDirect(FOdcPathSpec InPathSpec) {
}

void ANPC_Character::ApplyNPCPathSpec(ENPC_PathSpec InPathSpec) {
}

void ANPC_Character::ApplyCharacterFX_Implementation() {
}

void ANPC_Character::AddStayInVolume(APerceptionPointArea* InArea) {
}

void ANPC_Character::AddQBUpdateSupported(ENPC_QBUpdate InQBUpdate) {
}

void ANPC_Character::AddPerceptionUpdateSupported(ENPC_PerceptionUpdate InPerceptionUpdate) {
}

ANPC_Character::ANPC_Character() {
    this->NPCType = ENPC_Type::Enemy;
    this->BehaviorTreePtr = NULL;
    this->BehaviorTreeDataTable = NULL;
    this->BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
    this->EmptyBlackboardAsset = NULL;
    this->BTComponent = CreateDefaultSubobject<UNPC_BTComponent>(TEXT("NPC_BTComponent"));
    this->CognitionComponent = CreateDefaultSubobject<UCognitionComponent>(TEXT("Cognition"));
    this->SocialAgentComponent = CreateDefaultSubobject<USocialAgentPathFollowerComponent>(TEXT("SocialAgentComponent"));
    this->NPCComponent = NULL;
    this->CCComponent = NULL;
    this->CogSourceComp = NULL;
    this->NPCReactionComponent = CreateDefaultSubobject<UNPC_ReactionComponent>(TEXT("ReactionComponent"));
    this->CombativePlantComponent = NULL;
    this->QBUpdatesSupported = 0;
    this->PerceptionUpdatesSupported = 0;
    this->QBUpdateDataAsset = NULL;
    this->PerceptionUpdateDataAsset = NULL;
    this->TargetSenseAsset = NULL;
    this->bEnableBeacon = true;
    this->BeaconIconName = TEXT("Enemy");
    this->bAllowDBInstanceRedirect = false;
    this->bCreateScheduledEntity = false;
    this->bIsAScheduledEntity = false;
    this->bShowVulnerabilityIndicators = false;
    this->PatrolPriority = 1;
    this->bAddSocialScoreToPatrol = true;
    this->bUseNPCController = false;
    this->bCommitsACrimeWhenKilling = true;
    this->bCanBePickpocketed = false;
    this->DamageDisplayHeight = 1.00f;
    this->DamageDisplayExtraOffset = 0;
    this->DefaultPathSpec = ENPC_PathSpec::Ground;
    this->LOSRadius = 20.00f;
    this->DeathEffectDelayTime = 4.00f;
    this->bDestroyOnDeath = false;
    this->bDissolveOnDeath = false;
    this->InstantDissolveChance = 0.20f;
    this->DissolveDelayMin = 0.50f;
    this->DissolveDelayMax = 1.00f;
    this->DissolveDestroyDelay = 4.00f;
    this->bFadeOnDeath = true;
    this->bDoNewDeathFade = false;
    this->FadeDelay = 4.00f;
    this->FadeDuration = 4.00f;
    this->bDoDeathCamOnDeath = false;
    this->DeathCamDelay = 0.00f;
    this->DeathCamDuration = 6.00f;
    this->bDoBulletTimeOnDeath = false;
    this->BulletTimeDilation = 0.25f;
    this->BulletTimeDelay = 1.00f;
    this->BulletTimeDuration = 5.00f;
    this->bHaltDeathCamOnBulletTimeStart = true;
    this->StealAmmount = 10;
    this->InventoryKnuts = 0;
    this->FromNPCDamageMult = 1.00f;
    this->FromPlayerDamageMult = 1.00f;
    this->ToPlayerDamageMult = 1.00f;
    this->bAllowReleaseOnce = false;
    this->bOverrideCharacterLook = false;
    this->bOverrideVoice = false;
    this->NPCControllerPtr = NULL;
    this->MinimapPerceptionData = NULL;
    this->DesiredCreatureStance = ECreatureStance::Standing;
    this->CurrentCreatureStance = ECreatureStance::Standing;
    this->NextCreatureStance = ECreatureStance::Standing;
    this->CurrentCreatureGait = ECreatureMovementSpeed::Stop;
    this->NextCreatureGait = ECreatureMovementSpeed::Stop;
    this->bInCreatureIdleVariation = false;
    this->MotionTable = NULL;
    this->MoveToStopDistanceTune = 1.40f;
    this->bDisableCreatureTurnNavChecks = false;
}

