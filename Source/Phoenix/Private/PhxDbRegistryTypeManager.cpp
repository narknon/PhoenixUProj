#include "PhxDbRegistryTypeManager.h"

class AActor;

bool UPhxDbRegistryTypeManager::UnregisterSpawnWhenDestroyed(AActor* InAssetPtr) {
    return false;
}

bool UPhxDbRegistryTypeManager::RegisterNewSpawn(AActor* InAssetPtr) {
    return false;
}

UPhxDbRegistryTypeManager::UPhxDbRegistryTypeManager() {
}

