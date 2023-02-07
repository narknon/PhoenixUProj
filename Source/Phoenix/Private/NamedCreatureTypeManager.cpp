#include "NamedCreatureTypeManager.h"
#include "Templates/SubclassOf.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

AActor* UNamedCreatureTypeManager::SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) {
    return NULL;
}

AActor* UNamedCreatureTypeManager::Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

bool UNamedCreatureTypeManager::GetSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) {
    return false;
}

bool UNamedCreatureTypeManager::GetSpawnAsset(const FString& InItemID, TSubclassOf<AActor>& OutAsset) {
    return false;
}

bool UNamedCreatureTypeManager::GetShellSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) {
    return false;
}

ESpawnAllowedResponse UNamedCreatureTypeManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UNamedCreatureTypeManager::UNamedCreatureTypeManager() {
}

