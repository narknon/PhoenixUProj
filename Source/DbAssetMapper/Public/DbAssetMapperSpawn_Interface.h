#pragma once
#include "CoreMinimal.h"
#include "SQLiteQueryResultMap.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ESpawnAllowedResponse.h"
#include "ESpawnRestrictionResponse.h"
#include "NPC_DbObjectInstanceData.h"
#include "RestrictionInfo.h"
#include "Templates/SubclassOf.h"
#include "DbAssetMapperSpawn_Interface.generated.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

UINTERFACE(MinimalAPI)
class UDbAssetMapperSpawn_Interface : public UInterface {
    GENERATED_BODY()
};

class IDbAssetMapperSpawn_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION()
    virtual bool UnregisterSpawnWhenDestroyed(AActor* InAssetPtr) PURE_VIRTUAL(UnregisterSpawnWhenDestroyed, return false;);
    
    UFUNCTION()
    virtual AActor* SpawnShell(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) PURE_VIRTUAL(SpawnShell, return NULL;);
    
    UFUNCTION()
    virtual AActor* SpawnSEAsset(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, const FString& inOverrideScheduleName, const FString& inOverrideScheduleTable, const FString& inOverrideWorldID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) PURE_VIRTUAL(SpawnSEAsset, return NULL;);
    
    UFUNCTION()
    virtual AActor* SpawnAsync(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) PURE_VIRTUAL(SpawnAsync, return NULL;);
    
    UFUNCTION()
    virtual AActor* Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) PURE_VIRTUAL(Spawn, return NULL;);
    
    UFUNCTION()
    virtual void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) PURE_VIRTUAL(SaveData,);
    
    UFUNCTION()
    virtual void RestoreData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) PURE_VIRTUAL(RestoreData,);
    
    UFUNCTION()
    virtual bool RegisterNewSpawn(AActor* InAssetPtr) PURE_VIRTUAL(RegisterNewSpawn, return false;);
    
    UFUNCTION()
    virtual FString RedirectObjectToInstance(const FString& InRegistryID) PURE_VIRTUAL(RedirectObjectToInstance, return TEXT(""););
    
    UFUNCTION()
    virtual FName RedirectObjectClass(FName InRegistryID, const FString& inTableName) PURE_VIRTUAL(RedirectObjectClass, return NAME_None;);
    
    UFUNCTION()
    virtual bool RedirectNamedObject(FName InRegistryID, const FString& inTableName, FString& outClassID, FString& outLootID) PURE_VIRTUAL(RedirectNamedObject, return false;);
    
    UFUNCTION()
    virtual FName RedirectInstanceToObject(FName InRegistryID) PURE_VIRTUAL(RedirectInstanceToObject, return NAME_None;);
    
    UFUNCTION()
    virtual bool IsObjectInDefinitionTable(FName InRegistryID) PURE_VIRTUAL(IsObjectInDefinitionTable, return false;);
    
    UFUNCTION()
    virtual uint32 GetUniqueObjectID(const FString& InItemID) PURE_VIRTUAL(GetUniqueObjectID, return 0;);
    
    UFUNCTION()
    virtual FName GetTableName() PURE_VIRTUAL(GetTableName, return NAME_None;);
    
    UFUNCTION()
    virtual bool GetSpawnRestrictionsByCategory(const FString& InItemID, const FString& inCategory, FSQLiteQueryResultMap& OutQueryResultMap) PURE_VIRTUAL(GetSpawnRestrictionsByCategory, return false;);
    
    UFUNCTION()
    virtual bool GetSpawnRestrictions(const FString& InItemID, FSQLiteQueryResultMap& OutQueryResultMap) PURE_VIRTUAL(GetSpawnRestrictions, return false;);
    
    UFUNCTION()
    virtual bool GetSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) PURE_VIRTUAL(GetSpawnPath, return false;);
    
    UFUNCTION()
    virtual bool GetSpawnAsset(const FString& InItemID, TSubclassOf<AActor>& OutAsset) PURE_VIRTUAL(GetSpawnAsset, return false;);
    
    UFUNCTION()
    virtual bool GetShellSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) PURE_VIRTUAL(GetShellSpawnPath, return false;);
    
    UFUNCTION()
    virtual int32 GetPlayerExperienceLevel() PURE_VIRTUAL(GetPlayerExperienceLevel, return 0;);
    
    UFUNCTION()
    virtual bool GetObjectInstanceData(FName InRegistryID, TArray<FNPC_DbObjectInstanceData>& outInstanceData) PURE_VIRTUAL(GetObjectInstanceData, return false;);
    
    UFUNCTION()
    virtual float GetHealth(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID) PURE_VIRTUAL(GetHealth, return 0.0f;);
    
    UFUNCTION()
    virtual FName GetDynamicTableName() PURE_VIRTUAL(GetDynamicTableName, return NAME_None;);
    
    UFUNCTION()
    virtual FName GetDynamicPersistenceTableName() PURE_VIRTUAL(GetDynamicPersistenceTableName, return NAME_None;);
    
protected:
    UFUNCTION()
    virtual bool GetDefinitionIdentifyingColumnName(FName& OutFirstColumnName) PURE_VIRTUAL(GetDefinitionIdentifyingColumnName, return false;);
    
public:
    UFUNCTION()
    virtual FName GetCharacterDerivedClass(FName InRegistryID) PURE_VIRTUAL(GetCharacterDerivedClass, return NAME_None;);
    
    UFUNCTION()
    virtual bool GetActorDefinitionData(const FString& InRegistryID, FName& outGenderID, FName& OutVoiceID, FName& outEmoteID) PURE_VIRTUAL(GetActorDefinitionData, return false;);
    
    UFUNCTION()
    virtual bool CreateItemAsScheduledEntity(const FString& InItemID) PURE_VIRTUAL(CreateItemAsScheduledEntity, return false;);
    
    UFUNCTION()
    virtual ESpawnRestrictionResponse CheckSpawnRestrictions(FRestrictionInfo& ioRestrictionInfo) PURE_VIRTUAL(CheckSpawnRestrictions, return ESpawnRestrictionResponse::SRR_NO_RESTRICTIONS;);
    
    UFUNCTION()
    virtual ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) PURE_VIRTUAL(AllowSpawn, return ESpawnAllowedResponse::SAR_ALLOWSPAWN;);
    
};

