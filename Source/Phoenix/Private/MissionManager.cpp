#include "MissionManager.h"

class AActor;
class APerformTasksForAI;
class UBeaconInfo;
class UMissionManager;
class UObject;
class UScheduledEntity;
class UStationComponent;

void UMissionManager::UpdateBlueprintTaskProgressBP(const FName MissionID, const FString& missionStepNickname, const int32 ProgressIncrement, const int32 ProgressGoal) {
}

void UMissionManager::TrackUpdatedMissionBP() {
}

bool UMissionManager::StationKnownByMissionManagerBP(UStationComponent* Object) {
    return false;
}

void UMissionManager::ShouldForcePlantItemBP(const AActor* interactionActor, FString& o_itemToPlant) {
}

void UMissionManager::SetMissionLogFocusMissionBP(const FName MissionID) {
}

bool UMissionManager::SetMapCursorToMissionLocationBP(FName MissionID) {
    return false;
}

void UMissionManager::ResetMissionDevOnlyBP(const FName MissionID) {
}

void UMissionManager::RequestMissionUpdateBP(const FName MissionID) {
}

void UMissionManager::PlaySceneRigFinished() {
}

void UMissionManager::PlayMissionFromFrontEnd(const FString& MissionName, const FString& Gender, const FString& SkipOption) {
}

void UMissionManager::PlayMissionDevOnlyBP(const FName MissionID) {
}

void UMissionManager::OnStartNewDay() {
}

void UMissionManager::OnPreGameSave() {
}

void UMissionManager::OnPostGameSave() {
}

void UMissionManager::OnPostGameLoad() {
}

void UMissionManager::MarkMissionAsViewed(const FName& MissionName) {
}

bool UMissionManager::IsNewMission(const FName MissionName) {
    return false;
}

bool UMissionManager::IsFocusMissionBP(const FName MissionID, FName CharacterID) {
    return false;
}

void UMissionManager::HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta) {
}

void UMissionManager::HandleSceneRigFadeOutComplete(const UObject* i_caller, int32 Value) {
}

void UMissionManager::HandleSceneRigFadeOut(const UObject* i_caller, int32 Value) {
}

void UMissionManager::HandlePerformTasksDone(const APerformTasksForAI* InPerformTasksForAI) {
}

void UMissionManager::HandleMissionEditorMessage(const UObject* i_caller, const FString& Message) {
}

void UMissionManager::HandleHighPriorityStreamingComplete() {
}

void UMissionManager::HandleGiftingBP(const FName CharacterID, const FString& ItemId, const int32 ItemCount) {
}

void UMissionManager::HandleFleshCreated(AActor* InActor, UScheduledEntity* InScheduledEntity) {
}

void UMissionManager::HandleExperienceLevelChanged(const int32 ExpLevel, bool bIndicateHUD) {
}

void UMissionManager::GetNewlyHilitedSpell(FString& Spell) {
}

bool UMissionManager::GetMissionStepCompletedBP(const FName MissionID, const FString& StepNickname) {
    return false;
}

FString UMissionManager::GetMissionStepBP(const FName MissionID) {
    return TEXT("");
}

TEnumAsByte<MissionStatus> UMissionManager::GetMissionStatusBP(const FName MissionID) {
    return MISSION_STATUS_PREACTIVE;
}

TArray<FString> UMissionManager::GetMissionSkipOptions(const FString& MissionName) {
    return TArray<FString>();
}

FName UMissionManager::GetMissionName(const FDatabaseMissionList DatabaseMissionList) {
    return NAME_None;
}

TArray<FMissionLogData> UMissionManager::GetMissionLogDataSingleBP(const int32 missionIndex) {
    return TArray<FMissionLogData>();
}

TArray<FMissionLogData> UMissionManager::GetMissionLogDataBP(int32& OutTrackedMissionIndex) {
    return TArray<FMissionLogData>();
}

bool UMissionManager::GetMissionBeaconWorldLocationBP(FName MissionID, FVector& WorldLocation) {
    return false;
}

UBeaconInfo* UMissionManager::GetMissionBeaconBP(FName MissionID) {
    return NULL;
}

TArray<FString> UMissionManager::GetFrontEndMissionList(int32& StartIndex) {
    return TArray<FString>();
}

UMissionManager* UMissionManager::Get() {
    return NULL;
}

void UMissionManager::DismissMissionLogBP() {
}

void UMissionManager::CompleteBlueprintConditionBP(const FName MissionID, const FString& missionStepNickname) {
}

void UMissionManager::CheckMissionRestriction(const FString& restrictionType, const FString& restrictionValue, FRestrictionInfo& ioRestrictionInfo, bool& o_canSpawn) {
}

bool UMissionManager::AutomationBlocksDungeonLoad(const FName DungeonName) {
    return false;
}

void UMissionManager::AbandonMissionBP() {
}

UMissionManager::UMissionManager() {
    this->InteractionManager = NULL;
}

