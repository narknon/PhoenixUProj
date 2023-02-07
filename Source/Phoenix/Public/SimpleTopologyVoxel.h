#pragma once
#include "CoreMinimal.h"
#include "ESimpleTopologyType.h"
#include "SimpleTopologyPointNormal.h"
#include "SimpleTopologyVoxel.generated.h"

USTRUCT(BlueprintType)
struct FSimpleTopologyVoxel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleTopologyPointNormal Plane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESimpleTopologyType Type;
    
    PHOENIX_API FSimpleTopologyVoxel();
};

