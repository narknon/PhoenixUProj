#pragma once
#include "CoreMinimal.h"
#include "TickSequencerGroupBucket.h"
#include "TickSequencerUpdateBucketList.generated.h"

USTRUCT(BlueprintType)
struct FTickSequencerUpdateBucketList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTickSequencerGroupBucket> Buckets;
    
    TICKSEQUENCER_API FTickSequencerUpdateBucketList();
};

