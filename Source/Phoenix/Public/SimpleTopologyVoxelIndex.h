#pragma once
#include "CoreMinimal.h"
#include "SimpleTopologyVoxelIndex.generated.h"

USTRUCT(BlueprintType)
struct FSimpleTopologyVoxelIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Y;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Z;
    
    PHOENIX_API FSimpleTopologyVoxelIndex();
};

