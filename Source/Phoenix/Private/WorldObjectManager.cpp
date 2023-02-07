#include "WorldObjectManager.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

AActor* UWorldObjectManager::Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

void UWorldObjectManager::SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

ESpawnAllowedResponse UWorldObjectManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UWorldObjectManager::UWorldObjectManager() {
}

