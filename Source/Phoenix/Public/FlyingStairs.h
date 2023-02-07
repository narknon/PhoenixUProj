#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StairStatusChangedDelegateDelegate.h"
#include "FlyingStairs.generated.h"

class AFlyingStairsChain;
class UCapsuleComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class AFlyingStairs : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* FlyingStairsArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* CloudMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeForStairsToStayAtHeightDuringMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AFlyingStairsChain*> FlyingStairsChain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeForRandomlyBuildingStair;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairBuilding;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairDemolishing;
    
public:
    AFlyingStairs();
private:
    UFUNCTION(BlueprintCallable)
    void DestroyRandomStairChain();
    
    UFUNCTION(BlueprintCallable)
    void BuildRandomStairChain();
    
};

