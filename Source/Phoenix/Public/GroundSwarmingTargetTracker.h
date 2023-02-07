#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingTargetTracker.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FGroundSwarmingTargetTracker {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Hits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThresholdMetDelayTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSignalledThresholdResult;
    
public:
    PHOENIX_API FGroundSwarmingTargetTracker();
};

