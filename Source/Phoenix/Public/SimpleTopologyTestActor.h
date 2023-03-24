#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleTopologyParams.h"
#include "SimpleTopologyVoxelArray.h"
#include "SimpleTopologyTestActor.generated.h"

UCLASS(Blueprintable)
class ASimpleTopologyTestActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyParams Topology;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyVoxelArray VoxelArray;
    
    ASimpleTopologyTestActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Precompute();
    
    UFUNCTION(BlueprintCallable)
    void AbortPrecompute();
    
};

