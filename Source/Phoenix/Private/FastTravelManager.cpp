#include "FastTravelManager.h"

class AActor;
class AFastTravelLocation;
class AFloo;
class UFastTravelManager;

void UFastTravelManager::UnlockLocationByName(const FString& LocationName) {
}

void UFastTravelManager::UnlockLocationByActor(AFastTravelLocation* locationActor) {
}

void UFastTravelManager::UnlockLocation(const FString& LocationID) {
}

void UFastTravelManager::TestExec() {
}

void UFastTravelManager::StartFastTravelWithCallbackBP(FVector ToLocation, FFastTravelFinishedBP Callback, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType) {
}

void UFastTravelManager::StartFastTravelUsingIDWithCallbackBP(const FString& LocationID, FFastTravelFinishedBP Callback, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType) {
}

void UFastTravelManager::StartFastTravelUsingID(const FString& LocationID, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType) {
}

bool UFastTravelManager::StartFastTravelToNamedLocation(FFastTravelLocationName LocationName, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType) {
    return false;
}

bool UFastTravelManager::StartFastTravelToClosestUnlockedSaveLocationToPlayer() {
    return false;
}

bool UFastTravelManager::StartFastTravelToClosestUnlockedSaveLocation(FVector CheckLocation) {
    return false;
}

void UFastTravelManager::StartFastTravel(AActor* TravelActorIn, FVector ToLocation, const FString& EndPointActorNameIn, float Yaw, TEnumAsByte<EFT_FromType> FromType, EFT_TravelType FastTravelControlType) {
}

void UFastTravelManager::SetWaitEnabled(bool Enable) {
}

void UFastTravelManager::SetForceFastTravelLocationName(const FString& FastTravelID, const FString& StartInMap) {
}

void UFastTravelManager::SetFastTravelDisabled(bool Disabled) {
}

void UFastTravelManager::PlayWaitSceneRig(bool WaitAtEnd) {
}

void UFastTravelManager::PlayerSelectedFloo(AActor* ActorUsingFloo, const FString& FastTravelID) {
}

void UFastTravelManager::PlayerExitingFloo(AActor* ActorUsingFloo) {
}

void UFastTravelManager::PlayerExitedFloo(AActor* ActorUsingFloo) {
}

void UFastTravelManager::PlayerEnteringFloo(AActor* ActorUsingFloo) {
}

void UFastTravelManager::PlayerEnteredFloo(AActor* ActorUsingFloo) {
}

void UFastTravelManager::PlayerDroppedPowder(AActor* ActorUsingFloo) {
}

void UFastTravelManager::PlayerCanceledFloo(AActor* ActorUsingFloo) {
}

void UFastTravelManager::LockLocationByName(const FString& LocationName) {
}

void UFastTravelManager::LockLocationByActor(AFastTravelLocation* locationActor) {
}

bool UFastTravelManager::IsWaitEnabled() {
    return false;
}

bool UFastTravelManager::IsFlooLoaded(const FString& Name, AFloo*& TargetFlooIn) {
    return false;
}

bool UFastTravelManager::IsFastTravelUnlockedForLocation(const FString& LocationID) {
    return false;
}

bool UFastTravelManager::IsFastTravelTutorialActive() {
    return false;
}

bool UFastTravelManager::IsFastTravelling() {
    return false;
}

bool UFastTravelManager::IsFastTravelDisabled() {
    return false;
}

bool UFastTravelManager::IsFastTravelDebugUnlockAllActive() {
    return false;
}

bool UFastTravelManager::IsFastTravelAvailableForLocation(const FString& LocationID) {
    return false;
}

bool UFastTravelManager::IsFastTravelAvailable() {
    return false;
}

bool UFastTravelManager::HasHardLoadFastTravelLocation() {
    return false;
}

float UFastTravelManager::GetHardLoadFastTravelYaw() {
    return 0.0f;
}

FVector UFastTravelManager::GetHardLoadFastTravelLocaiton() {
    return FVector{};
}

FString UFastTravelManager::GetForceFastTravelLocationName() {
    return TEXT("");
}

void UFastTravelManager::GetFastTravelLocationsByType(const FString& Type, TArray<FTravelLocation>& Locations) {
}

void UFastTravelManager::GetFastTravelLocations(TArray<FString>& Names, TArray<FVector>& Locations) {
}

bool UFastTravelManager::GetFastTravelLocationFromName(const FString& Name, FVector& Location) {
    return false;
}

bool UFastTravelManager::GetFastTravelLocationDataFromName(const FString& Name, FTravelLocation& Location) {
    return false;
}

bool UFastTravelManager::GetClosestUnlockedSaveLocationToPlayer(FTravelLocation& LocationData) {
    return false;
}

bool UFastTravelManager::GetClosestUnlockedSaveLocation(FVector CheckLocation, FTravelLocation& LocationData) {
    return false;
}

void UFastTravelManager::GetAvailableFloos(TArray<FTravelLocation>& AvailableFloos) {
}

UFastTravelManager* UFastTravelManager::Get() {
    return NULL;
}

void UFastTravelManager::FinishWait() {
}

bool UFastTravelManager::FindFastTravelLocationData(const FString& LocationID, FTravelLocation& LocationData) {
    return false;
}

bool UFastTravelManager::FastTravelTutorialCompleted() {
    return false;
}

void UFastTravelManager::FastTravel_To(const FString& LocationID) {
}

void UFastTravelManager::FastTravel_TeleportToXYZ(float X, float Y, float Z) {
}

void UFastTravelManager::FastTravel_EnableWaitSR(bool tf) {
}

void UFastTravelManager::FastTravel_DisableNextWaitSR(bool tf) {
}

void UFastTravelManager::EnableWaitSR(bool Enabled) {
}

void UFastTravelManager::DoWait() {
}

void UFastTravelManager::DebugLogFastTravelInformation(const FString& Data1, const FString& Data2) {
}

void UFastTravelManager::ClearHardLoadFastTravelLocaiton() {
}

void UFastTravelManager::ClearForceFastTravelLocationName() {
}

void UFastTravelManager::AddFastTravelLocationWithLockToDB(AFastTravelLocation* locationActor, const FString& LocationName, FVector Location, FVector BeaconLocation, float ZRot, bool isSaveLocation, bool IsBuiltNightly, bool ShowOnMap, bool Locked) {
}

void UFastTravelManager::AddFastTravelLocationToDB(const FString& LocationName, FVector Location, FVector BeaconLocation, float ZRot, const FString& RegionId, bool isSaveLocation, bool IsBuiltNightly, bool ShowOnMap) {
}

bool UFastTravelManager::ActorDismount(AActor* InActor) {
    return false;
}

UFastTravelManager::UFastTravelManager() {
    this->bWaitEnabled = true;
    this->SourceFlooRef = NULL;
    this->TargetFloo = NULL;
    this->WaitSceneRigActor = NULL;
    this->LastActorUsingFloo = NULL;
    this->FlooListEntry = NULL;
}

