#pragma once
#include "CoreMinimal.h"
#include "EInteractOffsetRules.generated.h"

UENUM(BlueprintType)
enum class EInteractOffsetRules : uint8 {
    None,
    PlayerToTarget,
    TargetToPlayer,
    TargetAxis,
    TargetPlane,
};

