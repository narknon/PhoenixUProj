#pragma once
#include "CoreMinimal.h"
#include "ENPC_FollowSplineEndAction.generated.h"

UENUM(BlueprintType)
enum class ENPC_FollowSplineEndAction : uint8 {
    None,
    Loop,
    Bounce,
    Done,
    Die,
    DoneNoReact,
    Deactivate,
    ENPC_MAX UMETA(Hidden),
};

