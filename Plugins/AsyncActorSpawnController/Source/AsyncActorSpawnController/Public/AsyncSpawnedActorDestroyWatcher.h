#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AsyncSpawnedActorDestroyWatcher.generated.h"

class AActor;

UCLASS(Blueprintable)
class UAsyncSpawnedActorDestroyWatcher : public UObject {
    GENERATED_BODY()
public:
    UAsyncSpawnedActorDestroyWatcher();
    UFUNCTION(BlueprintCallable)
    void OnActorDestroy(AActor* DestroyedActor);
    
};

