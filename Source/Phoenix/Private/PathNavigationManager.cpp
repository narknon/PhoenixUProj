#include "PathNavigationManager.h"

class AGuideSpline;
class ANavigationArrow;
class UBeaconInfo;
class UPathNavigationManager;
class UScheduledEntity;
class UWorld;

void UPathNavigationManager::UseAuthoredPath(FName Name) {
}

void UPathNavigationManager::UpdateMissionBeacons(const bool bStart) {
}

AGuideSpline* UPathNavigationManager::SpawnGuideSplineFromPath(TArray<FVector>& InPath) {
    return NULL;
}

void UPathNavigationManager::ShowPathSelectionUI() {
}

void UPathNavigationManager::SetWaypointPathTarget(TArray<FVector> Waypoints) {
}

void UPathNavigationManager::SetStaticPathTarget(FVector staticTarget) {
}

void UPathNavigationManager::SetImportantPathName(FName Name) {
}

void UPathNavigationManager::SetBeaconPathTarget(const int64 NewBeaconHandle, const bool bValidateOnly, const FString& BeaconLongName) {
}

void UPathNavigationManager::RemoveGuideSpline() {
}

void UPathNavigationManager::ReDisplayMissionObjective() {
}

void UPathNavigationManager::PathNavigation_ToggleUseForcePathDestination() {
}

void UPathNavigationManager::PathNavigation_TogglePauseThread() {
}

void UPathNavigationManager::PathNavigation_SetUseForcePathDestination(bool bNewValue) {
}

void UPathNavigationManager::PathNavigation_SetForcePathDestination(float X, float Y, float Z) {
}

void UPathNavigationManager::OnCurtainRaised() {
}

void UPathNavigationManager::OnCurtainLowered() {
}

void UPathNavigationManager::MarkHogwartsNavmeshLoaded(const EHogwartsNavmeshID NavMesh, const bool bLoaded) {
}

bool UPathNavigationManager::IsWaypointPathTarget() {
    return false;
}

bool UPathNavigationManager::IsLocationInAreaBeaconArea(FVector Location) const {
    return false;
}

void UPathNavigationManager::HidePathSelectionUI() {
}

bool UPathNavigationManager::HasGuidePath() {
    return false;
}

bool UPathNavigationManager::HasDestinationLocation(bool ShowDestinationsInAreaBeacons) const {
    return false;
}

bool UPathNavigationManager::GiveMeHelp() {
    return false;
}

FVector UPathNavigationManager::GetWaymarkerDestinationLocation() {
    return FVector{};
}

FVector UPathNavigationManager::GetPathDestinationLocation() {
    return FVector{};
}

TArray<FVector> UPathNavigationManager::GetPath() {
    return TArray<FVector>();
}

TArray<ANavigationArrow*> UPathNavigationManager::GetNagivationMarkerActors() {
    return TArray<ANavigationArrow*>();
}

FVector UPathNavigationManager::GetMissionDestinationLocation() {
    return FVector{};
}

TArray<FMapIconEntry> UPathNavigationManager::GetMinimapPath() {
    return TArray<FMapIconEntry>();
}

FName UPathNavigationManager::GetImportantPathName() {
    return NAME_None;
}

FVector UPathNavigationManager::GetGuidePathEndPoint() {
    return FVector{};
}

TArray<FVector> UPathNavigationManager::GetGuidePath() {
    return TArray<FVector>();
}

TArray<FMapIconEntry> UPathNavigationManager::GetElevationChangePoints() {
    return TArray<FMapIconEntry>();
}

FVector UPathNavigationManager::GetDestinationLocationForBeacon(UBeaconInfo* Beacon) {
    return FVector{};
}

bool UPathNavigationManager::GetCanPlayerTrackDestination() const {
    return false;
}

FName UPathNavigationManager::GetAuthoredPathName() {
    return NAME_None;
}

UPathNavigationManager* UPathNavigationManager::Get() {
    return NULL;
}

bool UPathNavigationManager::FindPath(const FVector& Start, const FVector& End, TArray<FVector>& OutPath, bool& OutMissingHogwartsSection) {
    return false;
}

bool UPathNavigationManager::ExecuteSave(const int32 CharacterID) {
    return false;
}

void UPathNavigationManager::Debug_StartMap(EMapTypes::Type MapTypeIn, UWorld* WorldIn) {
}

void UPathNavigationManager::ClearWaypointPathTarget() {
}

void UPathNavigationManager::ClearWaymarkerTarget() {
}

void UPathNavigationManager::ClearPathTarget() {
}

void UPathNavigationManager::ClearPathAndMissionTarget() {
}

void UPathNavigationManager::ClearImportantPathName() {
}

void UPathNavigationManager::ClearAuthoredPath() {
}

void UPathNavigationManager::AddWaypointPathTarget(FVector Point) {
}

void UPathNavigationManager::AddMissionBeacon(UScheduledEntity* dynamicTarget, const FVector staticTarget, const int64 BeaconHandle) {
}

UPathNavigationManager::UPathNavigationManager() {
    this->MapTargetBeaconHandle = 0;
    this->WayMarkerBeaconHandle = 0;
    this->MissionBeaconHandle = 0;
    this->MapTargetScheduledEntity = NULL;
    this->PathTargetType = EPathTargetType::PATH_TARGET_NONE;
    this->MaxSpliceDistance = 500.00f;
    this->ShowUnknownRoads = true;
    this->GuideSplineClass = NULL;
    this->GuideSplineActor = NULL;
    this->WiggleIterDist = 10.00f;
    this->WiggleMaxDist = 400.00f;
    this->WiggleInitialDist = 10.00f;
    this->WiggleRange = 8000.00f;
    this->WiggleMaxAngleDegrees = 20.00f;
    this->PathSelectWidgetClass = NULL;
    this->PathSelectWidget = NULL;
    this->bShowingPathSelectUI = false;
    this->PathCollector = NULL;
    this->OverlandPathFinder = NULL;
    this->FlightPathWorld = NULL;
    this->AllRoads = NULL;
    this->Spline = NULL;
}

