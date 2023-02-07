#include "NPC_System.h"

class AActor;
class ADynamicObjectVolume;
class AMunitionType_Base;
class ANPC_Character;
class UNPC_System;

void UNPC_System::TrackObject(const FString& ObjectName, AActor* ParentObject, AActor* ChildObject) {
}

void UNPC_System::TrackerCallback(AActor* ChildObject) {
}

void UNPC_System::TerminateAllBossFights() {
}

void UNPC_System::StartWandLinkEvent(AActor* TargetActor, TArray<AActor*> ExcludeListAlways, TArray<AActor*> ExcludeListOnce) {
}

void UNPC_System::StartBossFight(FName InBossFightName) {
}

void UNPC_System::SetToDead(AActor* InActorPtr) {
}

void UNPC_System::SetOverrideThreatLevel(ENPC_CombatThreatLevel InThreatLevel) {
}

void UNPC_System::SetLoadoutConfigurationContext(const FString& InContext) {
}

void UNPC_System::SetCanPerceivePlayerStatic(bool bCanPerceive) {
}

void UNPC_System::SetBossFightState(FName InBossFightName, EBossStates InBossState) {
}

void UNPC_System::SetBossFightCharacter(FName InBossFightName, AActor* InBossCharacterPtr) {
}

void UNPC_System::SendHermesMessageToDOVActors(ADynamicObjectVolume* InDOVPtr, FName InMessage) {
}

void UNPC_System::SelectCycle() {
}

void UNPC_System::ReportGameEvent(FGameplayTagContainer TagContainer, FVector Location, EGameEvent_Intensity Intensity, float Duration, float Range, float Falloff, AActor* Instigator, bool bTrackBackToInstigator, AActor* Target, FName Name) {
}

void UNPC_System::RemoveObject(AActor* ChildObject) {
}

void UNPC_System::RemoveNonNPC(AActor* NonNPCPtr) {
}

void UNPC_System::RemoveFromManager(AActor* InActorPtr) {
}

void UNPC_System::PostDeath_TimerModeCallback() {
}

void UNPC_System::PostDeath_CleanupCallback(ANPC_Character* InNPCCharacter) {
}

int32 UNPC_System::ParryLaunchedProjectileStart(const FEnemy_ParryWindowSetupData& InSetupData, AActor* InOwner, AActor* InProjectile, float InVelocityMag, float InPostParryVelocityMag) {
    return 0;
}

void UNPC_System::ParryLaunchedProjectileNotifyMunitionCreated(int32 InWindowID, AActor* InOwnerPtr, AActor* InTargetPtr, AMunitionType_Base* InMunitionPtr) {
}

void UNPC_System::ParryLaunchedProjectileEnd(int32 InWindowID) {
}

void UNPC_System::OnSaveGameLoaded() {
}

void UNPC_System::OnGameToBeSaved() {
}

void UNPC_System::OnCurtainRaised() {
}

void UNPC_System::OnCurtainLowered() {
}

void UNPC_System::OnBossDeadEvent(AActor* DeadActor) {
}

void UNPC_System::KillNPC(AActor* InActorPtr) {
}

void UNPC_System::KilledEvent(AActor* EnemyPtr, AActor* KilledByPtr, bool bKilledByPlayer, bool bPlayCameraCut) {
}

bool UNPC_System::IsPlayerInCombat() {
    return false;
}

bool UNPC_System::IsBossFightActive() {
    return false;
}

void UNPC_System::GetTrackedChildren(AActor* ParentObject, TArray<AActor*>& FoundChildren) {
}

FAssetTrackerData UNPC_System::GetObjectTracker(const FString& ObjectName) {
    return FAssetTrackerData{};
}

void UNPC_System::GetNPCsByTypeWithinRadius(const ENPC_ManagerType ManagerType, const FVector& SourceLocation, const float Radius, TArray<AActor*>& FoundNPCs) {
}

float UNPC_System::GetClosest(AActor* NPCPtr) const {
    return 0.0f;
}

EBossStates UNPC_System::GetBossFightState(FName InBossFightName) {
    return EBossStates::BS_None;
}

FName UNPC_System::GetBossFightNameFromBossCharacter(AActor* BossActor) {
    return NAME_None;
}

FName UNPC_System::GetBossFightName(FName BossDbId) {
    return NAME_None;
}

FBossFightData UNPC_System::GetBossFightData(FName InBossFightName) {
    return FBossFightData{};
}

AActor* UNPC_System::GetBossFightCharacter(FName InBossFightName) {
    return NULL;
}

UNPC_System* UNPC_System::Get() {
    return NULL;
}

void UNPC_System::FollowAttackTimeout() {
}

void UNPC_System::FinishAvadaKedavraEvent() {
}

void UNPC_System::EndWandLinkEvent() {
}

void UNPC_System::EndBossFight(FName InBossFightName) {
}

void UNPC_System::EnableTargetPerception(AActor* InActorPtr, bool bEnable) {
}

void UNPC_System::EnableCombat(AActor* InActorPtr, bool bEnable) {
}

void UNPC_System::ClearLoadoutConfigurationContext() {
}

void UNPC_System::ChangeManager(AActor* InActorPtr, FGameplayTag InNewTag) {
}

bool UNPC_System::CanPerceivePlayerStatic() {
    return false;
}

bool UNPC_System::AnyNPCLOSPlayer() {
    return false;
}

bool UNPC_System::AnyNPCAwareOfPlayer() {
    return false;
}

bool UNPC_System::AnyNPCAttackingPlayer() {
    return false;
}

void UNPC_System::AdvanceBossFightSystem(FName InBossFightName) {
}

void UNPC_System::AdvanceBossFightManual(FName InBossFightName) {
}

void UNPC_System::AdvanceBossFight(FName InBossFightName) {
}

void UNPC_System::AddToManager(AActor* InActorPtr) {
}

void UNPC_System::AddNonNPC(AActor* NonNPCPtr) {
}

UNPC_System::UNPC_System() {
    this->WeaponManager = NULL;
}

