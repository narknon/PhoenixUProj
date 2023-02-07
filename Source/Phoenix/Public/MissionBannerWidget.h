#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BannerUpdateType.h"
#include "ENotificationCategory.h"
#include "HUDElementGroup.h"
#include "MissionBannerWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UMissionBannerWidget : public UHUDElementGroup {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StepUpdateInProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MissionStepsShowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool WaypointShowing;
    
public:
    UMissionBannerWidget();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateExistingStepBanner(const TArray<FString>& objectiveText, const TArray<bool>& objectiveChecked, const TArray<bool>& objectiveCheckChanged, const TArray<int32>& objectiveRuntimeValue1, const TArray<int32>& objectiveRuntimeValue2);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateColorBlindColors(FLinearColor ObjectiveTintColor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBPStepBanner(BannerUpdateType updateType, FName updateTitle, FName bannerText, FName bannerText2, bool bShowTrackMission, const TArray<FString>& objectiveText, const TArray<bool>& objectiveChecked, const TArray<bool>& objectiveCheckChanged, const TArray<int32>& objectiveRuntimeValue1, const TArray<int32>& objectiveRuntimeValue2, const FString& MissionDescription, const FString& MissionTypeIcon, const FString& MissionObjectiveIcon, const FLinearColor ObjectiveTintColor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBPMissionBanner(BannerUpdateType updateType, FName updateTitle, FName bannerText, FName bannerText2, bool bShowTrackMission, const TArray<FString>& objectiveText, const TArray<bool>& objectiveChecked, const TArray<bool>& objectiveCheckChanged, const TArray<int32>& objectiveRuntimeValue1, const TArray<int32>& objectiveRuntimeValue2);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBPCelebrationBanner(BannerUpdateType updateType, FName updateTitle, FName bannerText, FName bannerText2, bool bShowTrackMission, const TArray<FString>& objectiveText, const TArray<bool>& objectiveChecked, const TArray<bool>& objectiveCheckChanged, const TArray<int32>& objectiveRuntimeValue1, const TArray<int32>& objectiveRuntimeValue2);
    
    UFUNCTION(BlueprintCallable)
    void BeginOrEndPlay(const bool endPlay);
    
    UFUNCTION(BlueprintCallable)
    void BannerComplete(const ENotificationCategory Category);
    
};

