#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LODActorRotationManager.generated.h"

UCLASS(Blueprintable)
class ALODActorRotationManager : public AActor {
    GENERATED_BODY()
public:
    ALODActorRotationManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> FilterValidActorRef(TArray<TSoftObjectPtr<AActor>> ActorRefList);
    
    UFUNCTION(BlueprintCallable)
    void CheckLOD0ActorRefValid(TSoftObjectPtr<AActor> ActorRef, bool& bTrue);
    
    UFUNCTION(BlueprintCallable)
    void CheckAnyActorRefValid(TArray<TSoftObjectPtr<AActor>> ActorRefList, bool& bTrue);
    
};

