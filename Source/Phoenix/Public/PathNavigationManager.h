#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "DebugMapData.h"
#include "EHogwartsNavmeshID.h"
#include "EMapTypes.h"
#include "EPathTargetType.h"
#include "MapIconEntry.h"
#include "MapLocationHint.h"
#include "NavigationPathUpdatedDelegate.h"
#include "PathDestinationLocation.h"
#include "Templates/SubclassOf.h"
#include "PathNavigationManager.generated.h"

class AAuthoredPath;
class AGuideSpline;
class ANavigationArrow;
class UBeaconInfo;
class UMapPathData;
class UOverlandPathFinder;
class UPathCollector;
class UPathNavigationManager;
class UPathSelectHUD;
class UScheduledEntity;
class USplineComponent;
class UWorld;
class UWorldSupportWorld;

UCLASS(Blueprintable)
class UPathNavigationManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FMapLocationHint> MapLocationHints;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavigationPathUpdated OnNavigationPathUpdated;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 MapTargetBeaconHandle;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 WayMarkerBeaconHandle;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 MissionBeaconHandle;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBeaconInfo> MapTargetBeacon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MapTargetBeaconLongName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UScheduledEntity* MapTargetScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MapTargetWorldLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> MapTargetWaypoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPathTargetType PathTargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpliceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowUnknownRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> HogwartExits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CoastNorthLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CoastSouthLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGuideSpline> GuideSplineClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector> GuidePathPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGuideSpline* GuideSplineActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WiggleIterDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WiggleMaxDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WiggleInitialDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WiggleRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WiggleMaxAngleDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* PathSelectWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathSelectHUD* PathSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowingPathSelectUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPathCollector* PathCollector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOverlandPathFinder* OverlandPathFinder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDebugMapData debugHelperData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* FlightPathWorld;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapPathData* AllRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ANavigationArrow*> PathMarkerActorsTS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, AAuthoredPath*> RegisteredAuthoredPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> PathTS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapIconEntry> MinimapPathTS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapIconEntry> ElevationChangePointsTS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FPathDestinationLocation> PathDestinationLocationsMap;
    
public:
    UPathNavigationManager();
    UFUNCTION(BlueprintCallable)
    void UseAuthoredPath(FName Name);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMissionBeacons(const bool bStart);
    
    UFUNCTION(BlueprintCallable)
    AGuideSpline* SpawnGuideSplineFromPath(UPARAM(Ref) TArray<FVector>& InPath);
    
    UFUNCTION(BlueprintCallable)
    void ShowPathSelectionUI();
    
    UFUNCTION(BlueprintCallable)
    void SetWaypointPathTarget(TArray<FVector> Waypoints);
    
    UFUNCTION(BlueprintCallable)
    void SetStaticPathTarget(FVector staticTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetImportantPathName(FName Name);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconPathTarget(const int64 NewBeaconHandle, const bool bValidateOnly, const FString& BeaconLongName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGuideSpline();
    
    UFUNCTION(BlueprintCallable)
    void ReDisplayMissionObjective();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PathNavigation_ToggleUseForcePathDestination();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PathNavigation_TogglePauseThread();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PathNavigation_SetUseForcePathDestination(bool bNewValue);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PathNavigation_SetForcePathDestination(float X, float Y, float Z);
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainLowered();
    
    UFUNCTION(BlueprintCallable)
    void MarkHogwartsNavmeshLoaded(const EHogwartsNavmeshID NavMesh, const bool bLoaded);
    
    UFUNCTION(BlueprintCallable)
    bool IsWaypointPathTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocationInAreaBeaconArea(FVector Location) const;
    
    UFUNCTION(BlueprintCallable)
    void HidePathSelectionUI();
    
    UFUNCTION(BlueprintCallable)
    bool HasGuidePath();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDestinationLocation(bool ShowDestinationsInAreaBeacons) const;
    
    UFUNCTION(BlueprintCallable)
    bool GiveMeHelp();
    
    UFUNCTION(BlueprintCallable)
    FVector GetWaymarkerDestinationLocation();
    
    UFUNCTION(BlueprintCallable)
    FVector GetPathDestinationLocation();
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector> GetPath();
    
    UFUNCTION(BlueprintCallable)
    TArray<ANavigationArrow*> GetNagivationMarkerActors();
    
    UFUNCTION(BlueprintCallable)
    FVector GetMissionDestinationLocation();
    
    UFUNCTION(BlueprintCallable)
    TArray<FMapIconEntry> GetMinimapPath();
    
    UFUNCTION(BlueprintCallable)
    FName GetImportantPathName();
    
    UFUNCTION(BlueprintCallable)
    FVector GetGuidePathEndPoint();
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector> GetGuidePath();
    
    UFUNCTION(BlueprintCallable)
    TArray<FMapIconEntry> GetElevationChangePoints();
    
    UFUNCTION(BlueprintCallable)
    FVector GetDestinationLocationForBeacon(UBeaconInfo* Beacon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanPlayerTrackDestination() const;
    
    UFUNCTION(BlueprintCallable)
    FName GetAuthoredPathName();
    
    UFUNCTION(BlueprintCallable)
    static UPathNavigationManager* Get();
    
    UFUNCTION(BlueprintCallable)
    bool FindPath(const FVector& Start, const FVector& End, TArray<FVector>& OutPath, bool& OutMissingHogwartsSection);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteSave(const int32 CharacterID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Debug_StartMap(EMapTypes::Type MapTypeIn, UWorld* WorldIn);
    
    UFUNCTION(BlueprintCallable)
    void ClearWaypointPathTarget();
    
    UFUNCTION(BlueprintCallable)
    void ClearWaymarkerTarget();
    
    UFUNCTION(BlueprintCallable)
    void ClearPathTarget();
    
    UFUNCTION(BlueprintCallable)
    void ClearPathAndMissionTarget();
    
    UFUNCTION(BlueprintCallable)
    void ClearImportantPathName();
    
    UFUNCTION(BlueprintCallable)
    void ClearAuthoredPath();
    
    UFUNCTION(BlueprintCallable)
    void AddWaypointPathTarget(FVector Point);
    
    UFUNCTION(BlueprintCallable)
    void AddMissionBeacon(UScheduledEntity* dynamicTarget, const FVector staticTarget, const int64 BeaconHandle);
    
};

