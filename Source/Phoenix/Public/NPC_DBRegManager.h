#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "PhxDbRegistryTypeManager.h"
#include "Templates/SubclassOf.h"
#include "NPC_DBRegManager.generated.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class UNPC_DBRegManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
    UNPC_DBRegManager();
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod inCollisioinMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION()
    void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION()
    void RestoreData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION()
    uint32 GetUniqueObjectID(const FString& InItemID);
    
    UFUNCTION(BlueprintCallable)
    bool GetSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath);
    
    UFUNCTION(BlueprintCallable)
    bool GetSpawnAsset(const FString& InItemID, TSubclassOf<AActor>& OutAsset);
    
    UFUNCTION()
    float GetHealth(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION(BlueprintCallable)
    bool CreateItemAsScheduledEntity(const FString& InItemID);
    
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
};

