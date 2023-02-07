#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreamingPlaceholderBase.generated.h"

UCLASS(Abstract, Blueprintable)
class AStreamingPlaceholderBase : public AActor {
    GENERATED_BODY()
public:
    AStreamingPlaceholderBase();
    UFUNCTION(BlueprintCallable)
    void WaitUntilLoadIsComplete();
    
    UFUNCTION(BlueprintCallable)
    void TriggerLoad(const bool bInSpawnWhenReady, const bool bForceBlockingLoad);
    
    UFUNCTION(BlueprintCallable)
    void SpawnObject(const bool bBlockingLoadIfNotLoaded);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseObject();
    
};

