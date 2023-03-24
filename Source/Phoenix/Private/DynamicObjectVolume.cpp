#include "DynamicObjectVolume.h"
#include "EncounterSpawnComponent.h"
#include "ManualNavigationInvokerComponent.h"
#include "MissionSpawnComponent.h"
#include "OwnershipComponent.h"

class AActor;
class APerceptionPointBox;
class ASpawnLocation;

void ADynamicObjectVolume::TerminateContinuousSpawning() {
}

void ADynamicObjectVolume::SetSpawnSequenceComplete() {
}

void ADynamicObjectVolume::SetSpawnLocations(TArray<ASpawnLocation*> InSpawnLocations) {
}

void ADynamicObjectVolume::SetSpawnBoundsFromVectors(const FVector& Min, const FVector& Max) {
}

void ADynamicObjectVolume::SetSpawnBounds(const FBox& SpawnBounds) {
}

void ADynamicObjectVolume::SetEnableSpawning(bool bSpawningEnabled, bool bCullActive) {
}

void ADynamicObjectVolume::SetAllowAutoActivation(bool bAllowAutoActivate) {
}

void ADynamicObjectVolume::ResetContinuousSpawning() {
}

void ADynamicObjectVolume::OnFinishedSpawning(const FName& GroupName) {
}

void ADynamicObjectVolume::OnActorSpawnPrep(const FString& SpawnGroup) {
}

void ADynamicObjectVolume::OnActorSpawnInFinished(AActor* SpawnedActor) {
}

void ADynamicObjectVolume::OnActorSpawnFinished(AActor* SpawnedActor) {
}

void ADynamicObjectVolume::OnActorSpawnFinalize(AActor* SpawnedActor) {
}

void ADynamicObjectVolume::OnActorSpawned(AActor* SpawnedActor, const FName& GroupName) {
}

void ADynamicObjectVolume::OnActorDeadEvent(AActor* DeadActor) {
}

void ADynamicObjectVolume::ObjectLoaded() {
}

void ADynamicObjectVolume::ObjectInfoComplete(FNPC_DbIdInfo InObjectIDs) {
}

bool ADynamicObjectVolume::IsSpawningEnabled() const {
    return false;
}

bool ADynamicObjectVolume::IsAutoActivationEnabled() {
    return false;
}

void ADynamicObjectVolume::InitializeTags(FGameplayTagContainer InTagsToConsider) {
}

bool ADynamicObjectVolume::HasSpawned() const {
    return false;
}

FVector ADynamicObjectVolume::GetVolumeExtents() {
    return FVector{};
}

FBox ADynamicObjectVolume::GetVolumeBounds() const {
    return FBox{};
}

FBox ADynamicObjectVolume::GetSpawnBounds() {
    return FBox{};
}

int32 ADynamicObjectVolume::GetSpawnActorCount() {
    return 0;
}

int32 ADynamicObjectVolume::GetObjectCount() {
    return 0;
}

int32 ADynamicObjectVolume::GetKillActorCount() {
    return 0;
}

void ADynamicObjectVolume::GetAllActiveInstances(TArray<AActor*>& OutInstances) {
}

int32 ADynamicObjectVolume::GetAliveActorCount() {
    return 0;
}

bool ADynamicObjectVolume::GetActiveInstances(const FString& InSpawnGroup, TArray<AActor*>& OutInstances) {
    return false;
}

int32 ADynamicObjectVolume::GetActiveActorCount() {
    return 0;
}

void ADynamicObjectVolume::ForceSpawn() {
}

void ADynamicObjectVolume::ForceDeactivate() {
}

void ADynamicObjectVolume::ForceActivate() {
}

void ADynamicObjectVolume::EncounterDeactivate() {
}

void ADynamicObjectVolume::EncounterActivate() {
}

bool ADynamicObjectVolume::DoneSpawning() const {
    return false;
}

void ADynamicObjectVolume::DestroySpawnedActor(AActor* actorToDestroy) {
}

void ADynamicObjectVolume::ContinuousSpawnDelayed() {
}

void ADynamicObjectVolume::ClearTeamShareVolumes() {
}

void ADynamicObjectVolume::ClearTargetExcludeVolumes() {
}

void ADynamicObjectVolume::ClearStayInVolumes() {
}

void ADynamicObjectVolume::ClearPerceiveVolumes() {
}

void ADynamicObjectVolume::ClearKillVolumes() {
}

void ADynamicObjectVolume::ClearForcePerceiveVolumes() {
}

void ADynamicObjectVolume::ClearAliveVolumes() {
}

void ADynamicObjectVolume::AttachEncompassingSpawners(const FString& ObjectName) {
}

bool ADynamicObjectVolume::AllowLinkedEvent() const {
    return false;
}

bool ADynamicObjectVolume::AllowAllDeadEvent() const {
    return false;
}

void ADynamicObjectVolume::AddTeamShareVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddTargetExcludeVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddStayInVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddPerceiveVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddKillVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddForcePerceiveVolume(APerceptionPointBox* InVolume) {
}

void ADynamicObjectVolume::AddAliveVolume(APerceptionPointBox* InVolume) {
}

ADynamicObjectVolume::ADynamicObjectVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowActivationDistances = false;
    this->bEnableAutoActivation = true;
    this->TriggerDistance = 1000.00f;
    this->CullDistance = 1500.00f;
    this->TriggerCullDiff = 500.00f;
    this->bMaintainTriggerCullDistance = false;
    this->bAllowContinuousSpawning = false;
    this->ContinuousMaxActorCount = 1;
    this->ContinuousMinActorCount = 1;
    this->ContinuousTotalActorCount = -1;
    this->ContinuousMinSpawnDelay = 0.00f;
    this->ContinuousMaxSpawnDelay = 0.00f;
    this->bEnableSpawning = true;
    this->bUseDiscoveredSpawnLocations = false;
    this->bDisableCombat = false;
    this->bSpawnWhenActivated = true;
    this->bCullWhenDeactivated = true;
    this->bFadeOutWhenCulled = true;
    this->bOnlySpawnOnce = false;
    this->bApplyDelayToFirstGroup = false;
    this->GroupMinDelay = 0.00f;
    this->GroupMaxDelay = 0.00f;
    this->distributionType = EDynamicObjectVolumeSpawnDistributionType::Uniform;
    this->bLimitUseToDiscoveredLocations = false;
    this->bForceDiscoveredLocsToDesiredType = false;
    this->DiscoveryType = EDynamicObjectVolumeDiscoveryType::Default;
    this->bCheckRestrictionsWhileActivated = false;
    this->bQuestRelevantPassthrough = false;
    this->ScheduleColumnFilter = TEXT("CharacterID");
    this->bOverrideWorldID = false;
    this->bChangeSpawnedEnemyTeam = false;
    this->bUseAttackTicketOverride = false;
    this->InventoryObjectUnitCount = 1;
    this->SpawnVolumeType = ESpawnVolumeType::Box;
    this->bIsNotEncounter = true;
    this->bIsStaticSpawner = false;
    this->bDoAsyncDebugSpawning = true;
    this->bAllowIndexedSpawning = false;
    this->bGetRegionLevelOverrideFromLocation = false;
    this->ActivateLinksAt = 0;
    this->TriggerLinksOnStealth = false;
    this->EncounterComponent = CreateDefaultSubobject<UEncounterSpawnComponent>(TEXT("EncounterSpawnComponent"));
    this->bDestroyOnDeath = false;
    this->bDissolveOnDeath = false;
    this->bFadeOnDeath = false;
    this->bDoDeathCamOnLastDeath = false;
    this->bDoDeathCamBulletTime = false;
    this->VolumeComponent = NULL;
    this->NavInvokerComponent = CreateDefaultSubobject<UManualNavigationInvokerComponent>(TEXT("NavInvokerComponent"));
    this->MissionComponent = CreateDefaultSubobject<UMissionSpawnComponent>(TEXT("MissionSpawnComponent"));
    this->OwnershipComponent = CreateDefaultSubobject<UOwnershipComponent>(TEXT("DefaultOwnershipComponent"));
    this->DebugTextVisualizer = NULL;
    this->isConstructed = false;
    this->bFromNamedEncounter = false;
}

