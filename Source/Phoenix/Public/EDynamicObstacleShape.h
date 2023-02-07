#pragma once
#include "CoreMinimal.h"
#include "EDynamicObstacleShape.generated.h"

UENUM(BlueprintType)
enum class EDynamicObstacleShape : uint8 {
    SHAPE_NONE,
    SHAPE_BOX,
    SHAPE_CAPSULE,
    SHAPE_SPHERE,
    SHAPE_MAX UMETA(Hidden),
};

