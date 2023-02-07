#pragma once
#include "CoreMinimal.h"
#include "TickSequencerBucketDelegateOptions.h"
#include "TickSequencerBucketDelegate.generated.h"

USTRUCT(BlueprintType)
struct FTickSequencerBucketDelegate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTickSequencerBucketDelegateOptions OPTIONS;
    
    TICKSEQUENCER_API FTickSequencerBucketDelegate();
};

