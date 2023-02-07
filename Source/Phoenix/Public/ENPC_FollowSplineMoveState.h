#pragma once
#include "CoreMinimal.h"
#include "ENPC_FollowSplineMoveState.generated.h"

UENUM(BlueprintType)
enum class ENPC_FollowSplineMoveState : uint8 {
    Normal,
    Scurry,
    Volume,
    ENPC_MAX UMETA(Hidden),
};

