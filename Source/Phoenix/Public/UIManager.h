#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EGenderEnum.h"
#include "GameFramework/PlayerInput.h"
#include "InputGroupHeader.h"
#include "InputCoreTypes.h"
#include "AsyncScreenLoadCallbackDelegate.h"
#include "ClosePauseMenuCompleteCallbackDelegate.h"
#include "EAvatarPresetType.h"
#include "EDisciplineType.h"
#include "EFactsheetButtonState.h"
#include "EFieldGuideExitReasons.h"
#include "EGamepadType.h"
#include "EInputDeviceUsed.h"
#include "EPauseMenuPage.h"
#include "ETutorialPosition.h"
#include "EUIDisplayMode.h"
#include "EUIFactsheetMode.h"
#include "EUIGameOverReason.h"
#include "EUIPlatformInputDevice.h"
#include "EUIPopupPriority.h"
#include "EWidgetType.h"
#include "HouseIds.h"
#include "InputActionHoldInfo.h"
#include "LegendItemData.h"
#include "MastermindPopupInfo.h"
#include "MastermindScreenInfo.h"
#include "MastermindTutorialInfo.h"
#include "MenuReaderVoice.h"
#include "OnFloatingGamepadTextInputClosedDelegate.h"
#include "OnGamepadTextInputClosedDelegate.h"
#include "OnLoadScreenDismissedDelegate.h"
#include "OnPSOUpdateDelegate.h"
#include "RPGUIInfo.h"
#include "UIManager.generated.h"

class AActor;
class APawn;
class APhoenixPathActor;
class APlayerController;
class UAvatarPresetDefinition;
class UBeaconInfo;
class UDataTable;
class UFieldGuideMenu;
class UInGameMenuScreen;
class UMapDungeon;
class UMapHogsmeade;
class UMapHogwarts;
class UMapOverland;
class UMapSubSystem;
class UMenuCursorWidget;
class UMissionFailScreenBase;
class UPhoenixNotificationManager;
class UPopupScreen;
class UScreen;
class UScreenFadeWidget;
class UTexture2D;
class UTutorialSystem;
class UUIInputManager;
class UUIManager;
class UUserWidget;
class UWorld;
class UWorldSupportLevel;
class UWorldSupportWorld;

UCLASS(Blueprintable)
class PHOENIX_API UUIManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TargetUITable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhoenixNotificationManager* NotificationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTutorialSystem* TutorialSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ErrorTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* LoadingTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIDisplayMode UIDisplayMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CompendiumCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CompendiumItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LastVisitedMenuPage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalParallaxMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NextExpGainDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LastLocationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum DefaultGenderRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultMalePreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultFemalePreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAvatarPresetType, TSoftObjectPtr<UAvatarPresetDefinition>> LastChosenPresetData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* PauseWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* FieldGuideWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* VendorWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* CompanionWorld;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UScreen* CompanionSelectScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerController* GamePlayerController;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadScreenDismissed OnLoadScreenDismissed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClosePauseMenuCompleteCallback OnPauseMenuClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CastStupefyWithRightTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapOverland* OverlandMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* InteractWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PauseRequesters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* mUIScreenFadeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EPauseMenuPage> HiddenMenuPages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapDungeon* DungeonMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogwarts* HogwartsMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogsmeade* HogsmeadeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* InGameMenuWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* FieldGuideWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInGameMenuScreen* InGameMenuWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFieldGuideMenu* FieldGuideWidget;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UClass* PopupScreenClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRichPaperShowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixPathActor* PathActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor PauseMenuLEDColor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUIInputManager* InputManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> AlwaysLoadedTextures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UScreenFadeWidget* m_pScreenFadeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMissionFailScreenBase* MissionFailedScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconInfo* CompanionBeaconInfo;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPSOUpdate OnPSOUpdate;
    
public:
    UUIManager();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WidgetClassLoaded(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FMenuReaderVoice ValidateMenuReaderVoice(const FMenuReaderVoice InVoice);
    
    UFUNCTION(BlueprintCallable)
    void UseHoverDrone();
    
    UFUNCTION(BlueprintCallable)
    void UpdateHintGameLogic(FName GameLogicVar, bool SetOn);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdateFSKnownItemsDetailMap(const FString& FactItem, const FString& FactAttribute, EFactsheetButtonState FactState);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UpdateAllFastTravelLocations();
    
    UFUNCTION(BlueprintCallable)
    void UnpauseLocationNameUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllPauseMenuTabs();
    
    UFUNCTION(BlueprintCallable)
    void UnloadFieldGuideScreen();
    
    UFUNCTION(BlueprintCallable)
    static bool UnbindMKBAxis(const FInputAxisKeyMapping& InAxisMapping, bool bForceRebuildKeymaps, bool bTranspose);
    
    UFUNCTION(BlueprintCallable)
    static bool UnbindMKBAction(const FInputActionKeyMapping& InActionMapping, bool bForceRebuildKeymaps, bool bTranspose);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UITriggerLevelLoad();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UIManager_ToggleShowCurentLevelName();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UIBuildNavMeshData();
    
    UFUNCTION(BlueprintCallable)
    void TriggerGamepadTextInput(FOnGamepadTextInputClosed InCallback, FText InTextDescription, int32 InMaxCharacters, const FString& InDefaultText);
    
    UFUNCTION(BlueprintCallable)
    void TriggerFadeOut();
    
    UFUNCTION(BlueprintCallable)
    void TriggerFadeIn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FInputAxisKeyMapping> TransposeAxisToQWERTY(const TArray<FInputAxisKeyMapping>& AxisMappings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FInputAxisKeyMapping> TransposeAxisFromQWERTY(const TArray<FInputAxisKeyMapping>& AxisMappings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FInputActionKeyMapping> TransposeActionToQWERTY(const TArray<FInputActionKeyMapping>& ActionMappings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FInputActionKeyMapping> TransposeActionFromQWERTY(const TArray<FInputActionKeyMapping>& ActionMappings);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TogglePathActive();
    
    UFUNCTION(BlueprintCallable)
    void ToggleMenuTab(EPauseMenuPage MenuPage, bool ShouldShow);
    
    UFUNCTION(BlueprintCallable)
    void ToggleHUD(bool Enable, bool AllowSelectiveTicking);
    
    UFUNCTION(BlueprintCallable)
    bool TargetWidgetSetup(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void TargetComponentWidget(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void StopVendorWorld();
    
    UFUNCTION(BlueprintCallable)
    void StopCompanionWorld();
    
    UFUNCTION(BlueprintCallable)
    void StartVendorWorld();
    
    UFUNCTION(BlueprintCallable)
    void StartCompanionWorld();
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowYesNoPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress);
    
    UFUNCTION(BlueprintCallable)
    void ShowVirtualCursor(APlayerController* Controller, bool Enable, FVector2D Position, const FString& Context);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ShowRoadsInWorld();
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowPleaseWaitPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress);
    
    UFUNCTION(BlueprintCallable)
    void ShowPathSelectionReleased();
    
    UFUNCTION(BlueprintCallable)
    void ShowPathSelectionPressed();
    
    UFUNCTION(BlueprintCallable)
    void ShowPathSelectionCancelled();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ShowPathInWorld();
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowOkPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress, int32 ZOrder);
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowOkCancelPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress);
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowGenericPopup(const FString& TitleString, const FString& DescriptionString, const TArray<FLegendItemData>& LegendItems, const TArray<FInputActionHoldInfo>& CompletionActions, const bool bUsesWaitIndicator, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress, int32 ZOrder);
    
    UFUNCTION(BlueprintCallable)
    void ShowFloatingGamepadTextInput(FOnFloatingGamepadTextInputClosed InCallback, bool ShowOnTop);
    
    UFUNCTION(BlueprintCallable)
    static void SetUIDisplayMode(EUIDisplayMode DisplayMode);
    
    UFUNCTION(BlueprintCallable)
    void SetToMapFromBackButton(bool pToMapFromBackButton);
    
    UFUNCTION(BlueprintCallable)
    void SetTempPauseLock(bool pTempPauseLock);
    
    UFUNCTION(BlueprintCallable)
    static bool SetStudentLocatorBeacon(const FString& StudentName);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerPawn(APawn* Pawn);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerInventorySortPreference(const FString& Preference);
    
    UFUNCTION(BlueprintCallable)
    bool SetPlayerHouseEnum(TEnumAsByte<HouseIds> House);
    
    UFUNCTION(BlueprintCallable)
    bool SetPlayerHouse(const FString& HouseName);
    
    UFUNCTION(BlueprintCallable)
    bool SetPlayerGender(const FString& Gender);
    
    UFUNCTION(BlueprintCallable)
    bool SetPlayerFirstAndLastName(const FString& PlayerFirstName, const FString& PlayerLastName);
    
    UFUNCTION(BlueprintCallable)
    bool SetPlayerChosenWandInfo(const FString& WandStyle, const FString& WandWood, const FString& WandCore, const FString& WandLength, const FString& WandFlex);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMKBAxis(const FInputAxisKeyMapping& InAxisMapping, bool bIsPrimary, bool bForceRebuildKeymaps, bool bTranspose);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMKBAction(const FInputActionKeyMapping& InActionMapping, bool bIsPrimary, bool bForceRebuildKeymaps, bool bTranspose);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMenuReaderVolume(const float InVolume);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMenuReaderVoice(const FMenuReaderVoice InVoice);
    
    UFUNCTION(BlueprintCallable)
    static bool SetMenuReaderEnabled(const bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetManualFade(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    static bool SetLocatorBeaconUsingType(const FString& Type, const FString& NameOrLocation);
    
    UFUNCTION(BlueprintCallable)
    static bool SetLocatorBeaconUsingDBLocation(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetLocatorBeaconUsingDBDungeonEntrances(const FString& LocationID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetLocatorBeacon(const FString& StudentName, FVector Location, const FString& BeaconIconName);
    
    UFUNCTION(BlueprintCallable)
    void SetLocationName(FName LocationName, bool ShowNotification);
    
    UFUNCTION(BlueprintCallable)
    void SetLoadingSaveGame(bool pLoadingSaveGame);
    
    UFUNCTION(BlueprintCallable)
    void SetIsRichPaperShowing(bool Showing);
    
    UFUNCTION(BlueprintCallable)
    void SetInPreGameplayState(const bool InPreGameplayState);
    
    UFUNCTION(BlueprintCallable)
    void SetInMenuTransitionWithDelay(bool pInMenuTransition, float Delay, const FString& pContext);
    
    UFUNCTION(BlueprintCallable)
    void SetInMenuTransition(bool pInMenuTransition, const FString& pContext);
    
    UFUNCTION(BlueprintCallable)
    void SetInFrontendLevel(const bool bInFrontend);
    
    UFUNCTION(BlueprintCallable)
    void SetInDarkArtsChallenge(bool InDA);
    
    UFUNCTION(BlueprintCallable)
    void SetHiddenMenuTabs(TArray<EPauseMenuPage> PagesToHide);
    
    UFUNCTION(BlueprintCallable)
    static void SetFactsheetMode(EUIFactsheetMode NewFactsheetMode);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugLoadingScreen(const bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    static void SetCursorWidget(UMenuCursorWidget* NewCursor);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionSelectionScreen(UScreen* InScreen);
    
    UFUNCTION(BlueprintCallable)
    void SetCastStupefyWithRightTrigger(bool UseRT);
    
    UFUNCTION(BlueprintCallable)
    void SetCanBackOutOfAvatarCreator(const bool bCanBackOut);
    
    UFUNCTION(BlueprintCallable)
    void SetAsyncScreenLoadInProgress(bool InProgress);
    
    UFUNCTION(BlueprintCallable)
    void SetAndShowHintMessage(const FString& HintKey, const ETutorialPosition HintPosition, const bool bIgnoreShowTutorialElementsFlag, const float MaxDuration);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveMenu(FName MenuToLoad, bool LoadToSubPage, bool LockToMenu);
    
    UFUNCTION(BlueprintCallable)
    void SelectButton();
    
    UFUNCTION(BlueprintCallable)
    static bool SaveInputConfig();
    
    UFUNCTION(BlueprintCallable)
    void RevelioPageScreenLoaded(UScreen* Screen);
    
    UFUNCTION(BlueprintCallable)
    void ReturnToStartPage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString ResolveOptionPanelChoice(const FString& DialogueLine);
    
    UFUNCTION(BlueprintCallable)
    void RequestGameAndSystemPause(bool bPause, const FName RequesterName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTargetComponentWidget(const AActor* Target, bool TargetDied);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveStudentLocatorBeacon();
    
    UFUNCTION(BlueprintCallable)
    void RemoveInteractComponentWidget(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAlertComponentWidget(const AActor* Target, EWidgetType WidgetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString PhoenixTranslate(const FString& Key, const FString& DebugLogText);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool PhoenixKeyExists(const FString& Key);
    
    UFUNCTION(BlueprintCallable)
    void PauseLocationNameUI();
    
    UFUNCTION(BlueprintCallable)
    void PathSelectionTimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void OnVendorLevelUnload(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnVendorLevelShow(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnVendorLevelLoad(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(EInputDeviceUsed UsedInputDevice, FKey InputPressed);
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    void OnFieldGuideUnload(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnFieldGuideShow(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnFieldGuideLoad(UWorldSupportLevel* Level);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnFadeInComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnControlSchemaChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionLevelUnload(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionLevelShow(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionLevelLoad(UWorldSupportLevel* Level);
    
    UFUNCTION(BlueprintCallable)
    void MoviePlaybackFinished(UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void MissionFailScreenLoaded(UScreen* Screen);
    
    UFUNCTION(BlueprintCallable)
    void LoadFieldGuideScreen();
    
    UFUNCTION(BlueprintCallable)
    void KeepLoadScreenUp();
    
    UFUNCTION(BlueprintCallable)
    bool IsVendorInteract(FName Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingXboxOneController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingSwitchController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingSteamController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingPS5Controller();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingPS4Controller();
    
    UFUNCTION(BlueprintCallable)
    static bool IsStudentLocatorBeaconActive(const FString& StudentName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSteamRunningOnSteamDeck() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSteamInBigPictureMode() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsPopupReady();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPauseRequestedBy(const FName RequesterName) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsNabSackAlreadyEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMenuTabHidden(EPauseMenuPage MenuTab);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMenuReaderSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMenuReaderEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMenuReaderCurrentLanguageSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMenuReaderBusy();
    
    UFUNCTION(BlueprintCallable)
    bool IsItemNew(const FName CategoryName, const FName ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInPreGameplayState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInFrontendLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGamepadTypeConnected(TEnumAsByte<EGamepadType> GamepadType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFaded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDebugLoadingScreen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAxisKeyValid(const FInputAxisKeyMapping& InAxisMapping);
    
    UFUNCTION(BlueprintCallable)
    bool IsAsyncScreenLoadInProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActionKeyValid(const FInputActionKeyMapping& InActionMapping);
    
    UFUNCTION(BlueprintCallable)
    void InteractComponentWidget(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    bool InPauseMode();
    
    UFUNCTION(BlueprintCallable)
    bool InFieldGuideMenuTransition();
    
    UFUNCTION(BlueprintCallable)
    bool InDarkArtsChallenge();
    
private:
    UFUNCTION(BlueprintCallable)
    void IconTextureLoadedCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetVendorWorldPreviewActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EUIPlatformInputDevice GetUIPlatformInputDevice();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UUIManager* GetUIManagerPure();
    
    UFUNCTION(BlueprintCallable)
    bool GetToMapFromBackButton();
    
    UFUNCTION(BlueprintCallable)
    bool GetTempPauseLock();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<HouseIds> GetSortingHatRecommendedHouse();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShouldShowButtonGraphics();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UScreenFadeWidget* GetScreenFadeWidget();
    
    UFUNCTION(BlueprintCallable)
    float GetPSOProgress();
    
    UFUNCTION(BlueprintCallable)
    int32 GetPlayerYear(EDisciplineType Discipline);
    
    UFUNCTION(BlueprintCallable)
    APawn* GetPlayerPawn();
    
    UFUNCTION(BlueprintCallable)
    FString GetPlayerName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerInventorySortPreference() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<HouseIds> GetPlayerHouseEnum();
    
    UFUNCTION(BlueprintCallable)
    FString GetPlayerHouse();
    
    UFUNCTION(BlueprintCallable)
    FString GetPlayerGender();
    
    UFUNCTION(BlueprintCallable)
    void GetPlayerFirstAndLastName(FString& PlayerFirstName, FString& PlayerLastName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerChosenWandInfo(FString& WandStyle, FString& WandWood, FString& WandCore, FString& WandLength, FString& WandFlex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FInputGroupHeader> GetPCInputGroupHeaders(bool bAction, bool bAxis);
    
    UFUNCTION(BlueprintCallable)
    UMapOverland* GetOverlandMap();
    
    UFUNCTION(BlueprintCallable)
    void GetNewIndicatorCategory(const FName CategoryName, TArray<FName>& NewIndicatorItems);
    
    UFUNCTION(BlueprintCallable)
    int32 GetNewFactCount();
    
    UFUNCTION(BlueprintCallable)
    static bool GetMutatedMKBAxisMappingsByName(const FName& AxisName, const TArray<FKey>& ForbiddenKeys, FInputAxisKeyMapping& OutPosMain, FInputAxisKeyMapping& OutFakePosMain, FInputAxisKeyMapping& OutPosAlt, FInputAxisKeyMapping& OutNegMain, FInputAxisKeyMapping& OutFakeNegMain, FInputAxisKeyMapping& OutNegAlt, bool bTranspose);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetMKBAxisPairsByName(const FName& AxisName, FInputAxisKeyMapping& OutPositivePrimary, FInputAxisKeyMapping& OutPositiveAlternative, FInputAxisKeyMapping& OutNegativePrimary, FInputAxisKeyMapping& OutNegativeAlternative, bool bTranspose);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetMKBActionPairByName(const FName ActionName, FInputActionKeyMapping& OutPrimary, FInputActionKeyMapping& OutAlternative, bool bTranspose);
    
    UFUNCTION(BlueprintCallable)
    bool GetMastermindTutorialInfo(FMastermindTutorialInfo& outMastermindTutorialInfo);
    
    UFUNCTION(BlueprintCallable)
    bool GetMastermindScreenInfo(FMastermindScreenInfo& outMastermindScreenInfo);
    
    UFUNCTION(BlueprintCallable)
    bool GetMastermindPopupInfo(FMastermindPopupInfo& outMastermindPopupInfo);
    
    UFUNCTION(BlueprintCallable)
    UMapSubSystem* GetMapSubSystem();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EInputDeviceUsed GetLastUsedInputDevice() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetKeyIdsFromActionId(const FString& ActionId, TArray<FString>& OutKeyIds, bool Transpose, bool ForceGamepadKeys, bool ForceMouseKeyboardKeys);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsVirtualCursorShowing();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsUIShown();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsRichPaperShowing();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsInitialized();
    
    UFUNCTION(BlueprintCallable)
    bool GetInMenuTransition();
    
    UFUNCTION(BlueprintCallable)
    UInGameMenuScreen* GetInGameMenuWidget();
    
    UFUNCTION(BlueprintCallable)
    UMapHogwarts* GetHogwartsMap();
    
    UFUNCTION(BlueprintCallable)
    UMapHogsmeade* GetHogsmeadeMap();
    
    UFUNCTION(BlueprintCallable)
    TArray<EPauseMenuPage> GetHiddenMenuTabs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> GetGroupMappingNames(const FName GroupName, bool bAction, bool bAxis, bool bSort);
    
    UFUNCTION(BlueprintCallable)
    UFieldGuideMenu* GetFieldGuideWidget();
    
    UFUNCTION(BlueprintCallable)
    static EUIFactsheetMode GetFactsheetMode();
    
    UFUNCTION(BlueprintCallable)
    UMapDungeon* GetDungeonMap();
    
    UFUNCTION(BlueprintCallable)
    FString GetDisplayedUserTag();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UMenuCursorWidget* GetCursorWidget();
    
    UFUNCTION(BlueprintCallable)
    UWorld* GetCurrentWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UScreen* GetCompanionSelectionScreen();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetCallOutComponentTarget(const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    FString GetBuildNumber();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAxisMappingByName(const FName AxisName, TArray<FInputAxisKeyMapping>& OutMappings, bool bTranspose, bool bMouseAndKeyboardOnly, bool bIncludeUnbound);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FMenuReaderVoice> GetAvailableVoices();
    
    UFUNCTION(BlueprintCallable)
    TArray<FRPGUIInfo> GetActiveBuffData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetActionMappingByName(const FName ActionName, TArray<FInputActionKeyMapping>& OutMappings, bool bTranspose, bool bMouseAndKeyboardOnly, bool bIncludeUnbound);
    
    UFUNCTION(BlueprintCallable)
    static UUIManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void GameOverScreenLoaded(UScreen* Screen);
    
    UFUNCTION(BlueprintCallable)
    static void ForceRebuildKeyMapsFromQWERTY();
    
    UFUNCTION(BlueprintCallable)
    void FieldGuideMenuStart();
    
    UFUNCTION(BlueprintCallable)
    void FadeOutToColor(float Duration, FLinearColor TargetColor);
    
    UFUNCTION(BlueprintCallable)
    void FadeOut(float Duration);
    
    UFUNCTION(BlueprintCallable)
    void FadeIn(float Duration);
    
    UFUNCTION(BlueprintCallable)
    void ExitFieldGuideWithReason(EFieldGuideExitReasons ExitReason, bool SkipFadeScreen, int32 CharacterID, const FString& Filename, const FString& FastTravelName);
    
    UFUNCTION(BlueprintCallable)
    void DropLoadScreen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesRightTriggerCastStupefy();
    
    UFUNCTION(BlueprintCallable)
    void DestroyVendorWorld();
    
    UFUNCTION(BlueprintCallable)
    void DestroyCompanionrWorld();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTriggerCollectionObtainedNotification(FName CollectionID, FName CollectionCategory);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTriggerCollectionKnownNotification(FName CollectionID, FName CollectionCategory);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTriggerChallengeUpdatedNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedAmt, int32 TotalRequired);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTriggerChallengeUnlockedNotification(FName ChallengeID, FName ChallengeCategory, int32 TotalRequired);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTriggerChallengeCompleteNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedLevel, int32 TotalLevels, int32 TotalInstancesForLevel);
    
    UFUNCTION(BlueprintCallable)
    void CycleControlModeInputCheck1();
    
    UFUNCTION(BlueprintCallable)
    void CreateHUDLog(bool pShow, const FString& Group, const FString& pContext);
    
    UFUNCTION(BlueprintCallable)
    void CreateGameOverScreen(EUIGameOverReason Reason);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateAsyncWidget(TSoftClassPtr<UScreen> ObjectPtr, const FAsyncScreenLoadCallback& AsyncLoadCallback, bool AddToViewport);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void CorrectInputAxisKeyIfNeeded(const FInputAxisKeyMapping& InInputAxisMapping, FInputAxisKeyMapping& OutInputAxisMapping);
    
    UFUNCTION(BlueprintCallable)
    void ClearPauseMenuPageBP();
    
    UFUNCTION(BlueprintCallable)
    void ClearPath();
    
    UFUNCTION(BlueprintCallable)
    void ClearNewIndicatorItem(const FName CategoryName, const FName ItemName);
    
    UFUNCTION(BlueprintCallable)
    void ClearNewIndicatorCategory(const FName CategoryName);
    
    UFUNCTION(BlueprintCallable)
    void ClearHintMessage();
    
    UFUNCTION(BlueprintCallable)
    void ClearCurrentLocationName();
    
    UFUNCTION(BlueprintCallable)
    void ChangeMenuPage();
    
    UFUNCTION(BlueprintCallable)
    void ChallengeResultsScreenLoaded(UScreen* Screen);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlayIntroNormally();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBackOutOfAvatarCreator();
    
    UFUNCTION(BlueprintCallable)
    void BuildNavPointsUsingActors(const TArray<AActor*>& Actors, float Width, float Height);
    
    UFUNCTION(BlueprintCallable)
    void AppendNavPointsUsingActors(const TArray<AActor*>& Actors);
    
    UFUNCTION(BlueprintCallable)
    void AnimateTrackingInfo();
    
    UFUNCTION(BlueprintCallable)
    void AlertComponentWidget(const AActor* Target, EWidgetType WidgetType);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceTime(FTimespan DeltaTimeAdvance);
    
    UFUNCTION(BlueprintCallable)
    static void AddTextTickerNotification(const FString& NotificationText);
    
    UFUNCTION(BlueprintCallable)
    void AddPathStartEnd(FVector Start, FVector End, float Width, float Height);
    
    UFUNCTION(BlueprintCallable)
    void AddPathPoints(const TArray<FVector>& PathPoints, float Width, float Height);
    
    UFUNCTION(BlueprintCallable)
    void AddPathEnd(FVector End, float Width, float Height);
    
    UFUNCTION(BlueprintCallable)
    void AddNewIndicatorItem(const FName CategoryName, const FName ItemName);
    
    UFUNCTION(BlueprintCallable)
    void AddNavPathPoints(const TArray<FVector>& PathPoints, float Width, float Height);
    
};

