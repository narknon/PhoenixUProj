#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HermesBPDelegateHandle.h"
#include "EMissionComplete.h"
#include "EMissionStatus.h"
#include "MissionID.h"
#include "MissionBPLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class UMissionBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesMissionIDDelegate, const UObject*, Caller, const FMissionID&, MissionID);
    
    UMissionBPLibrary();
    UFUNCTION(BlueprintCallable)
    static void UpdateMissionProgress(const FMissionID MissionID, const FString& StepName, const int32 ProgressIncrement, const int32 ProgressGoal);
    
    UFUNCTION(BlueprintCallable)
    static void TrackMission(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void ResetMissionDevOnly(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void RequestMissionUpdates(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void PrintMissionString(const FMissionID MissionID, const FString& inString);
    
    UFUNCTION(BlueprintCallable)
    static void PlayMissionDevOnly(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFocusMission(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsExclusiveMissionActive();
    
    UFUNCTION(BlueprintCallable)
    static bool IsExclusiveMission(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteOwned_MissionID(const FString& Name, const UObject* Owner, const UObject* Caller, const FMissionID& MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void HermesExecuteAll_MissionID(const FString& Name, const UObject* Caller, const FMissionID& MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBind_MissionID(UMissionBPLibrary::FHermesMissionIDDelegate Delegate_MissionID, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static bool GetMissionStepComplete(const FMissionID MissionID, const FString& StepName);
    
    UFUNCTION(BlueprintCallable)
    static EMissionStatus GetMissionStatus(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static bool GetMissionComplete(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static FString GetCurrentMissionStepName(const FMissionID MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void CompleteMissionTask(const FMissionID MissionID, const FString& StepName);
    
    UFUNCTION(BlueprintCallable)
    static void BranchMissionStepComplete(const FMissionID MissionID, const FString& StepName, EMissionComplete& Complete);
    
    UFUNCTION(BlueprintCallable)
    static void BranchMissionStatus(const FMissionID MissionID, EMissionStatus& Status);
    
    UFUNCTION(BlueprintCallable)
    static void BranchMissionComplete(const FMissionID MissionID, EMissionComplete& Complete);
    
    UFUNCTION(BlueprintCallable)
    static void BindMissionUpdates(const FMissionID MissionID, UMissionBPLibrary::FHermesMissionIDDelegate Delegate_MissionID, FHermesBPDelegateHandle& Handle);
    
};

