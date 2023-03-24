#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "FlyingStairStatus.h"
#include "StairStatusChangedDelegateDelegate.h"
#include "FlyingStairsChain.generated.h"

class UCapsuleComponent;
class UFlyingStairComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AFlyingStairsChain : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairBuilding;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairDemolishing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* FlyingStairsChainArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenAutomaticSequentialBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpeedOfStairsFromCloud;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBuildWholeChainWhenCharacterEntersRange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlyingStairStatus> FlyingStairs;
    
public:
    AFlyingStairsChain(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnFlyingStairComponentDemolish(UFlyingStairComponent* FlyingStairComponent, float animationLength, float animationStartPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnFlyingStairComponentBuild(UFlyingStairComponent* FlyingStairComponent, float animationLength, float animationStartPosition);
    
    UFUNCTION(BlueprintCallable)
    void DemolishNext();
    
    UFUNCTION(BlueprintCallable)
    void BuildNext();
    
};

