#include "MapSubSystem.h"

class AActor;
class AMapPawn;
class APawn;
class APlayerController;
class UBeaconInfo;
class UMapBase;
class UMapDungeon;
class UMapFXManager;
class UMapHogsmeade;
class UMapHogwarts;
class UMapOverland;
class UMapScreenBase;
class UMinimapManager;
class UObject;
class UTexture2D;
class UUIAccessibilityManager;
class UWorld;

void UMapSubSystem::UpdatePlayerRegionAsync() {
}

void UMapSubSystem::UpdateDungeonFogMaskAsync(FVector PlayerPosition) {
}

bool UMapSubSystem::UnloadLevels() {
    return false;
}

bool UMapSubSystem::UnloadFieldGuideLevels() {
    return false;
}

void UMapSubSystem::UIReleaseTransitionLock() {
}

void UMapSubSystem::TriggerMapScreenFadeOut() {
}

void UMapSubSystem::TriggerMapScreenFadeIn() {
}

void UMapSubSystem::TriggerAccessibility(EAccessibilityAudioCueEventType Type, AActor* Actor) {
}

void UMapSubSystem::TeleportToListIndex(int32 Index) {
}

void UMapSubSystem::SubdivideAndCreateOctreeAsync() {
}

bool UMapSubSystem::StopMap(bool pCleanupActors, TEnumAsByte<EMapPostFadeState> PostFadeState) {
    return false;
}

void UMapSubSystem::StartTutorialOpenMap(FName TutorialName) {
}

void UMapSubSystem::StartMapExitTransition(float InDuration) {
}

bool UMapSubSystem::StartMap() {
    return false;
}

void UMapSubSystem::ShowMap(bool NewShowMap) {
}

void UMapSubSystem::ShowDebugPanel() {
}

void UMapSubSystem::SetToMapFromIndexOrTab(bool InToMapFromIndexOrTab) {
}

void UMapSubSystem::SetShouldRevealMinimapOnStart(bool RevealMinimapOnStart) {
}

void UMapSubSystem::SetOverrideFIG01FTCheck(bool pOverrideCheck) {
}

void UMapSubSystem::SetMiniMapManager(UMinimapManager* pMiniMapManager) {
}

void UMapSubSystem::SetMapTransitionStyle(EMapTransitionStyle InStyle) {
}

void UMapSubSystem::SetLastActiveMap() {
}

void UMapSubSystem::SetIsInVault(bool InIsInVault) {
}

void UMapSubSystem::SetIsFromOverland(bool NewIsFromOverland) {
}

void UMapSubSystem::SetIsFromDungeon(bool NewIsFromDungeon) {
}

void UMapSubSystem::SetInPauseMenu(bool InPauseMenuFlag) {
}

void UMapSubSystem::SetIfFromFieldGuide(bool pIsFromFieldGuide) {
}

void UMapSubSystem::SetHasIntroPlayed(bool HasPlayed) {
}

void UMapSubSystem::SetFieldGuideWorldToNull() {
}

void UMapSubSystem::SetFelixFelicisPotionRadius(float PotionRadius) {
}

void UMapSubSystem::SetFadeToGame(bool pSetFadeToGame) {
}

void UMapSubSystem::SetDeveloperMenuUsed(bool pUsedDeveloperMenu) {
}

void UMapSubSystem::SetCoverDisplayed(bool IsDisplayed) {
}

bool UMapSubSystem::SetActiveMapByType(TEnumAsByte<EMapTypes::Type>& MapType) {
    return false;
}

bool UMapSubSystem::SetActiveMap(FName MapName) {
    return false;
}

void UMapSubSystem::RestoreMap() {
}

void UMapSubSystem::RemovePathToLocation() {
}

void UMapSubSystem::RemoveAreaBeaconByHandle(int32 Handle) {
}

void UMapSubSystem::RecenterMapPawn() {
}

void UMapSubSystem::OutputWidgetLog() {
}

void UMapSubSystem::OutputCanvasPanelLog() {
}

void UMapSubSystem::OnStatChanged(const FName StatID, const int32 Value, const int32 Delta) {
}

void UMapSubSystem::OnStartPathing(const UObject* i_caller, uint32 BeaconHandle) {
}

void UMapSubSystem::OnStartNewDay() {
}

void UMapSubSystem::MiniResetPlayerLocation() {
}

void UMapSubSystem::MiniMapToggleIntrusionAlert() {
}

void UMapSubSystem::MiniMapToggleIconsNearMe() {
}

void UMapSubSystem::MiniMapToggleIcons() {
}

void UMapSubSystem::MiniMapShowIconStats() {
}

void UMapSubSystem::MiniMapSetTutorialIntroLevel(FName IntroLevel) {
}

void UMapSubSystem::MiniMapSetSize(float Size, float ZoomTime) {
}

void UMapSubSystem::MiniMapSetScale(float Size) {
}

void UMapSubSystem::MiniMapSetPlayerToHogwarts() {
}

void UMapSubSystem::MiniMapSetPlayerToHogsmeade() {
}

void UMapSubSystem::MiniMapSetPlayerLocationToCursor() {
}

void UMapSubSystem::MiniMapSetPlayerLocation(float X, float Y, float Z) {
}

void UMapSubSystem::MiniMapSetPlayerActorPosition(float X, float Y, float Z) {
}

void UMapSubSystem::MiniMapSetPerceptionOverlay() {
}

void UMapSubSystem::MiniMapSetOptions(int32 Size, float Opacity, int32 PathlineOn) {
}

void UMapSubSystem::MiniMapSetNoFlyTexture(int32 Value) {
}

void UMapSubSystem::MiniMapSetMap(FName MapName) {
}

void UMapSubSystem::MiniMapSetLevelName(const FString& LevelName) {
}

void UMapSubSystem::MiniMapSetLevel(int32 LevelIndex) {
}

void UMapSubSystem::MiniMapSetIconSize(float Size) {
}

void UMapSubSystem::MiniMapSetIconScale(float IconDistanceScale) {
}

void UMapSubSystem::MiniMapSetDungeonRadius(float Value) {
}

void UMapSubSystem::MiniMapReveal(int32 Reveal) {
}

void UMapSubSystem::MiniMapQuickFade(int32 Reveal) {
}

void UMapSubSystem::MiniMapDungeonSetPartialTextureUpdate(bool Enable) {
}

void UMapSubSystem::MiniMapDungeonEnableFogOfWar(bool Enable) {
}

void UMapSubSystem::MiniMapDungeonDebug(float Value) {
}

void UMapSubSystem::MiniMapDebugMap(FName MapName) {
}

void UMapSubSystem::MiniMapDeactivateIntrusionArea(FName IntrusionVolumeActorName) {
}

void UMapSubSystem::MiniMapAlwaysShowFastTravelIcons(int32 Value) {
}

void UMapSubSystem::MiniMapActivateIntrusionArea(FName IntrusionVolumeActorName) {
}

void UMapSubSystem::MapWriteLog() {
}

void UMapSubSystem::MapVerifyBeacons(int32 LocationIndex, int32 pTeleportType, int32 pEndIndex) {
}

void UMapSubSystem::MapUnlockAllRegions() {
}

void UMapSubSystem::MapUnlockAllMapIcons(int32 Type) {
}

void UMapSubSystem::MapUnloadOverlandLevels() {
}

void UMapSubSystem::MapTurnOnDebugCamera(int32 Value) {
}

void UMapSubSystem::MapTurnOnCompletionMessages(int32 Value) {
}

void UMapSubSystem::MapTurnOnCollisionSphere(int32 Value) {
}

void UMapSubSystem::MapTurnOnAllMapLocations(FName Filter, bool pSetStateToShown) {
}

void UMapSubSystem::MapTurnOffMapLocationNames() {
}

void UMapSubSystem::MapTriggerMapScreenFadeOut() {
}

void UMapSubSystem::MapTriggerMapScreenFadeIn() {
}

void UMapSubSystem::MapToggleRegionSplineDots(int32 Value) {
}

void UMapSubSystem::MapTogglePushIconsAway() {
}

void UMapSubSystem::MapTogglePathDots() {
}

void UMapSubSystem::MapTogglePathDebug() {
}

void UMapSubSystem::MapToggleMapRoads() {
}

void UMapSubSystem::MapToggleMapBounds() {
}

void UMapSubSystem::MapToggleIconStacking(int32 Value) {
}

void UMapSubSystem::MapToggleFogDrawMode(int32 DrawMode) {
}

void UMapSubSystem::MapToggleFogCheckForIcons() {
}

void UMapSubSystem::MapToggleFog() {
}

void UMapSubSystem::MapTestRegionSaturation(FName Region) {
}

void UMapSubSystem::MapTestMissionIcons() {
}

void UMapSubSystem::MapTeleportToLocation(const FString& pName, int32 pTeleportType) {
}

void UMapSubSystem::MapStopFXChain() {
}

void UMapSubSystem::MapStopFX() {
}

void UMapSubSystem::MapStopFieldGuideTest() {
}

void UMapSubSystem::MapSpawnFXChain(FName FXChainName, float X, float Y, float Z, float SX, float SY, float SZ) {
}

void UMapSubSystem::MapSpawnFX(FName FXName, float X, float Y, float Z, float SX, float SY, float SZ) {
}

void UMapSubSystem::MapShowTierLevel() {
}

void UMapSubSystem::MapShowPathingDebug() {
}

void UMapSubSystem::MapShowMapIconStats() {
}

void UMapSubSystem::MapShowMap() {
}

void UMapSubSystem::MapShowIconsWithoutRegions(int32 Value) {
}

void UMapSubSystem::MapShowCursorPosition() {
}

void UMapSubSystem::MapShowCollisionActor() {
}

void UMapSubSystem::MapSetSpecificIcons() {
}

void UMapSubSystem::MapSetPlayerToCursorPosition() {
}

void UMapSubSystem::MapSetIsFromFieldGuide(int32 Value) {
}

void UMapSubSystem::MapSetIconSize(float Size) {
}

void UMapSubSystem::MapSetBeaconState(EBeaconType BeaconType, EBeaconState BeaconState) {
}

void UMapSubSystem::MapSendHermesString(FName MessageName, FName Parameter) {
}

void UMapSubSystem::MapSendHermes(FName MessageName) {
}

void UMapSubSystem::MapRestoreIcons() {
}

void UMapSubSystem::MapRemoveDebugPane() {
}

void UMapSubSystem::MapReloadMapTables() {
}

void UMapSubSystem::MapProcessFlightNav() {
}

void UMapSubSystem::MapOverrideMapCamera() {
}

void UMapSubSystem::MapOpenFieldGuideTest(int32 DoFastTravel) {
}

void UMapSubSystem::MapMoveToTier(int32 tierValue, float Time) {
}

void UMapSubSystem::MapLoadOverlandLevels() {
}

void UMapSubSystem::MapLerpToIcon(float X, float Y, float Z, float Speed) {
}

void UMapSubSystem::MapIconTextureCallback(UTexture2D* Texture, UObject* Param) {
}

void UMapSubSystem::MapHideIcons(int32 Value) {
}

void UMapSubSystem::MapGiveMeHelp() {
}

void UMapSubSystem::MapFillRegionMask() {
}

void UMapSubSystem::MapDungeonTogglePPV() {
}

void UMapSubSystem::MapDungeonShowStats() {
}

void UMapSubSystem::MapDungeonShowAll() {
}

void UMapSubSystem::MapDumpUnmatchedBeacons() {
}

void UMapSubSystem::MapDumpNoRegionBeacons() {
}

void UMapSubSystem::MapDumpDynamicBeacons() {
}

void UMapSubSystem::MapDumpDiscoverableBeacons() {
}

void UMapSubSystem::MapDoKnowledgeCard(const FString& Item) {
}

void UMapSubSystem::MapCreateDebugPane() {
}

void UMapSubSystem::MapClearWorldStack() {
}

void UMapSubSystem::MapClearRegionMask() {
}

void UMapSubSystem::MapCancelLogs() {
}

void UMapSubSystem::MapAlwaysShowMerlin(int32 ShowMerlin) {
}

void UMapSubSystem::MapAlwaysShowDemiguise(int32 ShowDemiguise) {
}

void UMapSubSystem::MapAlwaysDefaultToOverlandMap(int32 Value) {
}

uint32 UMapSubSystem::MapAddDynamicBeacon(EBeaconType BeaconType, FName BeaconName, FName BeaconIcon, float X, float Y, float Z) {
    return 0;
}

uint32 UMapSubSystem::MapAddAreaBeaconAtPlayerLocation(float Radius) {
    return 0;
}

void UMapSubSystem::Locate(const FString& ItemToLocate, const FString& Category, const FString& OnMap) {
}

bool UMapSubSystem::LoadLevels() {
    return false;
}

void UMapSubSystem::LoadGameLevel(const FString& LevelName) {
}

bool UMapSubSystem::LoadFieldGuideLevels() {
    return false;
}

bool UMapSubSystem::IsTutorialLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsTutorial() {
    return false;
}

bool UMapSubSystem::IsTentLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsTent() {
    return false;
}

bool UMapSubSystem::IsSanctuaryLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsSanctuary() {
    return false;
}

bool UMapSubSystem::IsPathDisplayEnabled() {
    return false;
}

bool UMapSubSystem::IsOverlandLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsOverland() {
    return false;
}

bool UMapSubSystem::IsMapReadyCalled() {
    return false;
}

bool UMapSubSystem::IsMapReady() {
    return false;
}

bool UMapSubSystem::IsMapActive() {
    return false;
}

bool UMapSubSystem::IsHoloLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsHolo() {
    return false;
}

bool UMapSubSystem::IsHogwartsLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsHogwarts() {
    return false;
}

bool UMapSubSystem::IsHogsmeadeLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsHogsmeade() {
    return false;
}

bool UMapSubSystem::IsFTPointValidPreFIG01b(const FString& FTLocationID) {
    return false;
}

bool UMapSubSystem::IsFromOverland() {
    return false;
}

bool UMapSubSystem::IsFromDungeon() {
    return false;
}

bool UMapSubSystem::IsExclusiveMissionActive() {
    return false;
}

bool UMapSubSystem::IsDungeonMap() {
    return false;
}

bool UMapSubSystem::IsDungeonLevel(const FString& LevelName) {
    return false;
}

bool UMapSubSystem::IsDungeon() {
    return false;
}

bool UMapSubSystem::IsBeaconNameInMapDB(const FString& BeaconName) {
    return false;
}

bool UMapSubSystem::IsBeaconComplete(const FString& BeaconName) {
    return false;
}

bool UMapSubSystem::HasDungeonBeenEntered(const FString& DungeonName) {
    return false;
}

bool UMapSubSystem::GetUsingGamePad() {
    return false;
}

FLinearColor UMapSubSystem::GetTrackedWaypointColor() {
    return FLinearColor{};
}

FLinearColor UMapSubSystem::GetTrackedMissionColor() {
    return FLinearColor{};
}

FLinearColor UMapSubSystem::GetTrackedColor() {
    return FLinearColor{};
}

bool UMapSubSystem::GetShouldRevealMinimapOnStart() {
    return false;
}

FMapWithinRegion UMapSubSystem::GetRegionForLocation(FVector Location, UMapBase* MapBase) {
    return FMapWithinRegion{};
}

void UMapSubSystem::GetPlayerLocation() {
}

UMapOverland* UMapSubSystem::GetOverlandMap() {
    return NULL;
}

TArray<int32> UMapSubSystem::GetNewlyDiscoveredBeacons() {
    return TArray<int32>();
}

UMinimapManager* UMapSubSystem::GetMiniMapManager() {
    return NULL;
}

UWorld* UMapSubSystem::GetMapWorld() {
    return NULL;
}

EMapTransitionStyle UMapSubSystem::GetMapTransitionStyle() const {
    return EMapTransitionStyle::Short;
}

UMapScreenBase* UMapSubSystem::GetMapScreenWidget() {
    return NULL;
}

AMapPawn* UMapSubSystem::GetMapPawn() {
    return NULL;
}

UMapBase* UMapSubSystem::GetMapByType(TEnumAsByte<EMapTypes::Type> MapType) {
    return NULL;
}

TArray<UBeaconInfo*> UMapSubSystem::GetMapBeaconsNearLocation(FVector Location, float Radius) {
    return TArray<UBeaconInfo*>();
}

UBeaconInfo* UMapSubSystem::GetMapBeaconFromName(const FString& BeaconName) {
    return NULL;
}

bool UMapSubSystem::GetMapActivated() {
    return false;
}

FLinearColor UMapSubSystem::GetMainLineColor() {
    return FLinearColor{};
}

FString UMapSubSystem::GetLocatedItem() {
    return TEXT("");
}

UMapBase* UMapSubSystem::GetLastActiveMap() {
    return NULL;
}

bool UMapSubSystem::GetIsInVault() {
    return false;
}

bool UMapSubSystem::GetIsFromFieldGuide() {
    return false;
}

bool UMapSubSystem::GetInPauseMenu() {
    return false;
}

FLinearColor UMapSubSystem::GetIconColorByState(EBeaconState BeaconState) {
    return FLinearColor{};
}

UMapHogwarts* UMapSubSystem::GetHogwartsMap() {
    return NULL;
}

UMapHogsmeade* UMapSubSystem::GetHogsmeadeMap() {
    return NULL;
}

bool UMapSubSystem::GetHasIntroPlayed() {
    return false;
}

UWorld* UMapSubSystem::GetGameWorld() {
    return NULL;
}

APlayerController* UMapSubSystem::GetGamePlayerController() {
    return NULL;
}

APawn* UMapSubSystem::GetGamePawn() {
    return NULL;
}

UMapFXManager* UMapSubSystem::GetFXManager() {
    return NULL;
}

FName UMapSubSystem::GetFilter() {
    return NAME_None;
}

bool UMapSubSystem::GetFelixFelicisPotionActive() {
    return false;
}

bool UMapSubSystem::GetFadeToGame() {
    return false;
}

UMapDungeon* UMapSubSystem::GetDungeonMap() {
    return NULL;
}

bool UMapSubSystem::GetDeveloperMenuUsed() {
    return false;
}

TEnumAsByte<ECursorControlTypes::Type> UMapSubSystem::GetCursorControl() {
    return ECursorControlTypes::CURSOR_CONTROL_AUTO;
}

FMapWithinRegion UMapSubSystem::GetCurrentPlayerRegionInfo() {
    return FMapWithinRegion{};
}

bool UMapSubSystem::GetCoverIsDisplayed() {
    return false;
}

FLinearColor UMapSubSystem::GetColorFromState(UBeaconInfo* BeaconInfo) {
    return FLinearColor{};
}

TArray<UBeaconInfo*> UMapSubSystem::GetChestsInVault(const FString& VaultName) {
    return TArray<UBeaconInfo*>();
}

EBeaconState UMapSubSystem::GetBeaconState(const FString& BeaconName) {
    return EBeaconState::BEACONSTATE_NONE;
}

FLinearColor UMapSubSystem::GetAuthorityFigureColor() {
    return FLinearColor{};
}

TEnumAsByte<EMapTypes::Type> UMapSubSystem::GetActiveMapType() {
    return EMapTypes::MAP_TYPE_NONE;
}

FName UMapSubSystem::GetActiveMapName() {
    return NAME_None;
}

int32 UMapSubSystem::GetActiveMapIndex() {
    return 0;
}

UMapBase* UMapSubSystem::GetActiveMap() {
    return NULL;
}

UUIAccessibilityManager* UMapSubSystem::GetAccessibilityManager() {
    return NULL;
}

int32 UMapSubSystem::FindMapByType(TEnumAsByte<EMapTypes::Type> MapType) {
    return 0;
}

int32 UMapSubSystem::FindMap(FName MapName) {
    return 0;
}

void UMapSubSystem::EnablePathDisplay(bool Enable) {
}

FName UMapSubSystem::DetermineMap() {
    return NAME_None;
}

void UMapSubSystem::DeactivateMap() {
}

void UMapSubSystem::CreateAreaBeacon(float X, float Y, float Z, float Radius) {
}

void UMapSubSystem::CompleteBeaconOfType(EBeaconType BeaconType) {
}

bool UMapSubSystem::ClearActiveMap() {
    return false;
}

void UMapSubSystem::AudioCueTrigger(int32 DisplayType, int32 CueType) {
}

bool UMapSubSystem::AreItemsRevealed(const FString& ItemName) {
    return false;
}

void UMapSubSystem::ActivateMapByType(EMapTypes::Type MapType, bool fromOverland, bool fromDungeon) {
}

void UMapSubSystem::ActivateMap() {
}

UMapSubSystem::UMapSubSystem() {
    this->PathSplineComponent[0] = NULL;
    this->PathSplineComponent[1] = NULL;
    this->PathActor[0] = NULL;
    this->PathActor[1] = NULL;
    this->CleanNameToDisplayName = NULL;
    this->InWorldArrowMaterial = NULL;
    this->PathIconList = NULL;
    this->RegionSplineDotList = NULL;
    this->RegionMaskTempTexture = NULL;
    this->IconRenderWidgetClass = NULL;
    this->MapPlayerMarker = NULL;
    this->InGameDirectionArrowClass = NULL;
    this->InGameDirectionArrow = NULL;
    this->IconRenderWidgetSimpleMaterial = NULL;
    this->IconRenderWidgetPathMaterial = NULL;
    this->RegionMaskHighlightBlitter = NULL;
    this->RegionMaskHighlightTexture = NULL;
    this->SplineWorld = NULL;
    this->DebugTextPanel = NULL;
    this->IconColorsTable = NULL;
    this->MiniMapIconOutlinesTable = NULL;
    this->IconAnimationTable = NULL;
    this->MiniMapIconBackgroundLayersTable = NULL;
    this->MapFXTables = NULL;
    this->MapLocTable = NULL;
    this->MapDungeonSubdivisionTable = NULL;
    this->IconTierTable = NULL;
    this->IconCacheTable = NULL;
    this->IconTierTableHogsmeade = NULL;
    this->IconTierTableHogwarts = NULL;
    this->IconStylesTable = NULL;
    this->RegionSplineNamesTable = NULL;
    this->RegionSplineClass = NULL;
    this->IntrusionFullScreenFX = NULL;
    this->LastPathToHighlight = NULL;
    this->ActiveMap = NULL;
    this->LastActiveMap = NULL;
    this->MapPawn = NULL;
    this->MovementComponent = NULL;
    this->PreviousViewTarget = NULL;
    this->MapNavMeshAssetPackage = NULL;
    this->MapNavMeshData = NULL;
    this->FXManager = NULL;
    this->DummyTexture = NULL;
    this->AccessibilityManager = NULL;
    this->OverlandMapTexture = NULL;
    this->SharedMapData = NULL;
}

