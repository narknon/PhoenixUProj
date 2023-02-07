#pragma once
#include "CoreMinimal.h"
#include "ENPC_FollowSplineScurryState.generated.h"

UENUM(BlueprintType)
enum class ENPC_FollowSplineScurryState : uint8 {
    Interval,
    Proximity,
    ENPC_MAX UMETA(Hidden),
};

