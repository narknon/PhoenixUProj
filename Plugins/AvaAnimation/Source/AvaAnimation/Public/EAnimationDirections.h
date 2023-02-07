#pragma once
#include "CoreMinimal.h"
#include "EAnimationDirections.generated.h"

UENUM(BlueprintType)
enum class EAnimationDirections : uint8 {
    MovingDirection,
    FacingDirection,
    AimingDirection,
    LookingDirection,
    GazingDirection,
    kDirectionCount,
};

