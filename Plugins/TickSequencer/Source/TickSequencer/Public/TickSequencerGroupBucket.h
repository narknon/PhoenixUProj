#pragma once
#include "CoreMinimal.h"
#include "TickSequencerBucketDelegate.h"
#include "TickSequencerGroupBucket.generated.h"

USTRUCT(BlueprintType)
struct FTickSequencerGroupBucket {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bucket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTickSequencerBucketDelegate> Delegates;
    
    TICKSEQUENCER_API FTickSequencerGroupBucket();
};

