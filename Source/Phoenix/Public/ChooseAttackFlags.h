#pragma once
#include "CoreMinimal.h"
#include "ChooseAttackFlags.generated.h"

UENUM(BlueprintType)
enum class ChooseAttackFlags : uint8 {
    UseFallbackRange,
    IgnoreSelectCooldown,
    ResetFailed,
    IgnoreSelectRanges,
    IgnoreOptRanges,
    IgnoreMinAttackAngle,
    TargetOffNav,
    HighTier,
    MedTier,
    LowTier,
    AnyTier,
    IgnoreSelectWeights,
    Count,
};

