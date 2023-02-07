#include "UIManager.h"

class AActor;
class APawn;
class APlayerController;
class UFieldGuideMenu;
class UInGameMenuScreen;
class UMapDungeon;
class UMapHogsmeade;
class UMapHogwarts;
class UMapOverland;
class UMapSubSystem;
class UMenuCursorWidget;
class UObject;
class UPopupScreen;
class UScreen;
class UScreenFadeWidget;
class UTexture2D;
class UUIManager;
class UUserWidget;
class UWorld;
class UWorldSupportLevel;


FMenuReaderVoice UUIManager::ValidateMenuReaderVoice(const FMenuReaderVoice InVoice) {
    return FMenuReaderVoice{};
}

void UUIManager::UseHoverDrone() {
}

void UUIManager::UpdateHintGameLogic(FName GameLogicVar, bool SetOn) {
}

bool UUIManager::UpdateFSKnownItemsDetailMap(const FString& FactItem, const FString& FactAttribute, EFactsheetButtonState FactState) {
    return false;
}

void UUIManager::UpdateAllFastTravelLocations() {
}

void UUIManager::UnpauseLocationNameUI() {
}

void UUIManager::UnlockAllPauseMenuTabs() {
}

void UUIManager::UnloadFieldGuideScreen() {
}

bool UUIManager::UnbindMKBAxis(const FInputAxisKeyMapping& InAxisMapping, bool bForceRebuildKeymaps, bool bTranspose) {
    return false;
}

bool UUIManager::UnbindMKBAction(const FInputActionKeyMapping& InActionMapping, bool bForceRebuildKeymaps, bool bTranspose) {
    return false;
}

void UUIManager::UITriggerLevelLoad() {
}

void UUIManager::UIManager_ToggleShowCurentLevelName() {
}

void UUIManager::UIBuildNavMeshData() {
}

void UUIManager::TriggerGamepadTextInput(FOnGamepadTextInputClosed InCallback, FText InTextDescription, int32 InMaxCharacters, const FString& InDefaultText) {
}

void UUIManager::TriggerFadeOut() {
}

void UUIManager::TriggerFadeIn() {
}

TArray<FInputAxisKeyMapping> UUIManager::TransposeAxisToQWERTY(const TArray<FInputAxisKeyMapping>& AxisMappings) {
    return TArray<FInputAxisKeyMapping>();
}

TArray<FInputAxisKeyMapping> UUIManager::TransposeAxisFromQWERTY(const TArray<FInputAxisKeyMapping>& AxisMappings) {
    return TArray<FInputAxisKeyMapping>();
}

TArray<FInputActionKeyMapping> UUIManager::TransposeActionToQWERTY(const TArray<FInputActionKeyMapping>& ActionMappings) {
    return TArray<FInputActionKeyMapping>();
}

TArray<FInputActionKeyMapping> UUIManager::TransposeActionFromQWERTY(const TArray<FInputActionKeyMapping>& ActionMappings) {
    return TArray<FInputActionKeyMapping>();
}

void UUIManager::TogglePathActive() {
}

void UUIManager::ToggleMenuTab(EPauseMenuPage MenuPage, bool ShouldShow) {
}

void UUIManager::ToggleHUD(bool Enable, bool AllowSelectiveTicking) {
}

bool UUIManager::TargetWidgetSetup(const AActor* Target) {
    return false;
}

void UUIManager::TargetComponentWidget(const AActor* Target) {
}

void UUIManager::StopVendorWorld() {
}

void UUIManager::StopCompanionWorld() {
}

void UUIManager::StartVendorWorld() {
}

void UUIManager::StartCompanionWorld() {
}

UPopupScreen* UUIManager::ShowYesNoPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress) {
    return NULL;
}

void UUIManager::ShowVirtualCursor(APlayerController* Controller, bool Enable, FVector2D Position, const FString& Context) {
}

void UUIManager::ShowRoadsInWorld() {
}

UPopupScreen* UUIManager::ShowPleaseWaitPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress) {
    return NULL;
}

void UUIManager::ShowPathSelectionReleased() {
}

void UUIManager::ShowPathSelectionPressed() {
}

void UUIManager::ShowPathSelectionCancelled() {
}

void UUIManager::ShowPathInWorld() {
}

UPopupScreen* UUIManager::ShowOkPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress, int32 ZOrder) {
    return NULL;
}

UPopupScreen* UUIManager::ShowOkCancelPopup(const FString& TitleString, const FString& DescriptionString, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress) {
    return NULL;
}

UPopupScreen* UUIManager::ShowGenericPopup(const FString& TitleString, const FString& DescriptionString, const TArray<FLegendItemData>& LegendItems, const TArray<FInputActionHoldInfo>& CompletionActions, const bool bUsesWaitIndicator, const bool IsDescTranslated, const bool bPausesTheGame, const UUserWidget* ContentWidget, const EUIPopupPriority PopupPriority, const bool bAutoCloseOnButtonPress, int32 ZOrder) {
    return NULL;
}

void UUIManager::ShowFloatingGamepadTextInput(FOnFloatingGamepadTextInputClosed InCallback, bool ShowOnTop) {
}

void UUIManager::SetUIDisplayMode(EUIDisplayMode DisplayMode) {
}

void UUIManager::SetToMapFromBackButton(bool pToMapFromBackButton) {
}

void UUIManager::SetTempPauseLock(bool pTempPauseLock) {
}

bool UUIManager::SetStudentLocatorBeacon(const FString& StudentName) {
    return false;
}

void UUIManager::SetPlayerPawn(APawn* Pawn) {
}

void UUIManager::SetPlayerInventorySortPreference(const FString& Preference) {
}

bool UUIManager::SetPlayerHouseEnum(TEnumAsByte<HouseIds> House) {
    return false;
}

bool UUIManager::SetPlayerHouse(const FString& HouseName) {
    return false;
}

bool UUIManager::SetPlayerGender(const FString& Gender) {
    return false;
}

bool UUIManager::SetPlayerFirstAndLastName(const FString& PlayerFirstName, const FString& PlayerLastName) {
    return false;
}

bool UUIManager::SetPlayerChosenWandInfo(const FString& WandStyle, const FString& WandWood, const FString& WandCore, const FString& WandLength, const FString& WandFlex) {
    return false;
}

bool UUIManager::SetMKBAxis(const FInputAxisKeyMapping& InAxisMapping, bool bIsPrimary, bool bForceRebuildKeymaps, bool bTranspose) {
    return false;
}

bool UUIManager::SetMKBAction(const FInputActionKeyMapping& InActionMapping, bool bIsPrimary, bool bForceRebuildKeymaps, bool bTranspose) {
    return false;
}

bool UUIManager::SetMenuReaderVolume(const float InVolume) {
    return false;
}

bool UUIManager::SetMenuReaderVoice(const FMenuReaderVoice InVoice) {
    return false;
}

bool UUIManager::SetMenuReaderEnabled(const bool bEnabled) {
    return false;
}

void UUIManager::SetManualFade(float Opacity) {
}

bool UUIManager::SetLocatorBeaconUsingType(const FString& Type, const FString& NameOrLocation) {
    return false;
}

bool UUIManager::SetLocatorBeaconUsingDBLocation(const FString& LocationID) {
    return false;
}

bool UUIManager::SetLocatorBeaconUsingDBDungeonEntrances(const FString& LocationID) {
    return false;
}

bool UUIManager::SetLocatorBeacon(const FString& StudentName, FVector Location, const FString& BeaconIconName) {
    return false;
}

void UUIManager::SetLocationName(FName LocationName, bool ShowNotification) {
}

void UUIManager::SetLoadingSaveGame(bool pLoadingSaveGame) {
}

void UUIManager::SetIsRichPaperShowing(bool Showing) {
}

void UUIManager::SetInPreGameplayState(const bool InPreGameplayState) {
}

void UUIManager::SetInMenuTransitionWithDelay(bool pInMenuTransition, float Delay, const FString& pContext) {
}

void UUIManager::SetInMenuTransition(bool pInMenuTransition, const FString& pContext) {
}

void UUIManager::SetInFrontendLevel(const bool bInFrontend) {
}

void UUIManager::SetInDarkArtsChallenge(bool InDA) {
}

void UUIManager::SetHiddenMenuTabs(TArray<EPauseMenuPage> PagesToHide) {
}

void UUIManager::SetFactsheetMode(EUIFactsheetMode NewFactsheetMode) {
}

void UUIManager::SetDebugLoadingScreen(const bool bDebug) {
}

void UUIManager::SetCursorWidget(UMenuCursorWidget* NewCursor) {
}

void UUIManager::SetCompanionSelectionScreen(UScreen* InScreen) {
}

void UUIManager::SetCastStupefyWithRightTrigger(bool UseRT) {
}

void UUIManager::SetCanBackOutOfAvatarCreator(const bool bCanBackOut) {
}

void UUIManager::SetAsyncScreenLoadInProgress(bool InProgress) {
}

void UUIManager::SetAndShowHintMessage(const FString& HintKey, const ETutorialPosition HintPosition, const bool bIgnoreShowTutorialElementsFlag, const float MaxDuration) {
}

void UUIManager::SetActiveMenu(FName MenuToLoad, bool LoadToSubPage, bool LockToMenu) {
}

void UUIManager::SelectButton() {
}

bool UUIManager::SaveInputConfig() {
    return false;
}

void UUIManager::RevelioPageScreenLoaded(UScreen* Screen) {
}

void UUIManager::ReturnToStartPage() {
}

FString UUIManager::ResolveOptionPanelChoice(const FString& DialogueLine) {
    return TEXT("");
}

void UUIManager::RequestGameAndSystemPause(bool bPause, const FName RequesterName) {
}

void UUIManager::RemoveTargetComponentWidget(const AActor* Target, bool TargetDied) {
}

void UUIManager::RemoveStudentLocatorBeacon() {
}

void UUIManager::RemoveInteractComponentWidget(const AActor* Target) {
}

void UUIManager::RemoveAlertComponentWidget(const AActor* Target, EWidgetType WidgetType) {
}

FString UUIManager::PhoenixTranslate(const FString& Key, const FString& DebugLogText) {
    return TEXT("");
}

bool UUIManager::PhoenixKeyExists(const FString& Key) {
    return false;
}

void UUIManager::PauseLocationNameUI() {
}

void UUIManager::PathSelectionTimerExpired() {
}

void UUIManager::OnVendorLevelUnload(UWorldSupportLevel* Level) {
}

void UUIManager::OnVendorLevelShow(UWorldSupportLevel* Level) {
}

void UUIManager::OnVendorLevelLoad(UWorldSupportLevel* Level) {
}

void UUIManager::OnStatChanged(const FName StatID, const int32 Value, const int32 Delta) {
}

void UUIManager::OnSaveGameLoad() {
}

void UUIManager::OnInputDeviceChanged(EInputDeviceUsed UsedInputDevice, FKey InputPressed) {
}

void UUIManager::OnGameToBeSaved() {
}

void UUIManager::OnFieldGuideUnload(UWorldSupportLevel* Level) {
}

void UUIManager::OnFieldGuideShow(UWorldSupportLevel* Level) {
}

void UUIManager::OnFieldGuideLoad(UWorldSupportLevel* Level) {
}

void UUIManager::OnFadeInComplete() {
}

void UUIManager::OnControlSchemaChanged() {
}

void UUIManager::OnCompanionLevelUnload(UWorldSupportLevel* Level) {
}

void UUIManager::OnCompanionLevelShow(UWorldSupportLevel* Level) {
}

void UUIManager::OnCompanionLevelLoad(UWorldSupportLevel* Level) {
}

void UUIManager::MoviePlaybackFinished(UObject* Caller) {
}

void UUIManager::MissionFailScreenLoaded(UScreen* Screen) {
}

void UUIManager::LoadFieldGuideScreen() {
}

void UUIManager::KeepLoadScreenUp() {
}

bool UUIManager::IsVendorInteract(FName Target) {
    return false;
}

bool UUIManager::IsUsingXboxOneController() {
    return false;
}

bool UUIManager::IsUsingSwitchController() {
    return false;
}

bool UUIManager::IsUsingSteamController() {
    return false;
}

bool UUIManager::IsUsingPS5Controller() {
    return false;
}

bool UUIManager::IsUsingPS4Controller() {
    return false;
}

bool UUIManager::IsStudentLocatorBeaconActive(const FString& StudentName) {
    return false;
}

bool UUIManager::IsSteamRunningOnSteamDeck() const {
    return false;
}

bool UUIManager::IsSteamInBigPictureMode() const {
    return false;
}

bool UUIManager::IsPopupReady() {
    return false;
}

bool UUIManager::IsPauseRequestedBy(const FName RequesterName) const {
    return false;
}

bool UUIManager::IsNabSackAlreadyEquipped() {
    return false;
}

bool UUIManager::IsMenuTabHidden(EPauseMenuPage MenuTab) {
    return false;
}

bool UUIManager::IsMenuReaderSupported() {
    return false;
}

bool UUIManager::IsMenuReaderEnabled() {
    return false;
}

bool UUIManager::IsMenuReaderCurrentLanguageSupported() {
    return false;
}

bool UUIManager::IsMenuReaderBusy() {
    return false;
}

bool UUIManager::IsItemNew(const FName CategoryName, const FName ItemName) {
    return false;
}

bool UUIManager::IsInPreGameplayState() const {
    return false;
}

bool UUIManager::IsInFrontendLevel() const {
    return false;
}

bool UUIManager::IsGamepadTypeConnected(TEnumAsByte<EGamepadType> GamepadType) {
    return false;
}

bool UUIManager::IsFaded() {
    return false;
}

bool UUIManager::IsDebugLoadingScreen() const {
    return false;
}

bool UUIManager::IsAxisKeyValid(const FInputAxisKeyMapping& InAxisMapping) {
    return false;
}

bool UUIManager::IsAsyncScreenLoadInProgress() {
    return false;
}

bool UUIManager::IsActionKeyValid(const FInputActionKeyMapping& InActionMapping) {
    return false;
}

void UUIManager::InteractComponentWidget(const AActor* Target) {
}

bool UUIManager::InPauseMode() {
    return false;
}

bool UUIManager::InFieldGuideMenuTransition() {
    return false;
}

bool UUIManager::InDarkArtsChallenge() {
    return false;
}

void UUIManager::IconTextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UUIManager::HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName) {
}

AActor* UUIManager::GetVendorWorldPreviewActor() {
    return NULL;
}

EUIPlatformInputDevice UUIManager::GetUIPlatformInputDevice() {
    return EUIPlatformInputDevice::UIPID_PS4;
}

UUIManager* UUIManager::GetUIManagerPure() {
    return NULL;
}

bool UUIManager::GetToMapFromBackButton() {
    return false;
}

bool UUIManager::GetTempPauseLock() {
    return false;
}

TEnumAsByte<HouseIds> UUIManager::GetSortingHatRecommendedHouse() {
    return HOUSE_GRYFFINDOR;
}

bool UUIManager::GetShouldShowButtonGraphics() {
    return false;
}

UScreenFadeWidget* UUIManager::GetScreenFadeWidget() {
    return NULL;
}

float UUIManager::GetPSOProgress() {
    return 0.0f;
}

int32 UUIManager::GetPlayerYear(EDisciplineType Discipline) {
    return 0;
}

APawn* UUIManager::GetPlayerPawn() {
    return NULL;
}

FString UUIManager::GetPlayerName() {
    return TEXT("");
}

FString UUIManager::GetPlayerInventorySortPreference() const {
    return TEXT("");
}

TEnumAsByte<HouseIds> UUIManager::GetPlayerHouseEnum() {
    return HOUSE_GRYFFINDOR;
}

FString UUIManager::GetPlayerHouse() {
    return TEXT("");
}

FString UUIManager::GetPlayerGender() {
    return TEXT("");
}

void UUIManager::GetPlayerFirstAndLastName(FString& PlayerFirstName, FString& PlayerLastName) {
}

bool UUIManager::GetPlayerChosenWandInfo(FString& WandStyle, FString& WandWood, FString& WandCore, FString& WandLength, FString& WandFlex) {
    return false;
}

TArray<FInputGroupHeader> UUIManager::GetPCInputGroupHeaders(bool bAction, bool bAxis) {
    return TArray<FInputGroupHeader>();
}

UMapOverland* UUIManager::GetOverlandMap() {
    return NULL;
}

void UUIManager::GetNewIndicatorCategory(const FName CategoryName, TArray<FName>& NewIndicatorItems) {
}

int32 UUIManager::GetNewFactCount() {
    return 0;
}

bool UUIManager::GetMutatedMKBAxisMappingsByName(const FName& AxisName, const TArray<FKey>& ForbiddenKeys, FInputAxisKeyMapping& OutPosMain, FInputAxisKeyMapping& OutFakePosMain, FInputAxisKeyMapping& OutPosAlt, FInputAxisKeyMapping& OutNegMain, FInputAxisKeyMapping& OutFakeNegMain, FInputAxisKeyMapping& OutNegAlt, bool bTranspose) {
    return false;
}

bool UUIManager::GetMKBAxisPairsByName(const FName& AxisName, FInputAxisKeyMapping& OutPositivePrimary, FInputAxisKeyMapping& OutPositiveAlternative, FInputAxisKeyMapping& OutNegativePrimary, FInputAxisKeyMapping& OutNegativeAlternative, bool bTranspose) {
    return false;
}

bool UUIManager::GetMKBActionPairByName(const FName ActionName, FInputActionKeyMapping& OutPrimary, FInputActionKeyMapping& OutAlternative, bool bTranspose) {
    return false;
}

bool UUIManager::GetMastermindTutorialInfo(FMastermindTutorialInfo& outMastermindTutorialInfo) {
    return false;
}

bool UUIManager::GetMastermindScreenInfo(FMastermindScreenInfo& outMastermindScreenInfo) {
    return false;
}

bool UUIManager::GetMastermindPopupInfo(FMastermindPopupInfo& outMastermindPopupInfo) {
    return false;
}

UMapSubSystem* UUIManager::GetMapSubSystem() {
    return NULL;
}

EInputDeviceUsed UUIManager::GetLastUsedInputDevice() const {
    return EInputDeviceUsed::None;
}

void UUIManager::GetKeyIdsFromActionId(const FString& ActionId, TArray<FString>& OutKeyIds, bool Transpose, bool ForceGamepadKeys, bool ForceMouseKeyboardKeys) {
}

bool UUIManager::GetIsVirtualCursorShowing() {
    return false;
}

bool UUIManager::GetIsUIShown() {
    return false;
}

bool UUIManager::GetIsRichPaperShowing() {
    return false;
}

bool UUIManager::GetIsInitialized() {
    return false;
}

bool UUIManager::GetInMenuTransition() {
    return false;
}

UInGameMenuScreen* UUIManager::GetInGameMenuWidget() {
    return NULL;
}

UMapHogwarts* UUIManager::GetHogwartsMap() {
    return NULL;
}

UMapHogsmeade* UUIManager::GetHogsmeadeMap() {
    return NULL;
}

TArray<EPauseMenuPage> UUIManager::GetHiddenMenuTabs() {
    return TArray<EPauseMenuPage>();
}

TArray<FName> UUIManager::GetGroupMappingNames(const FName GroupName, bool bAction, bool bAxis, bool bSort) {
    return TArray<FName>();
}

UFieldGuideMenu* UUIManager::GetFieldGuideWidget() {
    return NULL;
}

EUIFactsheetMode UUIManager::GetFactsheetMode() {
    return EUIFactsheetMode::UI_Compendium;
}

UMapDungeon* UUIManager::GetDungeonMap() {
    return NULL;
}

FString UUIManager::GetDisplayedUserTag() {
    return TEXT("");
}

UMenuCursorWidget* UUIManager::GetCursorWidget() {
    return NULL;
}

UWorld* UUIManager::GetCurrentWorld() {
    return NULL;
}

UScreen* UUIManager::GetCompanionSelectionScreen() {
    return NULL;
}

AActor* UUIManager::GetCallOutComponentTarget(const AActor* Target) {
    return NULL;
}

FString UUIManager::GetBuildNumber() {
    return TEXT("");
}

void UUIManager::GetAxisMappingByName(const FName AxisName, TArray<FInputAxisKeyMapping>& OutMappings, bool bTranspose, bool bMouseAndKeyboardOnly, bool bIncludeUnbound) {
}

TArray<FMenuReaderVoice> UUIManager::GetAvailableVoices() {
    return TArray<FMenuReaderVoice>();
}

TArray<FRPGUIInfo> UUIManager::GetActiveBuffData() {
    return TArray<FRPGUIInfo>();
}

void UUIManager::GetActionMappingByName(const FName ActionName, TArray<FInputActionKeyMapping>& OutMappings, bool bTranspose, bool bMouseAndKeyboardOnly, bool bIncludeUnbound) {
}

UUIManager* UUIManager::Get() {
    return NULL;
}

void UUIManager::GameOverScreenLoaded(UScreen* Screen) {
}

void UUIManager::ForceRebuildKeyMapsFromQWERTY() {
}

void UUIManager::FieldGuideMenuStart() {
}

void UUIManager::FadeOutToColor(float Duration, FLinearColor TargetColor) {
}

void UUIManager::FadeOut(float Duration) {
}

void UUIManager::FadeIn(float Duration) {
}

void UUIManager::ExitFieldGuideWithReason(EFieldGuideExitReasons ExitReason, bool SkipFadeScreen, int32 CharacterID, const FString& Filename, const FString& FastTravelName) {
}

void UUIManager::DropLoadScreen() {
}

bool UUIManager::DoesRightTriggerCastStupefy() {
    return false;
}

void UUIManager::DestroyVendorWorld() {
}

void UUIManager::DestroyCompanionrWorld() {
}

void UUIManager::DebugTriggerCollectionObtainedNotification(FName CollectionID, FName CollectionCategory) {
}

void UUIManager::DebugTriggerCollectionKnownNotification(FName CollectionID, FName CollectionCategory) {
}

void UUIManager::DebugTriggerChallengeUpdatedNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedAmt, int32 TotalRequired) {
}

void UUIManager::DebugTriggerChallengeUnlockedNotification(FName ChallengeID, FName ChallengeCategory, int32 TotalRequired) {
}

void UUIManager::DebugTriggerChallengeCompleteNotification(FName ChallengeID, FName ChallengeCategory, int32 CompletedLevel, int32 TotalLevels, int32 TotalInstancesForLevel) {
}

void UUIManager::CycleControlModeInputCheck1() {
}

void UUIManager::CreateHUDLog(bool pShow, const FString& Group, const FString& pContext) {
}

void UUIManager::CreateGameOverScreen(EUIGameOverReason Reason) {
}

bool UUIManager::CreateAsyncWidget(TSoftClassPtr<UScreen> ObjectPtr, const FAsyncScreenLoadCallback& AsyncLoadCallback, bool AddToViewport) {
    return false;
}

void UUIManager::CorrectInputAxisKeyIfNeeded(const FInputAxisKeyMapping& InInputAxisMapping, FInputAxisKeyMapping& OutInputAxisMapping) {
}

void UUIManager::ClearPauseMenuPageBP() {
}

void UUIManager::ClearPath() {
}

void UUIManager::ClearNewIndicatorItem(const FName CategoryName, const FName ItemName) {
}

void UUIManager::ClearNewIndicatorCategory(const FName CategoryName) {
}

void UUIManager::ClearHintMessage() {
}

void UUIManager::ClearCurrentLocationName() {
}

void UUIManager::ChangeMenuPage() {
}

void UUIManager::ChallengeResultsScreenLoaded(UScreen* Screen) {
}

bool UUIManager::CanPlayIntroNormally() {
    return false;
}

bool UUIManager::CanBackOutOfAvatarCreator() {
    return false;
}

void UUIManager::BuildNavPointsUsingActors(const TArray<AActor*>& Actors, float Width, float Height) {
}

void UUIManager::AppendNavPointsUsingActors(const TArray<AActor*>& Actors) {
}

void UUIManager::AnimateTrackingInfo() {
}

void UUIManager::AlertComponentWidget(const AActor* Target, EWidgetType WidgetType) {
}

void UUIManager::AdvanceTime(FTimespan DeltaTimeAdvance) {
}

void UUIManager::AddTextTickerNotification(const FString& NotificationText) {
}

void UUIManager::AddPathStartEnd(FVector Start, FVector End, float Width, float Height) {
}

void UUIManager::AddPathPoints(const TArray<FVector>& PathPoints, float Width, float Height) {
}

void UUIManager::AddPathEnd(FVector End, float Width, float Height) {
}

void UUIManager::AddNewIndicatorItem(const FName CategoryName, const FName ItemName) {
}

void UUIManager::AddNavPathPoints(const TArray<FVector>& PathPoints, float Width, float Height) {
}

UUIManager::UUIManager() {
    this->IconDataTable = NULL;
    this->TargetUITable = NULL;
    this->NotificationManager = NULL;
    this->TutorialSystem = NULL;
    this->ErrorTexture = NULL;
    this->LoadingTexture = NULL;
    this->UIDisplayMode = EUIDisplayMode::UI_Viewing;
    this->CompendiumCategory = TEXT("Person");
    this->LastVisitedMenuPage = TEXT("Character");
    this->GlobalParallaxMultiplier = 1.00f;
    this->NextExpGainDelay = 0.00f;
    this->DefaultGenderRig = EGenderEnum::GENDER_MALE;
    this->DefaultMalePreset = TEXT("BodyMale001");
    this->DefaultFemalePreset = TEXT("BodyFemale001");
    this->PauseWorld = NULL;
    this->FieldGuideWorld = NULL;
    this->VendorWorld = NULL;
    this->CompanionWorld = NULL;
    this->CompanionSelectScreen = NULL;
    this->GamePlayerController = NULL;
    this->CastStupefyWithRightTrigger = true;
    this->OverlandMap = NULL;
    this->InteractWidget = NULL;
    this->mUIScreenFadeClass = NULL;
    this->DungeonMap = NULL;
    this->HogwartsMap = NULL;
    this->HogsmeadeMap = NULL;
    this->InGameMenuWidgetClass = NULL;
    this->FieldGuideWidgetClass = NULL;
    this->InGameMenuWidget = NULL;
    this->FieldGuideWidget = NULL;
    this->PopupScreenClass = NULL;
    this->bIsRichPaperShowing = false;
    this->PathActor = NULL;
    this->m_pScreenFadeWidget = NULL;
    this->MissionFailedScreen = NULL;
    this->CompanionBeaconInfo = NULL;
}

