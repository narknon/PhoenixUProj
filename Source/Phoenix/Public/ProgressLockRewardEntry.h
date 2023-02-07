#pragma once
#include "CoreMinimal.h"
#include "EProgressLockRewardType.h"
#include "ProgressLockRewardEntry.generated.h"

USTRUCT(BlueprintType)
struct FProgressLockRewardEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProgressLockRewardType RewardType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RewardName;
    
    PHOENIX_API FProgressLockRewardEntry();
};

