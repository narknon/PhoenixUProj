#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhxDbRegistryTypeManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class UPhxDbRegistryTypeManager : public UObject {
    GENERATED_BODY()
public:
    UPhxDbRegistryTypeManager();
    UFUNCTION(BlueprintCallable)
    bool UnregisterSpawnWhenDestroyed(AActor* InAssetPtr);
    
    UFUNCTION(BlueprintCallable)
    bool RegisterNewSpawn(AActor* InAssetPtr);
    
};

