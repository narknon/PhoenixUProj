#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EAccessibilityAudioCueEventType.h"
#include "EBeaconState.h"
#include "EBeaconType.h"
#include "ECursorControlTypes.h"
#include "EMapLocTypes.h"
#include "EMapPostFadeState.h"
#include "EMapTransitionStyle.h"
#include "EMapTypes.h"
#include "ERegionType.h"
#include "MapDungeonSaveDataBlob.h"
#include "MapIconListContainer.h"
#include "MapLocDataItem.h"
#include "MapOptions.h"
#include "MapRegionEnemyLevel.h"
#include "MapWithinRegion.h"
#include "MapSubSystem.generated.h"

class AActor;
class AMapPawn;
class APawn;
class APhoenixPathActor;
class APlayerController;
class UBeaconInfo;
class UCleanNameToDisplayName;
class UDataTable;
class UDebugTextPanel;
class UMapBase;
class UMapDungeon;
class UMapFXManager;
class UMapHogsmeade;
class UMapHogwarts;
class UMapIcon;
class UMapIconInstance;
class UMapIconList;
class UMapMovementComponent;
class UMapNavData;
class UMapOverland;
class UMapScreenBase;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMinimapManager;
class UObject;
class UPackage;
class USharedMapData;
class USplineComponent;
class UStaticMesh;
class UTexture2D;
class UTextureUtil;
class UUIAccessibilityManager;
class UWorld;
class UWorldSupportWorld;

UCLASS(Blueprintable)
class UMapSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> CurrentMapPathMission;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> CurrentMapPathWaymarker;
    
    UPROPERTY(EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* PathSplineComponent[2];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixPathActor* PathActor[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCleanNameToDisplayName* CleanNameToDisplayName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIconInstance*> MapIconInstancePool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOptions MapOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> InWorldDirectionArrowPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* InWorldArrowMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIconList* PathIconList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIconList* RegionSplineDotList;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapIconListContainer MapIconList[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIconList*> MapIconListArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RegionMaskTempTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* IconRenderWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MapPlayerMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* InGameDirectionArrowClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* InGameDirectionArrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetSimpleMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetPathMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UTexture2D*> MapIconTextureCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureUtil* RegionMaskHighlightBlitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RegionMaskHighlightTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, UTexture2D*> RegionTextureToRegionMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, int32> RegionTypeToRegionPixelMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UTexture2D*> RegionTextureToRegionNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* SplineWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebugTextPanel* DebugTextPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EMapLocTypes::Type>, FMapLocDataItem> IconLocMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconColorsTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MiniMapIconOutlinesTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconAnimationTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MiniMapIconBackgroundLayersTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MapFXTables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MapLocTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MapDungeonSubdivisionTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconTierTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconCacheTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconTierTableHogsmeade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconTierTableHogwarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* IconStylesTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* RegionSplineNamesTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* RegionSplineClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* IntrusionFullScreenFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, FString> RegionSplineLocNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERegionType, FMapRegionEnemyLevel> RegionSplineEnemyLevelMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UBeaconInfo*> DiscoverableBeacons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapBase*> MapScreens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldSupportWorld*> MapWorlds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* LastPathToHighlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapBase* ActiveMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapBase* LastActiveMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> NewlyDiscoveredBeacons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> NewlyDiscoveredFastTravelLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> PreviouslySeenFastTravelLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIcon*> MapIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapPawn* MapPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PreviousViewTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapDungeonSaveDataBlob DungeonFOWDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPackage* MapNavMeshAssetPackage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapNavData* MapNavMeshData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapFXManager* FXManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandFastTravelLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HogwartsFastTravelLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HogsmeadeFastTravelLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandSphinxPuzzleLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandTreasureVaultLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandChestLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> DungeonChestLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandAstronomyLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandDemiguiseLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HogwartsDemiguiseLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HogsmeadeDemiguiseLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandAncientMagicLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandHamletLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBanditCampLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBeastDenLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandEnemyDenLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandForagablesLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandPlantsLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandDungeonsLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandTentsLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandNamedEnemyLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandKnowledgeEnemyLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBothyLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandCombatChallengesLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> HogsmeadeLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBroomPlatformLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBroomRaceLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandBroomBalloonLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> OverlandRuinLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> VendorsLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBeaconInfo*> KnowledgeInvestigatablesLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<int32, USplineComponent*> IconAnimationSplines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* DummyTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUIAccessibilityManager* AccessibilityManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* OverlandMapTexture;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USharedMapData* SharedMapData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> BPClasses;
    
public:
    UMapSubSystem();
private:
    UFUNCTION(BlueprintCallable)
    void UpdatePlayerRegionAsync();
    
    UFUNCTION(BlueprintCallable)
    void UpdateDungeonFogMaskAsync(FVector PlayerPosition);
    
public:
    UFUNCTION(BlueprintCallable)
    bool UnloadLevels();
    
    UFUNCTION(BlueprintCallable, Exec)
    bool UnloadFieldGuideLevels();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UIReleaseTransitionLock();
    
    UFUNCTION(BlueprintCallable)
    void TriggerMapScreenFadeOut();
    
    UFUNCTION(BlueprintCallable)
    void TriggerMapScreenFadeIn();
    
    UFUNCTION(BlueprintCallable)
    void TriggerAccessibility(EAccessibilityAudioCueEventType Type, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TeleportToListIndex(int32 Index);
    
private:
    UFUNCTION(BlueprintCallable)
    void SubdivideAndCreateOctreeAsync();
    
public:
    UFUNCTION(BlueprintCallable)
    bool StopMap(bool pCleanupActors, TEnumAsByte<EMapPostFadeState> PostFadeState);
    
    UFUNCTION(BlueprintCallable, Exec)
    void StartTutorialOpenMap(FName TutorialName);
    
    UFUNCTION(BlueprintCallable)
    void StartMapExitTransition(float InDuration);
    
    UFUNCTION(BlueprintCallable)
    bool StartMap();
    
    UFUNCTION(BlueprintCallable)
    void ShowMap(bool NewShowMap);
    
    UFUNCTION(BlueprintCallable)
    void ShowDebugPanel();
    
    UFUNCTION(BlueprintCallable)
    void SetToMapFromIndexOrTab(bool InToMapFromIndexOrTab);
    
    UFUNCTION(BlueprintCallable)
    void SetShouldRevealMinimapOnStart(bool RevealMinimapOnStart);
    
    UFUNCTION(BlueprintCallable)
    void SetOverrideFIG01FTCheck(bool pOverrideCheck);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapManager(UMinimapManager* pMiniMapManager);
    
    UFUNCTION(BlueprintCallable)
    void SetMapTransitionStyle(EMapTransitionStyle InStyle);
    
    UFUNCTION(BlueprintCallable)
    void SetLastActiveMap();
    
    UFUNCTION(BlueprintCallable)
    void SetIsInVault(bool InIsInVault);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFromOverland(bool NewIsFromOverland);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFromDungeon(bool NewIsFromDungeon);
    
    UFUNCTION(BlueprintCallable)
    void SetInPauseMenu(bool InPauseMenuFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetIfFromFieldGuide(bool pIsFromFieldGuide);
    
    UFUNCTION(BlueprintCallable)
    void SetHasIntroPlayed(bool HasPlayed);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetFieldGuideWorldToNull();
    
    UFUNCTION(BlueprintCallable)
    void SetFelixFelicisPotionRadius(float PotionRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetFadeToGame(bool pSetFadeToGame);
    
    UFUNCTION(BlueprintCallable)
    void SetDeveloperMenuUsed(bool pUsedDeveloperMenu);
    
    UFUNCTION(BlueprintCallable)
    void SetCoverDisplayed(bool IsDisplayed);
    
    UFUNCTION(BlueprintCallable)
    bool SetActiveMapByType(TEnumAsByte<EMapTypes::Type>& MapType);
    
    UFUNCTION(BlueprintCallable)
    bool SetActiveMap(FName MapName);
    
    UFUNCTION(BlueprintCallable)
    void RestoreMap();
    
    UFUNCTION(BlueprintCallable)
    void RemovePathToLocation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveAreaBeaconByHandle(int32 Handle);
    
    UFUNCTION(BlueprintCallable)
    void RecenterMapPawn();
    
    UFUNCTION(BlueprintCallable, Exec)
    void OutputWidgetLog();
    
    UFUNCTION(BlueprintCallable, Exec)
    void OutputCanvasPanelLog();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
public:
    UFUNCTION()
    void OnStartPathing(const UObject* i_caller, uint32 BeaconHandle);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStartNewDay();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void MiniResetPlayerLocation();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapToggleIntrusionAlert();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapToggleIconsNearMe();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapToggleIcons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapShowIconStats();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetTutorialIntroLevel(FName IntroLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetSize(float Size, float ZoomTime);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetScale(float Size);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPlayerToHogwarts();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPlayerToHogsmeade();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPlayerLocationToCursor();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPlayerLocation(float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPlayerActorPosition(float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetPerceptionOverlay();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetOptions(int32 Size, float Opacity, int32 PathlineOn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetNoFlyTexture(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetMap(FName MapName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetLevelName(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetLevel(int32 LevelIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetIconSize(float Size);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetIconScale(float IconDistanceScale);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapSetDungeonRadius(float Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapReveal(int32 Reveal);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapQuickFade(int32 Reveal);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapDungeonSetPartialTextureUpdate(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapDungeonEnableFogOfWar(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapDungeonDebug(float Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapDebugMap(FName MapName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapDeactivateIntrusionArea(FName IntrusionVolumeActorName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapAlwaysShowFastTravelIcons(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MiniMapActivateIntrusionArea(FName IntrusionVolumeActorName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapWriteLog();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapVerifyBeacons(int32 LocationIndex, int32 pTeleportType, int32 pEndIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapUnlockAllRegions();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapUnlockAllMapIcons(int32 Type);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapUnloadOverlandLevels();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTurnOnDebugCamera(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTurnOnCompletionMessages(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTurnOnCollisionSphere(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTurnOnAllMapLocations(FName Filter, bool pSetStateToShown);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTurnOffMapLocationNames();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTriggerMapScreenFadeOut();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTriggerMapScreenFadeIn();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleRegionSplineDots(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTogglePushIconsAway();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTogglePathDots();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTogglePathDebug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleMapRoads();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleMapBounds();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleIconStacking(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleFogDrawMode(int32 DrawMode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleFogCheckForIcons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapToggleFog();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTestRegionSaturation(FName Region);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTestMissionIcons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapTeleportToLocation(const FString& pName, int32 pTeleportType);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapStopFXChain();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapStopFX();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapStopFieldGuideTest();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSpawnFXChain(FName FXChainName, float X, float Y, float Z, float SX, float SY, float SZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSpawnFX(FName FXName, float X, float Y, float Z, float SX, float SY, float SZ);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowTierLevel();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowPathingDebug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowMapIconStats();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowMap();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowIconsWithoutRegions(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowCursorPosition();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapShowCollisionActor();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSetSpecificIcons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSetPlayerToCursorPosition();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSetIsFromFieldGuide(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSetIconSize(float Size);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSetBeaconState(EBeaconType BeaconType, EBeaconState BeaconState);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSendHermesString(FName MessageName, FName Parameter);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapSendHermes(FName MessageName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapRestoreIcons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapRemoveDebugPane();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapReloadMapTables();
    
    UFUNCTION(BlueprintCallable, Exec)
    static void MapProcessFlightNav();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapOverrideMapCamera();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapOpenFieldGuideTest(int32 DoFastTravel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapMoveToTier(int32 tierValue, float Time);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapLoadOverlandLevels();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapLerpToIcon(float X, float Y, float Z, float Speed);
    
private:
    UFUNCTION(BlueprintCallable)
    void MapIconTextureCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void MapHideIcons(int32 Value);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapGiveMeHelp();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapFillRegionMask();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDungeonTogglePPV();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDungeonShowStats();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDungeonShowAll();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDumpUnmatchedBeacons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDumpNoRegionBeacons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDumpDynamicBeacons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDumpDiscoverableBeacons();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapDoKnowledgeCard(const FString& Item);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapCreateDebugPane();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapClearWorldStack();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapClearRegionMask();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapCancelLogs();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapAlwaysShowMerlin(int32 ShowMerlin);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapAlwaysShowDemiguise(int32 ShowDemiguise);
    
    UFUNCTION(BlueprintCallable, Exec)
    void MapAlwaysDefaultToOverlandMap(int32 Value);
    
    UFUNCTION(Exec)
    uint32 MapAddDynamicBeacon(EBeaconType BeaconType, FName BeaconName, FName BeaconIcon, float X, float Y, float Z);
    
    UFUNCTION(Exec)
    uint32 MapAddAreaBeaconAtPlayerLocation(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void Locate(const FString& ItemToLocate, const FString& Category, const FString& OnMap);
    
    UFUNCTION(BlueprintCallable)
    bool LoadLevels();
    
    UFUNCTION(BlueprintCallable)
    void LoadGameLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable, Exec)
    bool LoadFieldGuideLevels();
    
    UFUNCTION(BlueprintCallable)
    bool IsTutorialLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsTutorial();
    
    UFUNCTION(BlueprintCallable)
    bool IsTentLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsTent();
    
    UFUNCTION(BlueprintCallable)
    bool IsSanctuaryLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsSanctuary();
    
    UFUNCTION(BlueprintCallable)
    bool IsPathDisplayEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsOverlandLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsOverland();
    
    UFUNCTION(BlueprintCallable)
    bool IsMapReadyCalled();
    
    UFUNCTION(BlueprintCallable)
    bool IsMapReady();
    
    UFUNCTION(BlueprintCallable)
    bool IsMapActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsHoloLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsHolo();
    
    UFUNCTION(BlueprintCallable)
    bool IsHogwartsLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsHogwarts();
    
    UFUNCTION(BlueprintCallable)
    bool IsHogsmeadeLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsHogsmeade();
    
    UFUNCTION(BlueprintCallable)
    bool IsFTPointValidPreFIG01b(const FString& FTLocationID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFromOverland();
    
    UFUNCTION(BlueprintCallable)
    bool IsFromDungeon();
    
    UFUNCTION(BlueprintCallable)
    bool IsExclusiveMissionActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsDungeonMap();
    
    UFUNCTION(BlueprintCallable)
    bool IsDungeonLevel(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    bool IsDungeon();
    
    UFUNCTION(BlueprintCallable)
    bool IsBeaconNameInMapDB(const FString& BeaconName);
    
    UFUNCTION(BlueprintCallable)
    bool IsBeaconComplete(const FString& BeaconName);
    
    UFUNCTION(BlueprintCallable)
    bool HasDungeonBeenEntered(const FString& DungeonName);
    
    UFUNCTION(BlueprintCallable)
    bool GetUsingGamePad();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetTrackedWaypointColor();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetTrackedMissionColor();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetTrackedColor();
    
    UFUNCTION(BlueprintCallable)
    bool GetShouldRevealMinimapOnStart();
    
    UFUNCTION(BlueprintCallable)
    FMapWithinRegion GetRegionForLocation(FVector Location, UMapBase* MapBase);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GetPlayerLocation();
    
    UFUNCTION(BlueprintCallable)
    UMapOverland* GetOverlandMap();
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> GetNewlyDiscoveredBeacons();
    
    UFUNCTION(BlueprintCallable)
    UMinimapManager* GetMiniMapManager();
    
    UFUNCTION(BlueprintCallable)
    UWorld* GetMapWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMapTransitionStyle GetMapTransitionStyle() const;
    
    UFUNCTION(BlueprintCallable)
    UMapScreenBase* GetMapScreenWidget();
    
    UFUNCTION(BlueprintCallable)
    AMapPawn* GetMapPawn();
    
private:
    UFUNCTION(BlueprintCallable)
    UMapBase* GetMapByType(TEnumAsByte<EMapTypes::Type> MapType);
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<UBeaconInfo*> GetMapBeaconsNearLocation(FVector Location, float Radius);
    
    UFUNCTION(BlueprintCallable)
    UBeaconInfo* GetMapBeaconFromName(const FString& BeaconName);
    
    UFUNCTION(BlueprintCallable)
    bool GetMapActivated();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetMainLineColor();
    
    UFUNCTION(BlueprintCallable)
    FString GetLocatedItem();
    
    UFUNCTION(BlueprintCallable)
    UMapBase* GetLastActiveMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsInVault();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsFromFieldGuide();
    
    UFUNCTION(BlueprintCallable)
    bool GetInPauseMenu();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetIconColorByState(EBeaconState BeaconState);
    
    UFUNCTION(BlueprintCallable)
    UMapHogwarts* GetHogwartsMap();
    
    UFUNCTION(BlueprintCallable)
    UMapHogsmeade* GetHogsmeadeMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetHasIntroPlayed();
    
    UFUNCTION(BlueprintCallable)
    UWorld* GetGameWorld();
    
    UFUNCTION(BlueprintCallable)
    APlayerController* GetGamePlayerController();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetGamePawn();
    
    UFUNCTION(BlueprintCallable)
    UMapFXManager* GetFXManager();
    
    UFUNCTION(BlueprintCallable)
    FName GetFilter();
    
    UFUNCTION(BlueprintCallable)
    bool GetFelixFelicisPotionActive();
    
    UFUNCTION(BlueprintCallable)
    bool GetFadeToGame();
    
    UFUNCTION(BlueprintCallable)
    UMapDungeon* GetDungeonMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetDeveloperMenuUsed();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<ECursorControlTypes::Type> GetCursorControl();
    
    UFUNCTION(BlueprintCallable)
    FMapWithinRegion GetCurrentPlayerRegionInfo();
    
    UFUNCTION(BlueprintCallable)
    bool GetCoverIsDisplayed();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetColorFromState(UBeaconInfo* BeaconInfo);
    
    UFUNCTION(BlueprintCallable)
    TArray<UBeaconInfo*> GetChestsInVault(const FString& VaultName);
    
    UFUNCTION(BlueprintCallable)
    EBeaconState GetBeaconState(const FString& BeaconName);
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetAuthorityFigureColor();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapTypes::Type> GetActiveMapType();
    
    UFUNCTION(BlueprintCallable)
    FName GetActiveMapName();
    
    UFUNCTION(BlueprintCallable)
    int32 GetActiveMapIndex();
    
    UFUNCTION(BlueprintCallable)
    UMapBase* GetActiveMap();
    
    UFUNCTION(BlueprintCallable)
    UUIAccessibilityManager* GetAccessibilityManager();
    
private:
    UFUNCTION(BlueprintCallable)
    int32 FindMapByType(TEnumAsByte<EMapTypes::Type> MapType);
    
    UFUNCTION(BlueprintCallable)
    int32 FindMap(FName MapName);
    
public:
    UFUNCTION(BlueprintCallable)
    void EnablePathDisplay(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    FName DetermineMap();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateMap();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CreateAreaBeacon(float X, float Y, float Z, float Radius);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CompleteBeaconOfType(EBeaconType BeaconType);
    
    UFUNCTION(BlueprintCallable)
    bool ClearActiveMap();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AudioCueTrigger(int32 DisplayType, int32 CueType);
    
    UFUNCTION(BlueprintCallable)
    bool AreItemsRevealed(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable)
    void ActivateMapByType(EMapTypes::Type MapType, bool fromOverland, bool fromDungeon);
    
    UFUNCTION(BlueprintCallable)
    void ActivateMap();
    
};

