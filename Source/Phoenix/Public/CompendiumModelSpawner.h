#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CompendiumModelSpawner.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ACompendiumModelSpawner : public AActor {
    GENERATED_BODY()
public:
    ACompendiumModelSpawner();
protected:
    UFUNCTION(BlueprintCallable)
    void UnloadModelClass();
    
    UFUNCTION(BlueprintCallable)
    void ForceMountAssetsToBeResident(USkeletalMeshComponent* MountSK);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnModelClassLoaded(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_LODsLoaded();
    
    UFUNCTION(BlueprintCallable)
    void AsyncLoadModelClassFromDbId(const FString& InItemName);
    
};

