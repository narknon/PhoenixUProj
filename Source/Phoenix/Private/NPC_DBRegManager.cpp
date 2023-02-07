#include "NPC_DBRegManager.h"
#include "Templates/SubclassOf.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

AActor* UNPC_DBRegManager::Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod inCollisioinMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

void UNPC_DBRegManager::SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

void UNPC_DBRegManager::RestoreData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

void UNPC_DBRegManager::OnSaveGameLoaded() {
}

uint32 UNPC_DBRegManager::GetUniqueObjectID(const FString& InItemID) {
    return 0;
}

bool UNPC_DBRegManager::GetSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) {
    return false;
}

bool UNPC_DBRegManager::GetSpawnAsset(const FString& InItemID, TSubclassOf<AActor>& OutAsset) {
    return false;
}

float UNPC_DBRegManager::GetHealth(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID) {
    return 0.0f;
}

bool UNPC_DBRegManager::CreateItemAsScheduledEntity(const FString& InItemID) {
    return false;
}

ESpawnAllowedResponse UNPC_DBRegManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UNPC_DBRegManager::UNPC_DBRegManager() {
}

