#pragma once
#include "CoreMinimal.h"
#include "EProgressLockRewardType.generated.h"

UENUM(BlueprintType)
enum class EProgressLockRewardType : uint8 {
    PROGRESS_LOCK_REWARD_TYPE_UNKNOWN,
    PROGRESS_LOCK_REWARD_TYPE_SPELL,
    PROGRESS_LOCK_REWARD_TYPE_MAX UMETA(Hidden),
};

