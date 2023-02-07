#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonSetupTimers.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonSetupTimers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollisionDelay;
    
    PHOENIX_API FExplodingSkeletonSetupTimers();
};

