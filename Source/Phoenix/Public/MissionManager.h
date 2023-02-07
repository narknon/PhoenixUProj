#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "RestrictionInfo.h"
#include "DatabaseMissionList.h"
#include "MissionLogData.h"
#include "MissionStatus.h"
#include "MissionManager.generated.h"

class AActor;
class APerformTasksForAI;
class UBeaconInfo;
class UMissionInteractionManager;
class UMissionManager;
class UScheduledEntity;
class UStationComponent;

UCLASS(Blueprintable)
class PHOENIX_API UMissionManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMissionInteractionManager* InteractionManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName FailureReasonTextKey;
    
public:
    UMissionManager();
    UFUNCTION(BlueprintCallable)
    static void UpdateBlueprintTaskProgressBP(const FName MissionID, const FString& missionStepNickname, const int32 ProgressIncrement, const int32 ProgressGoal);
    
    UFUNCTION(BlueprintCallable)
    static void TrackUpdatedMissionBP();
    
    UFUNCTION(BlueprintCallable)
    static bool StationKnownByMissionManagerBP(UStationComponent* Object);
    
    UFUNCTION(BlueprintCallable)
    static void ShouldForcePlantItemBP(const AActor* interactionActor, FString& o_itemToPlant);
    
    UFUNCTION(BlueprintCallable)
    static void SetMissionLogFocusMissionBP(const FName MissionID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMapCursorToMissionLocationBP(FName MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void ResetMissionDevOnlyBP(const FName MissionID);
    
    UFUNCTION(BlueprintCallable)
    static void RequestMissionUpdateBP(const FName MissionID);
    
private:
    UFUNCTION(BlueprintCallable)
    void PlaySceneRigFinished();
    
    UFUNCTION(BlueprintCallable)
    static void PlayMissionFromFrontEnd(const FString& MissionName, const FString& Gender, const FString& SkipOption);
    
public:
    UFUNCTION(BlueprintCallable)
    static void PlayMissionDevOnlyBP(const FName MissionID);
    
    UFUNCTION(BlueprintCallable)
    void OnStartNewDay();
    
    UFUNCTION(BlueprintCallable)
    void OnPreGameSave();
    
    UFUNCTION(BlueprintCallable)
    void OnPostGameSave();
    
    UFUNCTION(BlueprintCallable)
    void OnPostGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void MarkMissionAsViewed(const FName& MissionName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsNewMission(const FName MissionName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFocusMissionBP(const FName MissionID, FName CharacterID);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    void HandleSceneRigFadeOutComplete(const UObject* i_caller, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void HandleSceneRigFadeOut(const UObject* i_caller, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void HandlePerformTasksDone(const APerformTasksForAI* InPerformTasksForAI);
    
    UFUNCTION(BlueprintCallable)
    void HandleMissionEditorMessage(const UObject* i_caller, const FString& Message);
    
    UFUNCTION(BlueprintCallable)
    void HandleHighPriorityStreamingComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    static void HandleGiftingBP(const FName CharacterID, const FString& ItemId, const int32 ItemCount);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleFleshCreated(AActor* InActor, UScheduledEntity* InScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    void HandleExperienceLevelChanged(const int32 ExpLevel, bool bIndicateHUD);
    
public:
    UFUNCTION(BlueprintCallable)
    void GetNewlyHilitedSpell(FString& Spell);
    
    UFUNCTION(BlueprintCallable)
    static bool GetMissionStepCompletedBP(const FName MissionID, const FString& StepNickname);
    
    UFUNCTION(BlueprintCallable)
    static FString GetMissionStepBP(const FName MissionID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<MissionStatus> GetMissionStatusBP(const FName MissionID);
    
private:
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetMissionSkipOptions(const FString& MissionName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetMissionName(const FDatabaseMissionList DatabaseMissionList);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FMissionLogData> GetMissionLogDataSingleBP(const int32 missionIndex);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FMissionLogData> GetMissionLogDataBP(int32& OutTrackedMissionIndex);
    
    UFUNCTION(BlueprintCallable)
    static bool GetMissionBeaconWorldLocationBP(FName MissionID, FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    static UBeaconInfo* GetMissionBeaconBP(FName MissionID);
    
private:
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetFrontEndMissionList(int32& StartIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    static UMissionManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static void DismissMissionLogBP();
    
    UFUNCTION(BlueprintCallable)
    static void CompleteBlueprintConditionBP(const FName MissionID, const FString& missionStepNickname);
    
    UFUNCTION(BlueprintCallable)
    void CheckMissionRestriction(const FString& restrictionType, const FString& restrictionValue, FRestrictionInfo& ioRestrictionInfo, bool& o_canSpawn);
    
private:
    UFUNCTION(BlueprintCallable)
    static bool AutomationBlocksDungeonLoad(const FName DungeonName);
    
public:
    UFUNCTION(BlueprintCallable)
    static void AbandonMissionBP();
    
};

