#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonInitialDelay.generated.h"

USTRUCT(BlueprintType)
struct FExplodingSkeletonInitialDelay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseInitialDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDelayAtMinHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDelayAtMaxHeight;
    
    PHOENIX_API FExplodingSkeletonInitialDelay();
};

