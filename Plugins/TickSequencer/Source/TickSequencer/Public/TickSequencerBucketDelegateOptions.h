#pragma once
#include "CoreMinimal.h"
#include "TickSequencerBucketDelegateOptions.generated.h"

USTRUCT(BlueprintType)
struct TICKSEQUENCER_API FTickSequencerBucketDelegateOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTickWhenPaused: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSuspend: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTickInEditor: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTickOnlyInEditor: 1;
    
    FTickSequencerBucketDelegateOptions();
};

