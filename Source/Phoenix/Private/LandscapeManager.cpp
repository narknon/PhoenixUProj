#include "LandscapeManager.h"

class ULandscapeManager;
class ULevel;
class ULevelStreaming;

void ULandscapeManager::RemoveCriticalLevel(ULevelStreaming* InLevel) {
}

void ULandscapeManager::PrepareMapCapture() {
}

void ULandscapeManager::OnShow() {
}

void ULandscapeManager::OnSaveGameLoad() {
}

void ULandscapeManager::OnLoad() {
}

void ULandscapeManager::OnGameToSave() {
}

bool ULandscapeManager::IsReadyForMapCapture() {
    return false;
}

bool ULandscapeManager::IsLocationExploredRegion(FVector Location, float MapScale) {
    return false;
}

bool ULandscapeManager::IsLocationExploredFog(FVector Location, float MapScale) {
    return false;
}

bool ULandscapeManager::IsLoadedLevelCritical(ULevel* InLevel) {
    return false;
}

bool ULandscapeManager::IsLevelCritical(ULevelStreaming* InLevel) {
    return false;
}

int32 ULandscapeManager::GetNumActiveLevelLoads(bool InCriticalOnly) {
    return 0;
}

FBox ULandscapeManager::GetLandscapeWorldBounds() {
    return FBox{};
}

ULandscapeManager* ULandscapeManager::Get() {
    return NULL;
}

void ULandscapeManager::ForceLandscapeLODs() {
}

void ULandscapeManager::DoMapCapture() {
}

void ULandscapeManager::ClearCriticalLevels() {
}

void ULandscapeManager::CleanupMapCapture() {
}

void ULandscapeManager::AddCriticalLevel(ULevelStreaming* InLevel) {
}

ULandscapeManager::ULandscapeManager() {
}

