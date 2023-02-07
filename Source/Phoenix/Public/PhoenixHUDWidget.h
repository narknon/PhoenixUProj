#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "ExperienceChange.h"
#include "MailEntry.h"
#include "TutorialLayoutData.h"
#include "PhoenixHUDWidget.generated.h"

class AActor;
class AFlyingBroom;
class UCanvasPanel;
class UCanvasPanelSlot;
class UComboHelperHud;
class UCreature_MountComponent;
class UHUDCompassIcon;
class UMissionBannerWidget;
class UObject;
class UReticule;
class UZoneNotification;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UPhoenixHUDWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* LockOnReticlePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CapturingWidgetPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UZoneNotification* HUD_ZoneNotification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UComboHelperHud* ComboHelperHud;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReticule* Reticule;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ConjurationIntroType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TransfigurationIntroType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeaconMinVertElevationDistMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeaconMaxHorizElevationDistMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeaconElevationBufferMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinVisibleBeaconTextDistMeters;
    
public:
    UPhoenixHUDWidget();
    UFUNCTION(BlueprintCallable)
    bool WorldToViewport(FVector WorldPos, FVector2D& o_Point, bool LockToViewableSpace);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateOutOfAreaAlertTimer(float Time);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TogglePersistentStepBanner(bool IsPersistent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleMissionDetailsHold(bool IsHeld);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SyncSettingsVisibilities();
    
    UFUNCTION(BlueprintCallable)
    void ShowZoneNotification(FName Header_Name, FName Label_Name, FName Image_Left, FName Image_Right, float duration_seconds, bool PlaySound);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowTransformationUI(bool Show, const int32 IntroType);
    
    UFUNCTION(BlueprintCallable)
    void ShowSpellBar(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowOutOfAreaAlert(FName Message, float InitialTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowNotificationsHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowNoFlyHUD(const FName& ErrorMessageKey);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowMountHUD(UCreature_MountComponent* MountComponent, bool bIncludeCharge);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowCreatureNurturingHUD(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowCreatureCaptureHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowConjurationUI(bool Show, const int32 IntroType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBroomRaceHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBroomHUD(AFlyingBroom* BroomActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetHudElementVisibility(const FString& ElementName, ESlateVisibility NewVisibility, UObject* Provider);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetGlobalHudVisibility(bool ShouldShow, bool AllowTicking, bool ShouldAnimate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCurrentTargetActor(const AActor* Target, bool ShowName, bool ShowHealth);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAndShowHintMessage(const FString& HintKey, FTutorialLayoutData HintPositionData, const bool bIgnoreShowTutorialElementsFlag, const float MaxDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveBeaconFromHUD(UHUDCompassIcon* Beacon);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReadActiveOwlMail();
    
    UFUNCTION(BlueprintCallable)
    void OverrideSpellBar();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowSpellBar(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowEnemyInfo(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetHUDVisibility();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetEnemyData(const FName& Name, float pct);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMailRecieved(FMailEntry Entry, int32 DisplayPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddTextTickerNotification(const FString& NotificationText);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddSpecialItemNotification(const FString& Name, const FString& IconName, int32 Count, const FString& UnlockMessage);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddPickupNotification(const FString& Name, const FString& IconName, int32 Count, bool bSpecial, FName Variation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddFastTravelUnlockedNotification(const FString& Name, const FString& IconName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddCompanionLevelUpNotification(const FString& CompanionName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddCollectionObtainedNotification(FName CollectionItemID, FName CollectionCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddCollectionKnownNotification(FName CollectionItemID, FName CollectionCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddChallengeUpdatedNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedAmt, int32 TotalRequired);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddChallengeUnlockedNotification(FName ChallengeID, FName ChallengeCategory, int32 TotalRequired);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddChallengeCompleteNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedLevel, int32 TotalLevels, int32 TotalInstancesForLevel);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UHUDCompassIcon* MakeBeaconIcon(const FString& IconName);
    
public:
    UFUNCTION(BlueprintCallable)
    void HideZoneNotification();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideOutOfAreaAlert();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideNotificationsHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideNoFlyHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideMountHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideCreatureCaptureHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideBroomRaceHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideBroomHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UMissionBannerWidget* GetMissionBanner();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExperienceChangedBP(FExperienceChange ExperienceChangedData);
    
    UFUNCTION(BlueprintCallable)
    void ClearSpellBarOverride();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearHintMessage();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AnimateTrackingInfoWidget();
    
    UFUNCTION(BlueprintCallable)
    void AddSpecialItemNotification(const FString& Name, const FString& IconName, int32 Count, const FString& UnlockMessage);
    
    UFUNCTION(BlueprintCallable)
    void AddFastTravelUnlockedNotification(const FString& Site, const FString& IconName);
    
    UFUNCTION(BlueprintCallable)
    void AddCompanionLevelUpNotification(const UObject* i_caller, const FString& CompanionName, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void AddCollectionNotification(const FString& Name, const FString& IconName, int32 Count, bool bSpecial, FName Variation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddBeaconToHUD(UHUDCompassIcon* Beacon, UCanvasPanelSlot*& BeaconSlot);
    
};

