#pragma once
#include "CoreMinimal.h"
#include "FlockPersonalityDistribution.h"
#include "FlockPersonalityLagger.generated.h"

USTRUCT(BlueprintType)
struct FFlockPersonalityLagger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFlockPersonalityDistribution Distribution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFactor;
    
    PHOENIX_API FFlockPersonalityLagger();
};

