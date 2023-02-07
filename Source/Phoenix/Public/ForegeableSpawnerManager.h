#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ForegeableSpawnerManager.generated.h"

class AActor;
class AForagable;
class UForageablePool;
class UForegeableSpawnerManager;

UCLASS(Blueprintable, NotPlaceable)
class UForegeableSpawnerManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForageablePool* Pool;
    
    UForegeableSpawnerManager();
    UFUNCTION(BlueprintCallable)
    void UnregisterInstance(AActor* Instance);
    
    UFUNCTION(BlueprintCallable)
    void RegisterInstance(AActor* Instance, bool bShouldSetInitialState);
    
    UFUNCTION(BlueprintCallable)
    void OnForageableCollected(AForagable* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnBreakableDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool InDungeon();
    
    UFUNCTION(BlueprintCallable)
    static UForegeableSpawnerManager* Get();
    
};

