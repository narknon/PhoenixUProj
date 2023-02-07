#pragma once
#include "CoreMinimal.h"
#include "ENPC_NavAttackReachableState.generated.h"

UENUM(BlueprintType)
enum class ENPC_NavAttackReachableState : uint8 {
    NotNeeded,
    Unreachable,
    Reachable,
    StraightLineReachable,
    ENPC_MAX UMETA(Hidden),
};

