#include "StationManager.h"

class UStationComponent;
class UStationManager;

bool UStationManager::IsPlayerInWorld(const FName& InWorldName) {
    return false;
}

UStationManager* UStationManager::GetStationManager() {
    return NULL;
}

UStationComponent* UStationManager::GetClosestPlayerBed() {
    return NULL;
}

bool UStationManager::FindSiteLocation(const FString& InSiteName, FVector& Location) {
    return false;
}

bool UStationManager::FindBedSiteLocation(const FString& InSiteName, FVector& Location) {
    return false;
}

UStationManager::UStationManager() {
}

