#pragma once
#include "CoreMinimal.h"
#include "ENPC_FollowSplineDirection.generated.h"

UENUM(BlueprintType)
enum class ENPC_FollowSplineDirection : uint8 {
    Forward,
    Reverse,
    ENPC_MAX UMETA(Hidden),
};

