#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GroundSwarmingVelocityTracker.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingVelocityTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLastPositionValid;
    
    PHOENIX_API FGroundSwarmingVelocityTracker();
};

