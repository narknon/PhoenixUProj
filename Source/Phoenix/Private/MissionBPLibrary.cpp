#include "MissionBPLibrary.h"

class UObject;

void UMissionBPLibrary::UpdateMissionProgress(const FMissionID MissionID, const FString& StepName, const int32 ProgressIncrement, const int32 ProgressGoal) {
}

void UMissionBPLibrary::TrackMission(const FMissionID MissionID) {
}

void UMissionBPLibrary::ResetMissionDevOnly(const FMissionID MissionID) {
}

void UMissionBPLibrary::RequestMissionUpdates(const FMissionID MissionID) {
}

void UMissionBPLibrary::PrintMissionString(const FMissionID MissionID, const FString& inString) {
}

void UMissionBPLibrary::PlayMissionDevOnly(const FMissionID MissionID) {
}

bool UMissionBPLibrary::IsFocusMission(const FMissionID MissionID) {
    return false;
}

bool UMissionBPLibrary::IsExclusiveMissionActive() {
    return false;
}

bool UMissionBPLibrary::IsExclusiveMission(const FMissionID MissionID) {
    return false;
}

void UMissionBPLibrary::HermesExecuteOwned_MissionID(const FString& Name, const UObject* Owner, const UObject* Caller, const FMissionID& MissionID) {
}

void UMissionBPLibrary::HermesExecuteAll_MissionID(const FString& Name, const UObject* Caller, const FMissionID& MissionID) {
}

void UMissionBPLibrary::HermesBind_MissionID(UMissionBPLibrary::FHermesMissionIDDelegate Delegate_MissionID, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

bool UMissionBPLibrary::GetMissionStepComplete(const FMissionID MissionID, const FString& StepName) {
    return false;
}

EMissionStatus UMissionBPLibrary::GetMissionStatus(const FMissionID MissionID) {
    return EMissionStatus::PreActive;
}

bool UMissionBPLibrary::GetMissionComplete(const FMissionID MissionID) {
    return false;
}

FString UMissionBPLibrary::GetCurrentMissionStepName(const FMissionID MissionID) {
    return TEXT("");
}

void UMissionBPLibrary::CompleteMissionTask(const FMissionID MissionID, const FString& StepName) {
}

void UMissionBPLibrary::BranchMissionStepComplete(const FMissionID MissionID, const FString& StepName, EMissionComplete& Complete) {
}

void UMissionBPLibrary::BranchMissionStatus(const FMissionID MissionID, EMissionStatus& Status) {
}

void UMissionBPLibrary::BranchMissionComplete(const FMissionID MissionID, EMissionComplete& Complete) {
}

void UMissionBPLibrary::BindMissionUpdates(const FMissionID MissionID, UMissionBPLibrary::FHermesMissionIDDelegate Delegate_MissionID, FHermesBPDelegateHandle& Handle) {
}

UMissionBPLibrary::UMissionBPLibrary() {
}

