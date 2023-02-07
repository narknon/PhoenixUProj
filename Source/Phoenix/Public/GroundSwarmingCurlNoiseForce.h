#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GroundSwarmingCurlNoiseForce.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingCurlNoiseForce {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Force;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timeout;
    
    PHOENIX_API FGroundSwarmingCurlNoiseForce();
};

