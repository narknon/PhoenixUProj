#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GroundSwarmSimulationFollowInfo.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmSimulationFollowInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceFactor;
    
    PHOENIX_API FGroundSwarmSimulationFollowInfo();
};

