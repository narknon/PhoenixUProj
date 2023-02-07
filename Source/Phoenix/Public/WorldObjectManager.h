#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESpawnAllowedResponse.h"
#include "Engine/EngineTypes.h"
#include "PhxDbRegistryTypeManager.h"
#include "WorldObjectManager.generated.h"

class AActor;
class ULevel;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class UWorldObjectManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
    UWorldObjectManager();
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION()
    void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    UFUNCTION()
    ESpawnAllowedResponse AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent);
    
};

