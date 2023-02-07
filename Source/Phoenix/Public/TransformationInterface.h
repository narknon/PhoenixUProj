#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TransformationInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UTransformationInterface : public UInterface {
    GENERATED_BODY()
};

class ITransformationInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformStart(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformSpawnSpawned(AActor* Instigator, AActor* OriginalActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformSpawn(AActor* Instigator, AActor* TransformedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformCompleteSpawned(AActor* Instigator, AActor* OriginalActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformComplete(AActor* Instigator, AActor* TransformedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRestoreStartSpawned(AActor* Instigator, AActor* OriginalActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRestoreStart(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRestoreComplete(AActor* Instigator);
    
};

