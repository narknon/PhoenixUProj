#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingExternalForce.h"
#include "GroundSwarmingExternalForces.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingExternalForces {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGroundSwarmingExternalForce> ExternalForces;
    
    PHOENIX_API FGroundSwarmingExternalForces();
};

