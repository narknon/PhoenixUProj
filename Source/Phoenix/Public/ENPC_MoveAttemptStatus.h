#pragma once
#include "CoreMinimal.h"
#include "ENPC_MoveAttemptStatus.generated.h"

UENUM(BlueprintType)
enum class ENPC_MoveAttemptStatus : uint8 {
    None,
    Success,
    NoNavData,
    NoSafeNavPoint,
    StartBlocked,
    UpdateBlocked,
    AbruptHeadingChange,
    HeadingOffscreen,
    WillEnterCorridor,
    PassTooCloseToTarget,
    NoPath,
    ConstrainLocFailed,
    NoGroundFound,
    ENPC_MAX UMETA(Hidden),
};

