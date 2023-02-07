#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "DynamicObstacleManager.generated.h"

class AActor;
class UDynamicObstacleManager;
class UWorld;

UCLASS(Blueprintable)
class UDynamicObstacleManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> World;
    
public:
    UDynamicObstacleManager();
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UDynamicObstacleManager* GetDynamicObstacleManager(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static UDynamicObstacleManager* Get(UWorld* NewWorld);
    
};

