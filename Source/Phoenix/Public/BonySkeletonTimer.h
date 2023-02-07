#pragma once
#include "CoreMinimal.h"
#include "BonySkeletonTimer.generated.h"

USTRUCT(BlueprintType)
struct FBonySkeletonTimer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTripped;
    
    PHOENIX_API FBonySkeletonTimer();
};

