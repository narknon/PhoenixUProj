#include "DynamicObjectManager.h"

class AActor;
class UDynamicObjectManager;

bool UDynamicObjectManager::SpawnObjectByName(const FString& ObjectToSpawn) {
    return false;
}

AActor* UDynamicObjectManager::SpawnDynamicObject(const FString& ObjectToSpawn, FDynamicObjectLoadInfo InSpawnParams) {
    return NULL;
}

void UDynamicObjectManager::SetDynamicSpawningEnabled(bool bInEnableSpawning) {
}

void UDynamicObjectManager::OnSaveGameLoaded() {
}

void UDynamicObjectManager::ObjectLoaded() {
}

bool UDynamicObjectManager::LoadDynamicObject(const FString& ObjectToLoad) {
    return false;
}

bool UDynamicObjectManager::IsObjectLoaded(const FString& ObjectToLoad) {
    return false;
}

UDynamicObjectManager* UDynamicObjectManager::Get() {
    return NULL;
}

FTransform UDynamicObjectManager::FindValidLocation(FTransform InTransform, float Radius, float halfAngle) {
    return FTransform{};
}

void UDynamicObjectManager::DoDelayedSpawn(uint32 RequestID) {
}

UDynamicObjectManager::UDynamicObjectManager() {
    this->pGameInstance = NULL;
    this->pRandomEncounter = NULL;
}

