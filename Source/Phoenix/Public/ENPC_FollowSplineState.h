#pragma once
#include "CoreMinimal.h"
#include "ENPC_FollowSplineState.generated.h"

UENUM(BlueprintType)
enum class ENPC_FollowSplineState : uint8 {
    None,
    Inactive,
    Spline,
    Idle,
    Volume,
    ENPC_MAX UMETA(Hidden),
};

