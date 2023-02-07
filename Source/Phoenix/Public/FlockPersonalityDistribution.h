#pragma once
#include "CoreMinimal.h"
#include "FlockPersonalityDistribution.generated.h"

USTRUCT(BlueprintType)
struct FFlockPersonalityDistribution {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Percentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowStacking;
    
    PHOENIX_API FFlockPersonalityDistribution();
};

