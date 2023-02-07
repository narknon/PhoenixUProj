#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "StreamingPlaceholderLockState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FStreamingPlaceholderLockState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo Lock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> Actor;
    
    PHOENIX_API FStreamingPlaceholderLockState();
};

