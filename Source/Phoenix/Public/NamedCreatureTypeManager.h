#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "PhxDbRegistryTypeManager.h"
#include "Templates/SubclassOf.h"
#include "NamedCreatureTypeManager.generated.h"

class AActor;
class UCreatureState;
class ULevel;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class UNamedCreatureTypeManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UCreatureState*> NamedCreatureStates;
    
public:
    UNamedCreatureTypeManager();
    UFUNCTION()
    AActor* SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel);
    
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION(BlueprintCallable)
    bool GetSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath);
    
    UFUNCTION(BlueprintCallable)
    bool GetSpawnAsset(const FString& InItemID, TSubclassOf<AActor>& OutAsset);
    
    UFUNCTION(BlueprintCallable)
    bool GetShellSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath);
    
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
};

