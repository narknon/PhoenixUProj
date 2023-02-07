#pragma once
#include "CoreMinimal.h"
#include "ENPC_GameContext.generated.h"

UENUM(BlueprintType)
enum class ENPC_GameContext : uint8 {
    None,
    Swim,
    OnSlope,
    OnStairs,
    Crouching,
    Flying,
    Stealth,
    CCState,
    KnockedDown,
    Levitated,
    ENPC_MAX UMETA(Hidden),
};

