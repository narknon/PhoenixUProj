#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingCurlNoiseMode.h"
#include "GroundSwarmingCurlNoiseParameters.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingCurlNoiseParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGroundSwarmingCurlNoiseMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SampleRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Force;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceVariancePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Epsilon;
    
    PHOENIX_API FGroundSwarmingCurlNoiseParameters();
};

