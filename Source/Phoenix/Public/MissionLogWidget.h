#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MissionLogData.h"
#include "MissionTabData.h"
#include "TabPageWidget.h"
#include "MissionLogWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UMissionLogWidget : public UTabPageWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMissionTabData> MissionTabDataSet;
    
public:
    UMissionLogWidget();
protected:
    UFUNCTION(BlueprintCallable)
    bool TrackNewObjective(const FString& ObjectiveName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionHasBeaconOnMap(FName MissionID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBeenInitialized() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTrackedMissionId(FName& MissionID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTrackedMissionData(FMissionLogData& MissionData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMissionLogData> GetMissionLogData(int32& OutTrackedMissionIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMapIconAndGlint(FName MissionID, FString& Icon, FString& Glint, FLinearColor& IconColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLighthouseGoalInfo(FName& LighthouseGoalID, TArray<FName>& LighthouseObjectives, TArray<bool>& ObjectiveUnlockedStates, TArray<bool>& ObjectiveCompleteStates) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActiveObjectiveTrackableStates(TArray<bool>& TrackableStates, FString& TrackedObjective) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAbandonMission(FName MissionID);
    
};

