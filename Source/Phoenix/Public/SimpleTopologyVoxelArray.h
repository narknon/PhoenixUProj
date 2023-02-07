#pragma once
#include "CoreMinimal.h"
#include "SimpleTopologyParams.h"
#include "SimpleTopologyVoxelIndex.h"
#include "SimpleTopologyVoxelArray.generated.h"

USTRUCT(BlueprintType)
struct FSimpleTopologyVoxelArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyParams Topology;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InvVoxelSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyVoxelIndex MinVoxelIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyVoxelIndex MaxVoxelIndex;
    
    PHOENIX_API FSimpleTopologyVoxelArray();
};

