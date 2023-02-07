#pragma once
#include "CoreMinimal.h"
#include "EMovementSensorType.generated.h"

UENUM(BlueprintType)
enum class EMovementSensorType : uint8 {
    BlockingCollision,
    JumpOn,
    JumpDown,
    JumpOver,
    Landing,
    GroundHit,
    None,
};

