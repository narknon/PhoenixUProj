#pragma once
#include "CoreMinimal.h"
#include "EAvaMotionWarpingModifierState.generated.h"

UENUM(BlueprintType)
enum class EAvaMotionWarpingModifierState : uint8 {
    Waiting,
    Active,
    MarkedForRemoval,
    Disabled,
};

